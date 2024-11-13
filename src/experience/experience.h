#include <string>

#include "../datetime/datetime.hpp"

#ifndef EXPERIENCE_H
#define EXPERIENCE_H

using namespace std;


struct Experience {

    const Date* debut;
    const Date* fin;
    string nomEntreprise;
    string poste;
};


#endif  // EXPERIENCE_H
