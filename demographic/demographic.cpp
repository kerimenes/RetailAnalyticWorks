#include "demographic.h"
#include <cstdlib>
void Demographic::AddCustomer(const retail::yca::Person &a_customerData) {
	if (a_customerData.details().gender() ==
			retail::yca::PersonDetails::MAN) // erkekse
	{
		m_maleCustomers[a_customerData.id()] = a_customerData;
	} else {
		m_femaleCustomers[a_customerData.id()] = a_customerData;
	}
}

void Demographic::DeleteCustomer(const retail::yca::Person &a_customerData) {
	if (a_customerData.details().gender() ==
			retail::yca::PersonDetails::MAN) // erkekse
	{
		if (m_maleCustomers.count(a_customerData.id())) {
			m_maleCustomers.erase(a_customerData.id());
		}
	} else {
		if (m_femaleCustomers.count(a_customerData.id())) {
			m_femaleCustomers.erase(a_customerData.id());
		}
	}
}

void Demographic::Clear() {
	m_maleCustomers.clear();
	m_femaleCustomers.clear();
}

DemographicAnalyticStruct Demographic::GetResults() {

	DemographicAnalyticStruct res;
	res.male_percent = ((float)100 * m_maleCustomers.size()) /
			(m_maleCustomers.size() + m_femaleCustomers.size());
	res.female_percent = 100 - res.male_percent;
	res.male_ages.resize(6, 0);
	res.female_ages.resize(6, 0);
	for (auto &x : m_maleCustomers) {
		if (x.second.details().age() <= 18) {
			res.male_ages[0]++;
		} else if (x.second.details().age() <= 25) {
			res.male_ages[1]++;
		} else if (x.second.details().age() <= 35) {
			res.male_ages[2]++;
		} else if (x.second.details().age() <= 45) {
			res.male_ages[3]++;
		} else {
			res.male_ages[4]++;
		}
	}
	for (auto &x : m_femaleCustomers) {
		if (x.second.details().age() <= 18) {
			res.female_ages[0]++;
		} else if (x.second.details().age() <= 25) {
			res.female_ages[1]++;
		} else if (x.second.details().age() <= 35) {
			res.female_ages[2]++;
		} else if (x.second.details().age() <= 45) {
			res.female_ages[3]++;
		} else {
			res.female_ages[4]++;
		}
	}
	return res;
}

DemographicManager::DemographicManager(QObject *parent) {
	Demographic d;

	m_demographics["customers"] = d;
}

void DemographicManager::Reload(QList<retail::yca::Person> plist) {
	// TODO: veriyi dosyadan okuma
	for (auto &x : m_demographics) {
		x.second.Clear();
	}
	for (int i = 0; i < plist.size(); i++) {
		retail::yca::Person p = plist[i];
		m_demographics["customers"].AddCustomer(p);
	}
}

DemographicAnalyticStruct DemographicManager::GetResult(std::string a_key) {
	DemographicAnalyticStruct res;
	if (m_demographics.count(a_key)) {
		res = m_demographics[a_key].GetResults();
	}
	return res;
}
