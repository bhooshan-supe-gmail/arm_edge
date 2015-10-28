#include <QDebug>
#include <QApplication>

#include "crobotarm.h"
#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    setupUi();
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__;

    bool isConnected = false;
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":isConnected=" << isConnected;

    isConnected = connect(m_M1OPLabel, SIGNAL(changeRobotArmStateTo(RobotArmState)), this, SLOT(onChangeRobotArmStateTo(RobotArmState)));
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":isConnected=" << isConnected;

    isConnected = connect(m_M1CLLabel, SIGNAL(changeRobotArmStateTo(RobotArmState)), this, SLOT(onChangeRobotArmStateTo(RobotArmState)));
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":isConnected=" << isConnected;

    isConnected = connect(m_M2UPLabel, SIGNAL(changeRobotArmStateTo(RobotArmState)), this, SLOT(onChangeRobotArmStateTo(RobotArmState)));
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":isConnected=" << isConnected;

    isConnected = connect(m_M2DNLabel, SIGNAL(changeRobotArmStateTo(RobotArmState)), this, SLOT(onChangeRobotArmStateTo(RobotArmState)));
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":isConnected=" << isConnected;

    isConnected = connect(m_M3UPLabel, SIGNAL(changeRobotArmStateTo(RobotArmState)), this, SLOT(onChangeRobotArmStateTo(RobotArmState)));
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":isConnected=" << isConnected;

    isConnected = connect(m_M3DNLabel, SIGNAL(changeRobotArmStateTo(RobotArmState)), this, SLOT(onChangeRobotArmStateTo(RobotArmState)));
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":isConnected=" << isConnected;

    isConnected = connect(m_M4UPLabel, SIGNAL(changeRobotArmStateTo(RobotArmState)), this, SLOT(onChangeRobotArmStateTo(RobotArmState)));
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":isConnected=" << isConnected;

    isConnected = connect(m_M4DNLabel, SIGNAL(changeRobotArmStateTo(RobotArmState)), this, SLOT(onChangeRobotArmStateTo(RobotArmState)));
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":isConnected=" << isConnected;

    isConnected = connect(m_MBCWLabel, SIGNAL(changeRobotArmStateTo(RobotArmState)), this, SLOT(onChangeRobotArmStateTo(RobotArmState)));
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":isConnected=" << isConnected;

    isConnected = connect(m_MBCCWLabel, SIGNAL(changeRobotArmStateTo(RobotArmState)), this, SLOT(onChangeRobotArmStateTo(RobotArmState)));
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":isConnected=" << isConnected;

    isConnected = connect(m_LIONLabel, SIGNAL(changeRobotArmStateTo(RobotArmState)), this, SLOT(onChangeRobotArmStateTo(RobotArmState)));
    qDebug() << "BAS_TBR:" << __PRETTY_FUNCTION__ << ":" << __LINE__ << ":isConnected=" << isConnected;
}

Widget::~Widget()
{
}

void Widget::setupUi()
{
    if (objectName().isEmpty())
        setObjectName(QStringLiteral("Widget"));
    resize(600, 400);
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(6);
    verticalLayout->setContentsMargins(11, 11, 11, 11);
    verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    m_MotorHorizontalLayout = new QHBoxLayout();
    m_MotorHorizontalLayout->setSpacing(6);
    m_MotorHorizontalLayout->setObjectName(QStringLiteral("m_MotorHorizontalLayout"));
    m_M1VerticalLayout = new QVBoxLayout();
    m_M1VerticalLayout->setSpacing(6);
    m_M1VerticalLayout->setObjectName(QStringLiteral("m_M1VerticalLayout"));

    RobotArmState lM1CLRobotArmState;
    lM1CLRobotArmState.m_MotorStates.m_MotorM1M2M3M4.m_MotorM1CL = 1;
    m_M1CLLabel = new CLabel(lM1CLRobotArmState, this);
    m_M1CLLabel->setObjectName(QStringLiteral("m_M1CLLabel"));

    m_M1VerticalLayout->addWidget(m_M1CLLabel);

    RobotArmState lM1OPRobotArmState;
    lM1OPRobotArmState.m_MotorStates.m_MotorM1M2M3M4.m_MotorM1OP = 1;
    m_M1OPLabel = new CLabel(lM1OPRobotArmState, this);
    m_M1OPLabel->setObjectName(QStringLiteral("m_M1OPLabel"));

    m_M1VerticalLayout->addWidget(m_M1OPLabel);

    m_MotorHorizontalLayout->addLayout(m_M1VerticalLayout);

    m_M2VerticalLayout = new QVBoxLayout();
    m_M2VerticalLayout->setSpacing(6);
    m_M2VerticalLayout->setObjectName(QStringLiteral("m_M2VerticalLayout"));

    RobotArmState lM2UPRobotArmState;
    lM2UPRobotArmState.m_MotorStates.m_MotorM1M2M3M4.m_MotorM2UP = 1;
    m_M2UPLabel = new CLabel(lM2UPRobotArmState, this);
    m_M2UPLabel->setObjectName(QStringLiteral("m_M2UPLabel"));

    m_M2VerticalLayout->addWidget(m_M2UPLabel);

    RobotArmState lM2DNRobotArmState;
    lM2DNRobotArmState.m_MotorStates.m_MotorM1M2M3M4.m_MotorM2DN = 1;
    m_M2DNLabel = new CLabel(lM2DNRobotArmState, this);
    m_M2DNLabel->setObjectName(QStringLiteral("m_M2DNLabel"));

    m_M2VerticalLayout->addWidget(m_M2DNLabel);

    m_MotorHorizontalLayout->addLayout(m_M2VerticalLayout);

    m_M3VerticalLayout = new QVBoxLayout();
    m_M3VerticalLayout->setSpacing(6);
    m_M3VerticalLayout->setObjectName(QStringLiteral("m_M3VerticalLayout"));

    RobotArmState lM3UPRobotArmState;
    lM3UPRobotArmState.m_MotorStates.m_MotorM1M2M3M4.m_MotorM3UP = 1;
    m_M3UPLabel = new CLabel(lM3UPRobotArmState, this);
    m_M3UPLabel->setObjectName(QStringLiteral("m_M3UPLabel"));

    m_M3VerticalLayout->addWidget(m_M3UPLabel);

    RobotArmState lM3DNRobotArmState;
    lM3DNRobotArmState.m_MotorStates.m_MotorM1M2M3M4.m_MotorM3DN = 1;
    m_M3DNLabel = new CLabel(lM3DNRobotArmState, this);
    m_M3DNLabel->setObjectName(QStringLiteral("m_M3DNLabel"));

    m_M3VerticalLayout->addWidget(m_M3DNLabel);

    m_MotorHorizontalLayout->addLayout(m_M3VerticalLayout);

    m_M4VerticalLayout = new QVBoxLayout();
    m_M4VerticalLayout->setSpacing(6);
    m_M4VerticalLayout->setObjectName(QStringLiteral("m_M4VerticalLayout"));

    RobotArmState lM4UPRobotArmState;
    lM4UPRobotArmState.m_MotorStates.m_MotorM1M2M3M4.m_MotorM4UP = 1;
    m_M4UPLabel = new CLabel(lM4UPRobotArmState, this);
    m_M4UPLabel->setObjectName(QStringLiteral("m_M4UPLabel"));

    m_M4VerticalLayout->addWidget(m_M4UPLabel);

    RobotArmState lM4DNRobotArmState;
    lM4DNRobotArmState.m_MotorStates.m_MotorM1M2M3M4.m_MotorM4DN = 1;
    m_M4DNLabel = new CLabel(lM4DNRobotArmState, this);
    m_M4DNLabel->setObjectName(QStringLiteral("m_M4DNLabel"));

    m_M4VerticalLayout->addWidget(m_M4DNLabel);

    m_MotorHorizontalLayout->addLayout(m_M4VerticalLayout);

    m_M5VerticalLayout = new QVBoxLayout();
    m_M5VerticalLayout->setSpacing(6);
    m_M5VerticalLayout->setObjectName(QStringLiteral("m_M5VerticalLayout"));

    RobotArmState lMBCWRobotArmState;
    lMBCWRobotArmState.m_BaseMotorState.m_BaseMotor.m_BaseMotorCW = 1;
    m_MBCWLabel = new CLabel(lMBCWRobotArmState, this);
    m_MBCWLabel->setObjectName(QStringLiteral("m_MBCWLabel"));

    m_M5VerticalLayout->addWidget(m_MBCWLabel);

    RobotArmState lMBCCWRobotArmState;
    lMBCCWRobotArmState.m_BaseMotorState.m_BaseMotor.m_BaseMotorCCW = 1;
    m_MBCCWLabel = new CLabel(lMBCCWRobotArmState, this);
    m_MBCCWLabel->setObjectName(QStringLiteral("m_MBCCWLabel"));

    m_M5VerticalLayout->addWidget(m_MBCCWLabel);

    m_MotorHorizontalLayout->addLayout(m_M5VerticalLayout);

    m_LIVerticalLayout = new QVBoxLayout();
    m_LIVerticalLayout->setSpacing(6);
    m_LIVerticalLayout->setObjectName(QStringLiteral("m_LIVerticalLayout"));

    RobotArmState lLIONRobotArmState;
    lLIONRobotArmState.m_SearchLEDState.m_SearchLED.m_SearchLED = 1;
    m_LIONLabel = new CLabel(lLIONRobotArmState, this);
    m_LIONLabel->setObjectName(QStringLiteral("m_LIONLabel"));

    m_LIVerticalLayout->addWidget(m_LIONLabel);

    m_MotorHorizontalLayout->addLayout(m_LIVerticalLayout);

    verticalLayout->addLayout(m_MotorHorizontalLayout);

    m_WarningLabel = new QLabel(this);
    m_WarningLabel->setObjectName(QStringLiteral("m_WarningLabel"));

    verticalLayout->addWidget(m_WarningLabel);

    m_ErrorLabel = new QLabel(this);
    m_ErrorLabel->setObjectName(QStringLiteral("m_ErrorLabel"));

    verticalLayout->addWidget(m_ErrorLabel);

    m_QuitPushButton = new QPushButton(this);
    m_QuitPushButton->setObjectName(QStringLiteral("m_QuitPushButton"));

    verticalLayout->addWidget(m_QuitPushButton);


    retranslateUi();
    QObject::connect(m_QuitPushButton, SIGNAL(clicked()), this, SLOT(close()));
} // setupUi

void Widget::retranslateUi()
{
    setWindowTitle(QApplication::translate("Widget", "Widget", 0));
    m_M1OPLabel->setText(QApplication::translate("Widget", "M1-OP", 0));
    m_M1CLLabel->setText(QApplication::translate("Widget", "M1-CL", 0));
    m_M2UPLabel->setText(QApplication::translate("Widget", "M2-UP", 0));
    m_M2DNLabel->setText(QApplication::translate("Widget", "M2-DN", 0));
    m_M3UPLabel->setText(QApplication::translate("Widget", "M3-UP", 0));
    m_M3DNLabel->setText(QApplication::translate("Widget", "M3-DN", 0));
    m_M4UPLabel->setText(QApplication::translate("Widget", "M4-UP", 0));
    m_M4DNLabel->setText(QApplication::translate("Widget", "M4-DN", 0));
    m_MBCWLabel->setText(QApplication::translate("Widget", "MB-CW", 0));
    m_MBCCWLabel->setText(QApplication::translate("Widget", "MB-CCW", 0));
    m_LIONLabel->setText(QApplication::translate("Widget", "L-ON", 0));
    m_WarningLabel->setText(QApplication::translate("Widget", "Warning", 0));
    m_ErrorLabel->setText(QApplication::translate("Widget", "Error", 0));
    m_QuitPushButton->setText(QApplication::translate("Widget", "&Quit", 0));
} // retranslateUi

void Widget::onChangeRobotArmStateTo(RobotArmState robotArmState)
{
    CRobotArm::instance()->setRobotArmSate(robotArmState);
}
