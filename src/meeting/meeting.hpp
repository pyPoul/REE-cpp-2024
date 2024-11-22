#include <vector>

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
      static vector<Meeting*> meetingList;

      Meeting(const Date*, const Time*, const Time*, Company*, Student*);

      ~Meeting() { delete _date; delete _start; delete _end; delete _company; delete _student; }
};


#endif  // MEETING_HPP
