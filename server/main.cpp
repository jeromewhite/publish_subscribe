#include <QCoreApplication>
#include <QTcpServer>
#include <QDebug>
#include <QNetworkInterface>
#include "publish_subscribe.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    publish_subscribe *pServer;
    pServer = new publish_subscribe;

    if (!pServer->listen(QHostAddress::Any, 50000)) {
        qDebug() << "Listen Failed" << endl;
        pServer->close();
        return 1;
    }
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            qDebug() << "Interface address = " << ipAddress << endl;
            break;
        }
    }


    pServer->waitForNewConnection();

    return a.exec();
}

