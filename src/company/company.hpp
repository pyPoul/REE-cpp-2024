#include <string>

#ifndef COMPANY_HPP
#define COMPANY_HPP

using namespace std;


class Company {

    string _name;
    string _address;
    string _contactName;
    string _contactPhone;

    public:
      Company(string, string, string, string);

      ~Company() {}
};


#endif  // COMPANY_HPP
