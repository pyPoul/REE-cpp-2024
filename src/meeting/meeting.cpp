#include <set>

#include "meeting.hpp"

using namespace std;


Meeting::meetings Meeting::meetingList;

Meeting::Meeting(
    const Date* date,
    const Time* start,
    const Time* end,
    Company* company,
    Student* student
) {
    _date = date;
    _start = start;
    _end = end;
    _company = company;
    _student = student;

    meetingList.insert(this);
}

// overload < operator
bool Meeting::operator<(const Meeting& other) const {

    // sorts meetingList by company name and datetime
    if (_company->name() == other.company()->name()) {
        return _date->timestamp() + _start->timestamp() < other.date()->timestamp() + other.start()->timestamp();
    }
    return _company->name() < other.company()->name();
}