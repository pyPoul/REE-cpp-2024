#include <iostream>
#include <string>

#include "datetime/datetime.hpp"
#include "company/company.hpp"

using namespace std;


Company* createCompany() {

    string name;
    string address;
    string cName;
    string cPhone;

    // name
    cout << "Nom de l'entreprise :" << endl;
    cin >> name;
    
    // address
    cout << "Adresse :" << endl;
    cin >> address;

    // contact name
    cout << "Nom du contact :" << endl;
    cin >> cName;

    // contact phone
    cout << "Numéro de téléphone du contact :" << endl;
    cin >> cPhone;

    return new Company(name, address, cName, cPhone);
}

void listCompanies() {

}