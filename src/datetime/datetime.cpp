#include <ctime>
#include <iostream>

#include "datetime.hpp"

using namespace std;


Date::Date(int annee, int mois, int jour) {

    _jour = jour;  // [1-31]
    _mois = mois;  // [1-12]
    _annee = annee;
    getTimestamp();
}

void Date::getTimestamp() {

    // documentation de : https://koor.fr/C/ctime/ctimefct.wp
    struct tm d;

    d.tm_mday = _jour;
    d.tm_mon = _mois -1;  // puisque tm_mon est défini sur [0-11]
    d.tm_year = _annee -1900;  // dates à partir du 1/01/1900

    // reste à 0 car inutile ici
    d.tm_hour = 0;
    d.tm_min = 0;
    d.tm_sec = 0;

    // fuseau horaire de la machine
    d.tm_isdst = -1;

    _timestamp = mktime(&d);  // retourne timestamp
}

void Date::affiche() const {
    cout << _annee << '-' << _mois << '-' << _jour;
}


Time::Time(int heures, int minutes, int secondes) {

    _heures = heures;
    _minutes = minutes;
    _secondes = secondes;

    getTimestamp();
}

void Time::affiche() const {
    cout << _heures << ':' << _minutes << ':' << _secondes;
}
