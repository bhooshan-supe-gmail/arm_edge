#include "robotarmstate.h"

RobotArmState::RobotArmState()
{
    m_MotorStates.m_MotorM1M2M3M4_uin8 = 0x00;
    m_BaseMotorState.m_BaseMotor_uin8 = 0x00;
    m_SearchLEDState.m_SearchLED_uin8 = 0x00;
}
