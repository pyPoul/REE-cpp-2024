#include <ctime>
#include <ostream>
#include <string>

#ifndef DATETIME_HPP
#define DATETIME_HPP

using namespace std;


class Date {

    time_t _timestamp;  // useful for sorting
    int _year;
    int _month;
    int _day;

    public:
      Date(int, int, int);

      ~Date() { delete &_timestamp; }

      void show(void) const;

      time_t timestamp() const { return _timestamp; }

    private:
      void getTimestamp(void);
};


class Time {

    time_t _timestamp;
    int _hours;
    int _minutes;
    int _seconds;

    public:
      Time(int, int, int);

      ~Time() { delete &_timestamp; }

      void show(void) const;

      time_t timestamp() const { return _timestamp; }

    private:
      void getTimestamp(void);
};


#endif  // DATETIME_HPP
