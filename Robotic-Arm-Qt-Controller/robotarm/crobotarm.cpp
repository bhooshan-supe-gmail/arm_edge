#include <QDebug>
#include <QApplication>

#include "crobotarm.h"

const RobotArmState CRobotArm::RobotArmResetState;
CRobotArm *CRobotArm::mp_SingleInstance = NULL;


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

	m_pArmEdgeInterProcessSignalPropagator = CArmEdgeInterProcessSignalPropagator::instance(QInterProcessSignalPropogator::InterProcessSignalPropogatorClient);
	qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":m_pArmEdgeInterProcessSignalPropagator=" << m_pArmEdgeInterProcessSignalPropagator;

	if(m_pArmEdgeInterProcessSignalPropagator != NULL)
	{
		isConnected = connect(m_pArmEdgeInterProcessSignalPropagator, SIGNAL(responseRobotArmStateChanged(quint8, quint8, quint8)), this, SLOT(onResponseRobotArmStateChanged(quint8, quint8, quint8)), Qt::QueuedConnection);
		qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":isConnected=" << isConnected;

		isConnected = connect(this, SIGNAL(requestRobotArmStateChange(quint8, quint8, quint8)), m_pArmEdgeInterProcessSignalPropagator, SIGNAL(requestRobotArmStateChange(quint8, quint8, quint8)), Qt::QueuedConnection);
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
    return return_value;
}

bool CRobotArm::deinitialize()
{
    bool return_value = false;
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

    if (return_value) {
		emit requestRobotArmStateChange(robotArmState.m_MotorStates.m_MotorM1M2M3M4_uin8, robotArmState.m_BaseMotorState.m_BaseMotor_uin8, robotArmState.m_SearchLEDState.m_SearchLED_uin8);
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

	qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__;
	qDebug() << ":m_CurrentRobotArmState.m_MotorStates=" << m_CurrentRobotArmState.m_MotorStates.m_MotorM1M2M3M4_uin8;
	qDebug() << ":m_CurrentRobotArmState.m_BaseMotorState=" << m_CurrentRobotArmState.m_BaseMotorState.m_BaseMotor_uin8;
	qDebug() << ":m_CurrentRobotArmState.m_SearchLEDState=" << m_CurrentRobotArmState.m_SearchLEDState.m_SearchLED_uin8;

	m_CurrentRobotArmState = robotArmState;

	qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__;
	qDebug() << ":m_CurrentRobotArmState.m_MotorStates=" << m_CurrentRobotArmState.m_MotorStates.m_MotorM1M2M3M4_uin8;
	qDebug() << ":m_CurrentRobotArmState.m_BaseMotorState=" << m_CurrentRobotArmState.m_BaseMotorState.m_BaseMotor_uin8;
	qDebug() << ":m_CurrentRobotArmState.m_SearchLEDState=" << m_CurrentRobotArmState.m_SearchLEDState.m_SearchLED_uin8;

	return return_value;
}

RobotArmState CRobotArm::getRobotArmCurrentSate()
{
    return m_CurrentRobotArmState;
}
