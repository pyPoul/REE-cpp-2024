#include <iostream>
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

void sPrevious() {
    cout << "[P] Page Précédente.\t";
}

void sNext() {
    cout << "[S] Page Suivante.";
}

int Paginate(vector<any>* vec) {

    int page = 0;
    int maxPage;
    bool end;
    string inp;

    int vSize = vec->size();
    int start = page * OBJ_PER_PAGE;
    int stop = min(start + OBJ_PER_PAGE, vSize -1);

    while (start <= stop) {
        cout << start + 1 << ". " << vec[start]->show() << endl;
        start++;
    }

    if (page != 0) sPrevious();
    if (page != maxPage -1) sNext();
        cout << endl;

    cin >> inp;

    return 1;
}


#endif  // UTILS_CPP
