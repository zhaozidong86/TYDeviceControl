#ifndef XWCONTROLINTERFACE_H
#define XWCONTROLINTERFACE_H

#include <QObject>

class XWControlInterface : public QObject
{
    Q_OBJECT
public:
    explicit XWControlInterface(QObject *parent = nullptr);

signals:

};

#endif // XWCONTROLINTERFACE_H
