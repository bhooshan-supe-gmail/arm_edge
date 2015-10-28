#ifndef ROBOTARMSTAE_H
#define ROBOTARMSTAE_H

#include <qglobal.h>
#include <QMetaType>

struct RobotArmState
{
public :
    union MotorStates
    {
        struct MotorM1M2M3M4
        {
            quint8 m_MotorM1CL  :1;
            quint8 m_MotorM1OP  :1;
            quint8 m_MotorM2UP  :1;
            quint8 m_MotorM2DN  :1;
            quint8 m_MotorM3UP  :1;
            quint8 m_MotorM3DN  :1;
            quint8 m_MotorM4UP  :1;
            quint8 m_MotorM4DN  :1;
        } m_MotorM1M2M3M4;
        quint8 m_MotorM1M2M3M4_uin8;
    };

    union BaseMotorState
    {
        struct BaseMotor
        {
            quint8 m_BaseMotorCW  :1;
            quint8 m_BaseMotorCCW :1;
        } m_BaseMotor;
        quint8 m_BaseMotor_uin8;
    };

    union SearchLEDState
    {
        struct SearchLED
        {
            quint8 m_SearchLED  :1;
        } m_SearchLED;
        quint8 m_SearchLED_uin8;
    };

public :
    MotorStates m_MotorStates;
    BaseMotorState m_BaseMotorState;
    SearchLEDState m_SearchLEDState;

public :
    RobotArmState();
};

Q_DECLARE_METATYPE(RobotArmState);

#endif // ROBOTARMSTAE_H
