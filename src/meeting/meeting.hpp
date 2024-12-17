#include <set>

#include "../company/company.hpp"
#include "../student/student.hpp"
#include "../datetime/datetime.hpp"

#ifndef MEETING_HPP
#define MEETING_HPP

using namespace std;


class Meeting {

    const Date* _date;
    const Time* _start;
    const Time* _end;
    Company* _company;
    Student* _student;

    public:
      typedef set<Meeting*> meetings;
      static meetings meetingList;

      Meeting(const Date*, const Time*, const Time*, Company*, Student*);

      ~Meeting() { delete _date; delete _start; delete _end; delete _company; delete _student; }

      // getter
      Company* company() const { return _company; }
      Student* student() const { return _student; }
      const Date* date() const { return _date; }
      const Time* start() const { return _start; }

      // overload < operator
      bool operator<(const Meeting&) const;
};


#endif  // MEETING_HPP
