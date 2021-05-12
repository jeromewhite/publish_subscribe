#include <QDebug>
#include <QThread>
#include <QTcpSocket>
#include <QByteArray>
#include "publish_subscribe_document.h"

#include "publish_subscribe.h"

publish_subscribe::publish_subscribe(QObject *parent) :  QTcpServer(parent)
{
    qDebug() << "In contructor" << endl;
//    QThread *threadp = this->thread();

    connect(this, SIGNAL(newConnection()), SLOT(newConnection()));

}

void publish_subscribe::addSubsciber(int msgID, fd_set fd)
{

}

void publish_subscribe::removeSubscriber(int msgID, fd_set fd)
{

}

void publish_subscribe::readReadySlot()
{
qDebug() << "Entered readReadyslot() " << endl;

    QByteArray document = m_sockp->readAll();
//    qDebug() << "read line done " << document << endl;
    m_sockp->write(document);
    publish_subscribe_document m_streamReader(document);
}

void publish_subscribe::newConnection()
{
    qDebug() << "Entered newConnection()" << endl;

    m_sockp = this->nextPendingConnection();

    if(m_sockp) {
        qDebug() << "Pending Connections" << endl;
        connect(m_sockp, SIGNAL(readyRead()), this, SLOT(readReadySlot()));
    } else {
        qDebug() << "No Pending Connections" << endl;
    }
}
