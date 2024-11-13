#include <ctime>
#include <ostream>
#include <string>

#ifndef DATETIME_HPP
#define DATETIME_HPP

using namespace std;


class Date {

    time_t _timestamp;  // utile pour les tris
    int _jour;
    int _mois;
    int _annee;

    public:
      Date(int, int, int);

      ~Date() { delete &_timestamp; }

      void affiche(void) const;

      time_t timestamp() const { return _timestamp; }

    private:
      void getTimestamp(void);
};


class Time {

    time_t _timestamp;
    int _heures;
    int _minutes;
    int _secondes;

    public:
      Time(int, int, int);

      ~Time() { delete &_timestamp; }

      void affiche(void) const;

      time_t timestamp() const { return _timestamp; }

    private:
      void getTimestamp(void);
};


#endif  // DATETIME_HPP
