#include <iostream>
#include <map>

#include "company.hpp"
#include "datetime.hpp"
#include "degree.h"
#include "experience.h"
#include "meeting.hpp"
#include "registration.hpp"
#include "student.hpp"

using namespace std;


FirstCycleStudent createFCStudent(string id, string name, string firstname, string address, string phone) {

}

Student* createStudent() {

    vector<void (**)>inpStu = new vector<void (**)>{
        *createFCStudent
    };

    string id;
    string name;
    string firstname;
    string address;
    string phone;

    int stuInp;
    while (stuInp < 1 || stuInp > 2) {
        cout << "Ajouter un étudiant :\n 1. étudiant de premier cycle.\n 2. étudiant de second cycle." << endl;
        cin >> stuInp;
    }


    return new Student();
}
