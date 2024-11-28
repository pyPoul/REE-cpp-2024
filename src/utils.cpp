#include <string>

#include "datetime.hpp"
#include "student.hpp"
#include "meeting.hpp"

using namespace std;


const Date* stringToDate(string str) {

    int yyyy, mm, dd;

    // stoi : convert str to int
    yyyy = stoi(str.substr(0, 4));
    mm = stoi(str.substr(5, 2));
    dd = stoi(str.substr(8, 2));

    return new Date(yyyy, mm, dd);
}

Meeting::meetings fetchStudent(string stuName, string stuFirstname, string stuId) {

    // fetch student
    vector<Student*> students = Student::students;
    for (vector<Student*>::const_iterator itPt = students.begin(); itPt != students.end(); itPt++) {

    }
}
