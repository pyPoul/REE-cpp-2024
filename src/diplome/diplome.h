#include <string>

#include "../datetime/datetime.hpp"

#ifndef DIPLOME_H
#define DIPLOME_H

using namespace std;


struct Diplome {
    string code;
    string nom;
};


struct DiplomeObtenu {
    Diplome* diplome;
    const Date* dateObt;
    string lieuObt;
};


#endif  // DIPLOME_H