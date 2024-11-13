#include <string>

#ifndef ENTREPRISE_HPP
#define ENTREPRISE_HPP

using namespace std;


class Entreprise {

    string _nom;
    string _adresse;
    string _nomContact;
    string _telContact;

    public:
      Entreprise(string, string, string, string);

      ~Entreprise() {}
};


#endif  // ENTREPRISE_HPP
