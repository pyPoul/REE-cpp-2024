#include <iostream>
#include <vector>

#include "etudiant.hpp"

using namespace std;


Etudiant::Etudiant(
    string numEtu,
    string nom,
    string prenom,
    string adresse,
    string numTel
) {
    _numEtu = numEtu;
    _nom = nom;
    _prenom = prenom;
    _adresse = adresse;
    _numTel = numTel;
}

Etudiant::Etudiant(
    string numEtu,
    string nom,
    string prenom,
    string adresse,
    string numTel,
    vector<Experience*>* experiences
) {
    _numEtu = numEtu;
    _nom = nom;
    _prenom = prenom;
    _adresse = adresse;
    _numTel = numTel;

    for (vector<Experience*>::const_iterator itPt = experiences->begin(); itPt != experiences->end(); itPt++) {
        _experiencesProfessionnelles.push_back(*itPt);
    }
}

Etudiant::Etudiant(
    string numEtu,
    string nom,
    string prenom,
    string adresse,
    string numTel,
    vector<DiplomeObtenu*>* diplomes
) {
    _numEtu = numEtu;
    _nom = nom;
    _prenom = prenom;
    _adresse = adresse;
    _numTel = numTel;

    for (vector<DiplomeObtenu*>::const_iterator itPt = diplomes->begin(); itPt != diplomes->end(); itPt++) {
        _diplomesObtenus.push_back(*itPt);
    }
}

Etudiant::Etudiant(
    string numEtu,
    string nom,
    string prenom,
    string adresse,
    string numTel,
    vector<DiplomeObtenu*>* diplomes,
    vector<Experience*>* experiences
) {
    _numEtu = numEtu;
    _nom = nom;
    _prenom = prenom;
    _adresse = adresse;
    _numTel = numTel;

    for (vector<Experience*>::const_iterator itPt = experiences->begin(); itPt != experiences->end(); itPt++) {
        _experiencesProfessionnelles.push_back(*itPt);
    }

    for (vector<DiplomeObtenu*>::const_iterator itPt = diplomes->begin(); itPt != diplomes->end(); itPt++) {
        _diplomesObtenus.push_back(*itPt);
    }
}

void Etudiant::affiche() const {

    cout << _prenom << ' ' << _nom << " (" << _numEtu << ")" << endl;
}

void Etudiant::afficheDiplomes() const {

    cout << "Diplômes obtenus :" << endl;
    Diplome *d;
    for (vector<DiplomeObtenu*>::const_iterator itPt = _diplomesObtenus.begin(); itPt != _diplomesObtenus.end(); itPt++) {
        d = (*itPt)->diplome;
        cout << d->code << ' ' << d->nom << endl;
    }
}


EtudiantPremierCycle::EtudiantPremierCycle(
    string numEtu,
    string nom,
    string prenom,
    string adresse,
    string numTel,
    string serieBac,
    const Date* dateObtBac,
    string lieuObtBac
) : Etudiant(
    numEtu,
    nom,
    prenom,
    adresse,
    numTel
) {
    _serieBac = serieBac;
    _dateObt = dateObtBac;
    _lieuObt = lieuObtBac;
}


EtudiantDeuxiemeCycle::EtudiantDeuxiemeCycle(
    string numEtu,
    string nom,
    string prenom,
    string adresse,
    string numTel,
    string discipline
) : Etudiant(
    numEtu,
    nom,
    prenom,
    adresse,
    numTel
) {
    _discipline = discipline;
}
