#include <string>
#include <iostream>

#include "company.hpp"

using namespace std;


Company::Company(string name, string address, string contactName, string contactPhone) {
    _name = name;
    _address = address;
    _contactName = contactName;
    _contactPhone = contactPhone;
}

void Company::show() const {

    // [name] ([address])
    //   [contact name] ([contact phone])
    cout << _name << " (" << _address << ")" << endl;
    cout << "\tContact : " << _contactName << " (" << _contactPhone <<")" << endl;
}
