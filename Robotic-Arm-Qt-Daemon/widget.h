#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "robotarmstate.h"

#include "clabel.h"
#include "crobotarm.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
	void onChangeRobotArmStateTo(RobotArmState robotArmState);

protected:
    void setupUi();
    void retranslateUi();

protected:
	QVBoxLayout *verticalLayout;
    QHBoxLayout *m_MotorHorizontalLayout;
    QVBoxLayout *m_M1VerticalLayout;
    CLabel *m_M1OPLabel;
    CLabel *m_M1CLLabel;
    QVBoxLayout *m_M2VerticalLayout;
    CLabel *m_M2UPLabel;
    CLabel *m_M2DNLabel;
    QVBoxLayout *m_M3VerticalLayout;
    CLabel *m_M3UPLabel;
    CLabel *m_M3DNLabel;
    QVBoxLayout *m_M4VerticalLayout;
    CLabel *m_M4UPLabel;
    CLabel *m_M4DNLabel;
    QVBoxLayout *m_M5VerticalLayout;
    CLabel *m_MBCWLabel;
    CLabel *m_MBCCWLabel;
    QVBoxLayout *m_LIVerticalLayout;
    CLabel *m_LIONLabel;
    QLabel *m_WarningLabel;
    QLabel *m_ErrorLabel;
    QPushButton *m_QuitPushButton;
};

#endif // WIDGET_H
