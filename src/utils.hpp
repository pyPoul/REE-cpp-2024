#include <string>
#include <vector>
#include <any>

#include "datetime/datetime.hpp"
#include "student/student.hpp"
#include "meeting/meeting.hpp"
#include "registration/registration.hpp"

#ifndef UTILS_CPP
#define UTILS_CPP

using namespace std;


// constants
const int OBJ_PER_PAGE = 7;


const Date* stringToDate(string str) {

    int yyyy, mm, dd;

    // stoi : convert str to int
    yyyy = stoi(str.substr(0, 4));
    mm = stoi(str.substr(5, 2));
    dd = stoi(str.substr(8, 2));

    return new Date(yyyy, mm, dd);
}

Meeting::meetings* fetchStudent(string stuName, string stuFirstname, string stuId) {

    // fetch student
    vector<Student*> students = Student::students;
    for (vector<Student*>::const_iterator itPt = students.begin(); itPt != students.end(); itPt++) {

    }
    return new Meeting::meetings();
}

string Paginate(
    vector<any>* vec,
    int page
) {
    int index = page * OBJ_PER_PAGE;
    return "";
}


#endif  // UTILS_CPP
