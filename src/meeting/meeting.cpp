#include <vector>

#include "meeting.hpp"

using namespace std;


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

    meetingList.push_back(this);
}
