#ifndef DEMOGRAPHIC_H
#define DEMOGRAPHIC_H

#include "grpc/analytic.grpc.pb.h"
#include <QList>
#include <QObject>

struct DemographicAnalyticStruct {
  float male_percent;
  float female_percent;
  std::vector<int> male_ages; // [0]->0-18
  std::vector<int> female_ages;
};

class Demographic {

public:
  void AddCustomer(const retail::yca::Person &a_customerData);
  void DeleteCustomer(const retail::yca::Person &a_customerData);
  void Clear();
  DemographicAnalyticStruct GetResults();

private:
  std::map<uint64_t, retail::yca::Person> m_maleCustomers;
  std::map<uint64_t, retail::yca::Person> m_femaleCustomers;
};

class DemographicManager : public QObject {
  Q_OBJECT;

public:
  explicit DemographicManager(QObject *parent = nullptr);
  void Reload();
  DemographicAnalyticStruct GetResult(std::string a_key);

private:
  std::map<std::string, Demographic> m_demographics;
signals:
};

#endif // DEMOGRAPHIC_H
