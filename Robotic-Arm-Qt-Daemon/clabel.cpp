#include "crobotarm.h"
#include "clabel.h"

CLabel::CLabel(RobotArmState robotArmState, QWidget *parent) :
    QLabel(parent)
{
    setAutoFillBackground(true); // IMPORTANT!
    QPalette pal = palette();
    m_BackgroundColor = pal.color(QPalette::Window);
    m_RobotArmState = robotArmState;
}

void CLabel::mousePressEvent(QMouseEvent *pMouseEvent)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Window, QColor(Qt::green));
    setPalette(pal);
    emit changeRobotArmStateTo(m_RobotArmState);
    QLabel::mousePressEvent(pMouseEvent);
}

void CLabel::mouseReleaseEvent(QMouseEvent *pMouseEvent)
{
    emit changeRobotArmStateTo(CRobotArm::RobotArmResetState);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, m_BackgroundColor);
    setPalette(pal);
    QLabel::mouseReleaseEvent(pMouseEvent);
}
