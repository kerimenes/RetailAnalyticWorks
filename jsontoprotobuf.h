#ifndef JSONTOPROTOBUF_H
#define JSONTOPROTOBUF_H

#include <QObject>
#include <grpc/analytic.pb.h>
#include <grpc/analytic.grpc.pb.h>
class JsonToProtobuf
{
public:
	JsonToProtobuf(const QString &file, int type);
	QList<retail::yca::Person> getPersonList();
protected:
	QList<retail::yca::Person> plist;

};

#endif // JSONTOPROTOBUF_H
