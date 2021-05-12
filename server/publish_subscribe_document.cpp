#include <QXmlStreamReader>
#include <QDebug>
#include "publish_subscribe_document.h"

publish_subscribe_document::publish_subscribe_document(QByteArray doc)
{
    qDebug() << "publish_subscribe_document()" << endl;

    this->xml.addData(doc);
    while (!this->xml.atEnd() && !this->xml.hasError()){
//        QString value = "";
        QStringRef value;
//        this->xml.readNextStartElement();
        int token = this->xml.readNext();
        QStringRef nameValue = this->xml.name();
        qDebug() << "Name = " << nameValue << endl;
        QString tokenValue = this->xml.tokenString();
        if(token == QXmlStreamReader::StartElement) {
            if(nameValue == "message") {
                while (this->xml.readNext() != QXmlStreamReader::EndElement || this->xml.name() != "message") {
                    value = this->xml.text();
                    qDebug() << "value = " << value;
                }
//                value = this->xml.readElementText();
//                value = this->xml.text();
//                qDebug() << "value = " << value << endl;
//                qDebug() << "Name = " << nameValue << " value = " << value << "tokenValue = "<< tokenValue << "tokenType = " << this->xml.tokenType() << endl;
                if(this->xml.hasError()) {
                    qDebug() << "Has Error is " << this->xml.errorString() << endl;
                }
            }
        }
    }
    qDebug() << "Done iteration" << endl;
}
