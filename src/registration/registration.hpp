#include <vector>

#include "../student/student.hpp"
#include "../degree/degree.h"
#include "../datetime/datetime.hpp"

#ifndef REGISTRATION_HPP
#define REGISTRATION_HPP

using namespace std;


class Registration {

    Student* _student;
    Degree* _degree;
    const Date* _firstRegistration;
    int _yearNb;

    public:
      static vector<Registration*> registrations;

    Registration(Student*, Degree*, const Date*, int);

    ~Registration() { delete _student; delete _degree; delete _firstRegistration; }

};


#endif  // REGISTRATION_HPP
