#include <string>

#include "../datetime/datetime.hpp"

#ifndef EXPERIENCE_H
#define EXPERIENCE_H

using namespace std;


struct Experience {

    const Date* _start;
    const Date* _end;
    string _company;
    string _job;
};


#endif  // EXPERIENCE_H
