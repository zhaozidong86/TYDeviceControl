#ifndef SIGNALMANAGE_H
#define SIGNALMANAGE_H

#include <QObject>

class SignalManage : public QObject
{
    Q_OBJECT
public:
    explicit SignalManage(QObject *parent = nullptr);

signals:

};

#endif // SIGNALMANAGE_H
