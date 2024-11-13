#include <vector>
#include <string>

#include "../datetime/datetime.hpp"
#include "../diplome/diplome.h"
#include "../experience/experience.h"

#ifndef ETUDIANT_HPP
#define ETUDIANT_HPP

using namespace std;


class Etudiant {

    protected:
        string _numEtu;
        string _nom;
        string _prenom;
        string _adresse;
        string _numTel;
        vector<DiplomeObtenu*> _diplomesObtenus;
        vector<Experience*> _experiencesProfessionnelles;

    public:
      static vector<Etudiant*> etudiants;

      Etudiant(string, string, string, string, string);
      Etudiant(string, string, string, string, string, vector<Experience*>*);
      Etudiant(string, string, string, string, string, vector<DiplomeObtenu*>*);
      Etudiant(string, string, string, string, string, vector<DiplomeObtenu*>*, vector<Experience*>*);

      ~Etudiant() { delete &_diplomesObtenus; }

      void affiche(void) const;
      void afficheDiplomes(void) const;
      void afficheExperiences(void) const;

      void ajouterDiplome(DiplomeObtenu* d) { _diplomesObtenus.push_back(d); }
      void ajouterExperience(Experience* e) { _experiencesProfessionnelles.push_back(e); }
};


class EtudiantPremierCycle : public Etudiant {

    string _serieBac;
    const Date* _dateObt;
    string _lieuObt;

    public:
      EtudiantPremierCycle(string, string, string, string, string, string, const Date*, string);

      ~EtudiantPremierCycle() { delete &_dateObt; }
};


class EtudiantDeuxiemeCycle : public Etudiant {

    string _discipline;

    public:
      EtudiantDeuxiemeCycle(string, string, string, string, string, string);
};


#endif  // ETUDIANT_HPP
