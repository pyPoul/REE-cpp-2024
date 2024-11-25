#include <string>

#include "../datetime/datetime.hpp"

#ifndef DEGREE_H
#define DEGREE_H

using namespace std;


struct Degree {
    string code;
    string name;
};


struct DegreeObtained {
    Degree* degree;
    const Date* dateObt;
    string placeObt;
};


#endif  // DEGREE_H