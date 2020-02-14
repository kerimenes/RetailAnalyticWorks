#ifndef CUSTOMERSHAPPINES_H
#define CUSTOMERSHAPPINES_H

#include "grpc/analytic.grpc.pb.h"
#include <QObject>
#include <vector>

struct CustomerHappinesStruct {
  unsigned int happy = 0;
  unsigned int sad = 0;
  unsigned int inside = 0;
  unsigned int pass = 0;
  unsigned int look = 0;
  unsigned int total = 0;
};

class customershappines : public QObject {
  Q_OBJECT
public:
  customershappines();
  void AddCustomer(const retail::yca::CustomerData &a_customer);
  void Clear();
  void Reload();
  CustomerHappinesStruct GetResult();

private:
  std::vector<retail::yca::CustomerData> m_customers;
};

#endif // CUSTOMERSHAPPINES_H
