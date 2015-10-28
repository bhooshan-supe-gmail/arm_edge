#ifndef CROBOTARM_H
#define CROBOTARM_H

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
};

#endif // CROBOTARM_H
