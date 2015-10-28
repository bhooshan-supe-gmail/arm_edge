#ifndef CLABEL_H
#define CLABEL_H

#include <QLabel>

#include "robotarmstate.h"

class CLabel : public QLabel
{
    Q_OBJECT
public:
    explicit CLabel(RobotArmState robotArmState, QWidget *parent = 0);

signals:
    void changeRobotArmStateTo(RobotArmState robotArmState);

public slots:

protected :
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);

protected :
    QColor m_BackgroundColor;
    RobotArmState m_RobotArmState;
};

#endif // CLABEL_H
