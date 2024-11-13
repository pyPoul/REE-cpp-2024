#include <string>

#include "entreprise.hpp"

using namespace std;


Entreprise::Entreprise(string nom, string adresse, string nomContact, string telContact) {
    _nom = nom;
    _adresse = adresse;
    _nomContact = nomContact;
    _telContact = telContact;
}
