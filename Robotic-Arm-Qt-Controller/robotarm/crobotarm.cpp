#include <QDebug>
#include <QApplication>

#include "crobotarm.h"

const RobotArmState CRobotArm::RobotArmResetState;
CRobotArm *CRobotArm::mp_SingleInstance = NULL;


CRobotArm::CRobotArm(QObject *parent) :
    QObject(parent)
{
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__;
    qDebug() << ":sizeof(CRobotArm::RobotArmResetState)=" << sizeof(CRobotArm::RobotArmResetState);

    bool bIsArmInited = initialize();
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":bIsArmInited=" << bIsArmInited;
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

bool CRobotArm::setRobotArmSate(RobotArmState robotArmSate)
{
    bool return_value = true;
    if (return_value) {
        m_CurrentRobotArmState = robotArmSate;
        qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__;
        qDebug() << ":m_CurrentRobotArmState.m_MotorStates=" << m_CurrentRobotArmState.m_MotorStates.m_MotorM1M2M3M4_uin8;
        qDebug() << ":m_CurrentRobotArmState.m_BaseMotorState=" << m_CurrentRobotArmState.m_BaseMotorState.m_BaseMotor_uin8;
        qDebug() << ":m_CurrentRobotArmState.m_SearchLEDState=" << m_CurrentRobotArmState.m_SearchLEDState.m_SearchLED_uin8;
    }
    return return_value;
}

RobotArmState CRobotArm::getRobotArmCurrentSate()
{
    return m_CurrentRobotArmState;
}
