#include <ctime>
#include <iostream>

#include "datetime.hpp"

using namespace std;


Date::Date(int year, int month, int day) {

    _day = day;  // [1-31]
    _month = month;  // [1-12]
    _year = year;
    getTimestamp();
}

void Date::getTimestamp() {

    // documentation from : https://koor.fr/C/ctime/ctimefct.wp
    struct tm d;

    d.tm_mday = _day;
    d.tm_mon = _month -1;  // tm_mon est defined on [0-11]
    d.tm_year = _year -1900;  // dates start 1/01/1900

    // rest at 0 because useless here
    d.tm_hour = 0;
    d.tm_min = 0;
    d.tm_sec = 0;

    // device time zone
    d.tm_isdst = -1;

    _timestamp = mktime(&d);  // return timestamp
}

void Date::show() const {
    cout << _year << '-' << _month << '-' << _day;
}


Time::Time(int hours, int minutes, int seconds) {

    _hours = hours;
    _minutes = minutes;
    _seconds = seconds;

    getTimestamp();
}

void Time::getTimestamp() {

    struct tm d;

    // date useless
    d.tm_mday = 1;  // [1-31]
    d.tm_mon = 0;  // tm_mon est defined on [0-11]
    d.tm_year = -1900;  // dates start 1/01/1900

    d.tm_hour = _hours;
    d.tm_min = _minutes;
    d.tm_sec = _seconds;

    // device time zone
    d.tm_isdst = -1;

    _timestamp = mktime(&d);  // return timestamp
}

void Time::show() const {
    cout << _hours << ':' << _minutes << ':' << _seconds;
}
