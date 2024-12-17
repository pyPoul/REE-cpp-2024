#include <vector>
#include <iostream>

#include "registration.hpp"

using namespace std;


vector<Registration*> Registration::registrations;

Registration::Registration(Student* student, Degree* degree, const Date* first, int year) {
    _student = student;
    _degree = degree;
    _firstRegistration = first;
    _yearNb = year;

    registrations.push_back(this);
}

void Registration::show() const {

    // [code] [name] ([nb year]ème année)
    // première inscription : [date:YYYY-mm-dd]
    cout << _degree->_code << " " << _degree->_name << "(" << _yearNb;
    if (_yearNb == 1) cout << "ère année";
    else cout << "ème années";
    cout << ")" << endl << "première inscription : ";
    _firstRegistration->show();
    cout << endl;
}
