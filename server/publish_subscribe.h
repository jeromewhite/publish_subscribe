#ifndef PUBLISH_SUBSCRIBE_H
#define PUBLISH_SUBSCRIBE_H

#include <QObject>
#include <QTcpServer>
#include "event_registry.h"
#include <QXmlStreamReader>

class publish_subscribe : public QTcpServer
{
    Q_OBJECT

public:
    publish_subscribe(QObject *parent = 0);

protected:
    void addSubsciber(int msgID, fd_set fd);
    void removeSubscriber(int msgID, fd_set fd);

signals:

public slots:
    void newConnection();
    void readReadySlot();

private:
//    QXmlStreamReader m_streamReader;
    EventRegistry *registerTable_p;

    int m_port;

    QTcpSocket  *m_sockp;
//    publish_subscribe *m_ps_server;
};

#endif // PUBLISH_SUBSCRIBE_H
