#include <string>

#include "datetime.hpp"

#ifndef DEGREE_H
#define DEGREE_H

using namespace std;


struct Degree {
    string _code;
    string _name;
};


struct DegreeObtained {
    const Degree* _degree;
    const Date* _dateObt;
    string _placeObt;
};


#endif  // DEGREE_H