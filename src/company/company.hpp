#include <string>
#include <vector>

#ifndef COMPANY_HPP
#define COMPANY_HPP

using namespace std;


class Company {

    string _name;
    string _address;
    string _contactName;
    string _contactPhone;

    public:
      static vector<Company*> companies;

      Company(string, string, string, string);

      ~Company() {}

      string name() const { return _name; }

      void show(void) const;
};


#endif  // COMPANY_HPP
