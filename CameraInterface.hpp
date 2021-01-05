#ifndef CAMERAINTERFACE_HPP
#define CAMERAINTERFACE_HPP

#include <QObject>

// 提供给通讯模块 ////////////////////////////////////////////////////////////////

//相机接口
class CCameraInterface :public QObject
{
    Q_OBJECT
public:
    CCameraInterface()
    {
        m_snapCount = 0;
        m_name = QStringLiteral("相机通讯接口");
        m_flagMode = 1;
        m_triggerPort = -1;
        m_triggerPort = 0;
    }
    virtual ~CCameraInterface(){}
    //设置名称
    void setName(QString name_)
    {
        m_name = name_;
        emit signalSetName(m_name);
    }
    //获取名称
    QString getName(){return m_name;}

    //设置模式:0 工作模式（接入相机），1 调试模式（不接相机，用于信号调试，模拟信号）
    void setMode(int flag_)
    {
        m_flagMode = flag_;
        emit signalSetMode(m_flagMode);
    }
    int getMode(){ return m_flagMode; }

    //相机编号
    void setIndex(int index) {
        m_index = index;
    }
    int getIndex(){ return m_index; }

    //需要拍照的帧数
    int getFrameCount() {
        return m_snapCount;
    }

    //硬触发端口号
    void setTriggerPort(int port) {
        m_triggerPort = port;
    }

    int getTriggerPort() {
        return m_triggerPort;
    }

    //触发方式0：软触发 1:硬触发
    int getTriggerType() {
        return m_triggerType;
    }

    void setTriggerType(int type) {
        m_triggerType = type;
    }



public slots:
    //收到新的条码,无码用当前时间戳代替
    void slotReceiveNewBarcode(QString barcode)
    {
        m_barcode = barcode;
        emit signalNewBarcode(m_barcode);
    }

    //设置一个周期内的拍照数量(工作模式时响应其它模块设置，调试模式时通讯模块设置用于模拟信号)
    void slotSetSnapCount(int count_)
    {
        m_snapCount = count_;
        emit signalSetSnapCount(m_snapCount);
    }
    //软触发
    void softWareTrigger()
    {
        emit siganlSoftWareTrigger();
    }

signals://输出
    void signalSetName(QString name_)	 ;//设置名称
    void signalSetMode(int flag_);//设置模式
    void signalNewBarcode(QString barcode);//新的码，无码用当前时间戳代替
    void signalSetSnapCount(int count_);//设置一个周期内的拍照数量
    void siganlSoftWareTrigger();//软触发一次

signals://输入

    //index号图像返回，调试模式时通讯模块模拟产生
    void signalImageCallback(int camIndex, int imgIndex) ;
    //所有画面拍照结束，调试模式时通讯模块模拟产生
    void signalSnapDone(int camIndex, int imgIndex, QString barcode)	;
    //所有画面处理完成，，调试模式时通讯模块模拟产生
    void signalProcessDone(int index, QString barcode, int result);//result:结果代号 0 OK,1 NG,-1 其它

private:
    int m_snapCount;
    QString m_name;
    QString m_barcode;
    int m_flagMode;
    int m_index;
    int m_triggerPort;
    int m_triggerType;

};

#endif // CAMERAINTERFACE_HPP
