#include <vector>

#include "../etudiant/etudiant.hpp"
#include "../diplome/diplome.h"
#include "../datetime/datetime.hpp"

#ifndef INSCRIPTION_HPP
#define INSCRIPTION_HPP

using namespace std;


class Inscription {

    Etudiant* _etudiant;
    Diplome* _diplome;
    const Date* _premiereInscription;
    int _numAnnee;

    public:
      static vector<Inscription*> inscriptions;

    Inscription(Etudiant*, Diplome*, const Date*, int);

    ~Inscription() { delete _etudiant; delete _diplome; delete _premiereInscription; }

};


#endif  // INSCRIPTION_HPP
