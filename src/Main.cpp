
#include "datetime/datetime.hpp"
#include "etudiant/etudiant.cpp"
#include "diplome/diplome.h"

int main() {

    Etudiant* etu = new EtudiantDeuxiemeCycle("numEtu", "nom", "prenom", "adresse", "012345678", "t");
    etu->affiche();

    return 0;
}