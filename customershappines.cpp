#include "customershappines.h"

customershappines::customershappines() {}

void customershappines::AddCustomer(
    const retail::yca::CustomerData &a_customer) {
  m_customers.push_back(a_customer);
}

void customershappines::Clear() { m_customers.clear(); }

void customershappines::Reload() {}

CustomerHappinesStruct customershappines::GetResult() {
  CustomerHappinesStruct res;
  for (auto &x : m_customers) {
    if (x.details().mood() == retail::yca::CustomerDetails::Happy) {
      res.happy++;
    } else {
      res.sad++;
    }
    if (x.details().action() == retail::yca::CustomerDetails::Inside) {
      res.inside++;
    } else if (x.details().action() == retail::yca::CustomerDetails::Look) {
      res.look++;
    } else {
      res.pass++;
    }
  }
  return res;
}
