#include <vector>

#include "registration.hpp"

using namespace std;


Registration::Registration(Student* student, Degree* degree, const Date* first, int year) {
    _student = student;
    _degree = degree;
    _firstRegistration = first;
    _yearNb = year;

    registrations.push_back(this);
}
