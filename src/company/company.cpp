#include <string>

#include "company.hpp"

using namespace std;


Company::Company(string name, string address, string contactName, string contactPhone) {
    _name = name;
    _address = address;
    _contactName = contactName;
    _contactPhone = contactPhone;
}
