#ifndef DEVICEMANAGE_H
#define DEVICEMANAGE_H

#include <QObject>

class DeviceManage : public QObject
{
    Q_OBJECT
public:
    explicit DeviceManage(QObject *parent = nullptr);

signals:

};

#endif // DEVICEMANAGE_H
