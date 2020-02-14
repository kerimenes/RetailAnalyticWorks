#include "jsontoprotobuf.h"
#include <QFile>

#include <grpc/analytic.pb.h>
#include <grpc/analytic.grpc.pb.h>
#include <google/protobuf/util/json_util.h>

static QString readFile(QString path)
{
	QFile file(path);
	if(!file.open(QIODevice::ReadOnly))
		return 0;

	QString jdata = file.readAll().data();
	file.close();

	return jdata;
}
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

JsonToProtobuf::JsonToProtobuf(const QString &file)
{
	QString data = readFile(file);
	QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
	QJsonArray personArray = doc.array();
	QList<retail::yca::Person> plist;
	qDebug() << "" << personArray.size();
	for(int i = 0; i < personArray.size(); i++) {
		retail::yca::Person person;
		QString str = QString::fromUtf8(QJsonDocument(personArray[i].toObject()).toJson());
		google::protobuf::util::JsonStringToMessage(str.toStdString(), &person);
		qDebug() << person.id();
		plist << person;
	}
//	qDebug() << plist[0].id();


}
