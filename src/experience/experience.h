#include <string>

#include "../datetime/datetime.hpp"

#ifndef EXPERIENCE_H
#define EXPERIENCE_H

using namespace std;


struct Experience {

    const Date* start;
    const Date* end;
    string company;
    string job;
};


#endif  // EXPERIENCE_H
