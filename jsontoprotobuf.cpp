#include "jsontoprotobuf.h"
#include <QFile>

#include <google/protobuf/util/json_util.h>

#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

static QString readFile(QString path)
{
	QFile file(path);
	if(!file.open(QIODevice::ReadOnly))
		return 0;

	QString jdata = file.readAll().data();
	file.close();

	return jdata;
}

JsonToProtobuf::JsonToProtobuf(const QString &file, int type)
{
	QString data = readFile(file);
	QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
	QJsonArray personArray = doc.array();
	for(int i = 0; i < personArray.size(); i++) {
		retail::yca::Person person;
		QString str = QString::fromUtf8(QJsonDocument(personArray[i].toObject()).toJson());
		google::protobuf::util::JsonStringToMessage(str.toStdString(), &person);
		qDebug() << person.id();
		plist << person;
	}
//	qDebug() << plist[0].id();
}

QList<retail::yca::Person> JsonToProtobuf::getPersonList()
{
	return plist;
}
