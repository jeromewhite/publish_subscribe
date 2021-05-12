#ifndef PUBLISH_SUBSCRIBE_DOCUMENT_H
#define PUBLISH_SUBSCRIBE_DOCUMENT_H

#include <QObject>
#include <QXmlStreamReader>
#include <QByteArray>

class publish_subscribe_document {
//    Q_OBJECT

public:
    publish_subscribe_document(QByteArray);
    QXmlStreamReader xml;

signals:

public slots:
};

#endif // PUBLISH_SUBSCRIBE_DOCUMENT_H
