#include <QDebug>
#include <QApplication>

#define EP_INTR	(1 | LIBUSB_ENDPOINT_IN)

#define ARM_VENDOR       0x1267
#define ARM_PRODUCT      0
#define CMD_DATALEN      3

#include "crobotarm.h"

const RobotArmState CRobotArm::RobotArmResetState;
CRobotArm *CRobotArm::mp_SingleInstance = NULL;
struct libusb_device_handle *CRobotArm::devh = NULL;
libusb_device **CRobotArm::devs = NULL;

/////////////////////////CODE from "http://notbrainsurgery.livejournal.com/38622.html"
libusb_device * find_arm(libusb_device **devs)
{
    libusb_device *dev;
    int i = 0;

    while ((dev = devs[i++]) != NULL) {
        struct libusb_device_descriptor desc;
        int r = libusb_get_device_descriptor(dev, &desc);
        if (r < 0) {
            fprintf(stderr, "failed to get device descriptor");
            return NULL;
        }
        if(desc.idVendor == ARM_VENDOR &&
           desc.idProduct == ARM_PRODUCT)
          {
            return dev;
          }
    }
    return NULL;
}
/////////////////////////CODE from "http://notbrainsurgery.livejournal.com/38622.html"


CRobotArm::CRobotArm(QObject *parent) :
	QObject(parent),
	m_pArmEdgeInterProcessSignalPropagator(NULL)
{
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__;
    qDebug() << ":sizeof(CRobotArm::RobotArmResetState)=" << sizeof(CRobotArm::RobotArmResetState);

    bool bIsArmInited = initialize();
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":bIsArmInited=" << bIsArmInited;

	bool isConnected = false;
	qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":isConnected=" << isConnected;

	m_pArmEdgeInterProcessSignalPropagator = CArmEdgeInterProcessSignalPropagator::instance(QInterProcessSignalPropogator::InterProcessSignalPropogatorServer);
	qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":m_pArmEdgeInterProcessSignalPropagator=" << m_pArmEdgeInterProcessSignalPropagator;

	if(m_pArmEdgeInterProcessSignalPropagator != NULL)
	{
		isConnected = connect(m_pArmEdgeInterProcessSignalPropagator, SIGNAL(requestRobotArmStateChange(quint8, quint8, quint8)), this, SLOT(onRequestRobotArmStateChange(quint8, quint8, quint8)), Qt::QueuedConnection);
		qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":isConnected=" << isConnected;

		isConnected = connect(this, SIGNAL(responseRobotArmStateChanged(quint8, quint8, quint8)), m_pArmEdgeInterProcessSignalPropagator, SIGNAL(responseRobotArmStateChanged(quint8, quint8, quint8)), Qt::QueuedConnection);
		qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":isConnected=" << isConnected;
	}
}

CRobotArm::~CRobotArm()
{
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__;
    bool bIsArmDeInited = deinitialize();
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":bIsArmDeInited=" << bIsArmDeInited;
}

CRobotArm* CRobotArm::instance()
{
    if (mp_SingleInstance == NULL) {
        mp_SingleInstance = new CRobotArm(QApplication::instance());
    }
    return mp_SingleInstance;
}

bool CRobotArm::initialize()
{
    bool return_value = true;
    libusb_device *dev;
    int r;
    ssize_t cnt;

    if (devh == NULL && devs == NULL) {
        r = libusb_init(NULL);
        if (r < 0) {
            fprintf(stderr, "failed to initialize libusb\n");
            return_value = false;
        }

        if (return_value) {
            libusb_set_debug(NULL,2);

            cnt = libusb_get_device_list(NULL, &devs);
            if (cnt < 0) {
                return_value = false;
            }

            if (return_value) {
                dev=find_arm(devs);
                if(!dev) {
                    fprintf(stderr, "Robot Arm not found\n");
                    return_value = false;
                }

                if (return_value) {
                    r = libusb_open(dev,&devh);
                    if(r!=0) {
                        fprintf(stderr, "Error opening device\n");
                        libusb_free_device_list(devs, 1);
                        libusb_exit(NULL);
                        return_value = false;
                    }
                }
            }
        }
    }

    return return_value;
}

bool CRobotArm::deinitialize()
{
    bool return_value = false;

    if (devh != NULL && devs != NULL) {
        libusb_close(devh);
        libusb_free_device_list(devs, 1);
        libusb_exit(NULL);
    }

    return return_value;
}

bool CRobotArm::onRequestRobotArmStateChange(quint8 motorStates, quint8 baseMotorState, quint8 searchLEDState)
{
    bool return_value = true;
	RobotArmState robotArmState;
	robotArmState.m_MotorStates.m_MotorM1M2M3M4_uin8 = motorStates;
	robotArmState.m_BaseMotorState.m_BaseMotor_uin8 = baseMotorState;
	robotArmState.m_SearchLEDState.m_SearchLED_uin8 = searchLEDState;

	qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__;
	qDebug() << ":robotArmState.m_MotorStates=" << robotArmState.m_MotorStates.m_MotorM1M2M3M4_uin8;
	qDebug() << ":robotArmState.m_BaseMotorState=" << robotArmState.m_BaseMotorState.m_BaseMotor_uin8;
	qDebug() << ":robotArmState.m_SearchLEDState=" << robotArmState.m_SearchLEDState.m_SearchLED_uin8;

    if (devh != NULL && devs != NULL) {
        int actual_length=-1;
        int r;
        unsigned char cmd[3];
        cmd[0]=(unsigned char)robotArmState.m_MotorStates.m_MotorM1M2M3M4_uin8;
        cmd[1]=(unsigned char)robotArmState.m_BaseMotorState.m_BaseMotor_uin8;
        cmd[2]=(unsigned char)robotArmState.m_SearchLEDState.m_SearchLED_uin8;

        r = libusb_control_transfer(devh,
                                    0x40, //uint8_t 	bmRequestType,
                                    6, //uint8_t 	bRequest,
                                    0x100, //uint16_t 	wValue,
                                    0,//uint16_t 	wIndex,
                                    cmd,
                                    CMD_DATALEN,
                                    0);

        if(!(r == 0 && actual_length >= CMD_DATALEN))
        {
            fprintf(stderr, "Write err %d. len=%d\n",r,actual_length);
        }

    }

    if (return_value) {
		m_CurrentRobotArmState = robotArmState;
		emit responseRobotArmStateChanged(m_CurrentRobotArmState.m_MotorStates.m_MotorM1M2M3M4_uin8, m_CurrentRobotArmState.m_BaseMotorState.m_BaseMotor_uin8, m_CurrentRobotArmState.m_SearchLEDState.m_SearchLED_uin8);
        qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__;
        qDebug() << ":m_CurrentRobotArmState.m_MotorStates=" << m_CurrentRobotArmState.m_MotorStates.m_MotorM1M2M3M4_uin8;
        qDebug() << ":m_CurrentRobotArmState.m_BaseMotorState=" << m_CurrentRobotArmState.m_BaseMotorState.m_BaseMotor_uin8;
        qDebug() << ":m_CurrentRobotArmState.m_SearchLEDState=" << m_CurrentRobotArmState.m_SearchLEDState.m_SearchLED_uin8;
    }
	return return_value;
}

bool CRobotArm::onResponseRobotArmStateChanged(quint8 motorStates, quint8 baseMotorState, quint8 searchLEDState)
{
	bool return_value = true;
	RobotArmState robotArmState;
	robotArmState.m_MotorStates.m_MotorM1M2M3M4_uin8 = motorStates;
	robotArmState.m_BaseMotorState.m_BaseMotor_uin8 = baseMotorState;
	robotArmState.m_SearchLEDState.m_SearchLED_uin8 = searchLEDState;

	qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__;
	qDebug() << ":robotArmState.m_MotorStates=" << robotArmState.m_MotorStates.m_MotorM1M2M3M4_uin8;
	qDebug() << ":robotArmState.m_BaseMotorState=" << robotArmState.m_BaseMotorState.m_BaseMotor_uin8;
	qDebug() << ":robotArmState.m_SearchLEDState=" << robotArmState.m_SearchLEDState.m_SearchLED_uin8;

	return return_value;
}

RobotArmState CRobotArm::getRobotArmCurrentSate()
{
    return m_CurrentRobotArmState;
}
