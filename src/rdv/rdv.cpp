#include <vector>

#include "rdv.hpp"

using namespace std;


RDV::RDV(
    const Date* date,
    const Time* debut,
    const Time* fin,
    Entreprise* entreprise,
    Etudiant* etudiant
) {
    _date = date;
    _debut = debut;
    _fin = fin;
    _entreprise = entreprise;
    _etudiant = etudiant;

    listeRdv.push_back(this);
}
