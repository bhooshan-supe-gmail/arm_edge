#ifndef CROBOTARM_H
#define CROBOTARM_H
#include <libusb-1.0/libusb.h>

#include <QObject>

#include "robotarmstate.h"
#include "ArmEdgeInterProcessSignalPropagator.h"

class CRobotArm : public QObject
{
	Q_OBJECT

public:
	~CRobotArm();

	static CRobotArm* instance();

	bool initialize();
	bool deinitialize();
	RobotArmState getRobotArmCurrentSate();

signals:
	void requestRobotArmStateChange(quint8 motorStates, quint8 baseMotorState, quint8 searchLEDState);
	void responseRobotArmStateChanged(quint8 motorStates, quint8 baseMotorState, quint8 searchLEDState);

public slots:
	bool onRequestRobotArmStateChange(quint8 motorStates, quint8 baseMotorState, quint8 searchLEDState);
	bool onResponseRobotArmStateChanged(quint8 motorStates, quint8 baseMotorState, quint8 searchLEDState);

public:
	static const RobotArmState RobotArmResetState;

protected:
	RobotArmState m_CurrentRobotArmState;

private:
	CRobotArm(QObject *parent = 0);

private:
	CArmEdgeInterProcessSignalPropagator *m_pArmEdgeInterProcessSignalPropagator;

	static CRobotArm *mp_SingleInstance;
	static struct libusb_device_handle *devh;
	static libusb_device **devs;
};

#endif // CROBOTARM_H
