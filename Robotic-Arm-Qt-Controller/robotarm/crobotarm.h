#ifndef CROBOTARM_H
#define CROBOTARM_H

#include <QObject>

#include "robotarmstate.h"

class CRobotArm : public QObject
{
    Q_OBJECT

public:
    ~CRobotArm();

    static CRobotArm* instance();

    bool initialize();
    bool deinitialize();
    bool setRobotArmSate(RobotArmState robotArmSate);
    RobotArmState getRobotArmCurrentSate();

signals:

public slots:

public:
    static const RobotArmState RobotArmResetState;

protected:
    RobotArmState m_CurrentRobotArmState;

private:
    CRobotArm(QObject *parent = 0);

private:
    static CRobotArm *mp_SingleInstance;
};

#endif // CROBOTARM_H
