#include <vector>

#include "inscription.hpp"

using namespace std;


Inscription::Inscription(Etudiant* etudiant, Diplome* diplome, const Date* premiere, int annee) {
    _etudiant = etudiant;
    _diplome = diplome;
    _premiereInscription = premiere;
    _numAnnee = annee;

    inscriptions.push_back(this);
}
