#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include "datetime/datetime.hpp"
#include "degree/degree.h"
#include "experience/experience.h"
#include "student/student.hpp"
#include "utils.hpp"

using namespace std;


void addDegree(vector<DegreeObtained*>* degrees) {

    string code;
    string name;
    string obtDate;
    string obtPlace;
    Degree* degree = {};
    DegreeObtained* dO = {};

    // code
    cout << "Code :" << endl;
    cin >> code;

    // name
    cout << "Nom :" << endl;
    cin >> name;

    // date
    while (obtDate.length() != 10) {
        cout << "Date d'obtention : (format AAA-MM-JJ)" << endl;
    }

    // place
    cout << "Lieu d'obtention :" << endl;
    cin >> obtPlace;

    // degree
    degree->_code = code;
    degree->_name = name;

    // degree obtained
    dO->_degree = degree;
    dO->_dateObt = stringToDate(obtDate);
    dO->_placeObt = obtPlace;

    // add to vector
    degrees->push_back(dO);
}

void addExperience(vector<Experience*>* experiences) {

    string start;
    string end;
    string company;
    string job;
    Experience* exp = {};

    // start
    while (start.length() != 10) {

        cout << "Début :" << endl;
        cin >> start;
    }

    // end
    while (end.length() != 10) {

        cout << "Fin :" << endl;
        cin >> end;
    }

    // end
    cout << "Nom de l'entreprise :" << endl;
    cin >> company;

    // job
    cout << "Poste occupé :" << endl;
    cin >> job;

    // experience
    exp->_start = stringToDate(start);
    exp->_end = stringToDate(end);
    exp->_company = company;
    exp->_job = job;

    // add to vector
    experiences->push_back(exp);
}

FirstCycleStudent* createFCStudent(
    string id,
    string name,
    string firstname,
    string address,
    string phone,
    vector<DegreeObtained*>* degrees,
    vector<Experience*>* experiences
) {

    string bacSeries;
    string obtDate;
    string obtPlace;

    // series
    cout << "Série du baccalauréat :" << endl;
    cin >> bacSeries;

    // date
    while (obtDate.length() != 10) {
        cout << "Date d'obtention : (format AAAA-MM-JJ)" << endl;
        cin >> obtDate;
    }

    // place
    cout << "Lieu d'obtention :" << endl;
    cin >> obtPlace;

    // student
    return new FirstCycleStudent(
        id,
        name,
        firstname,
        address,
        phone,
        bacSeries,
        stringToDate(obtDate),
        obtPlace,
        degrees,
        experiences
    );
}

SecondCycleStudent* createSCStudent(
    string id,
    string name,
    string firstname,
    string address,
    string phone,
    vector<DegreeObtained*>* degrees,
    vector<Experience*>* experiences
) {

    string discipline;

    // discipline
    cout << "Nom de la discipline :" << endl;
    cin >> discipline;

    // student
    return new SecondCycleStudent(
        id,
        name,
        firstname,
        address,
        phone,
        discipline,
        degrees,
        experiences
    );
}

Student* createStudent() {

    string id;
    string name;
    string firstname;
    string address;
    string phone;
    vector<DegreeObtained*>* degrees = new vector<DegreeObtained*>();
    vector<Experience*>* experiences = new vector<Experience*>();
    char deg = 'O';
    char exp = 'O';

    int stuInp;
    // student cycle
    while (stuInp < 1 || stuInp > 2) {
        cout << "Ajouter un étudiant :\n 1. étudiant de premier cycle.\n 2. étudiant de second cycle." << endl;
        cin >> stuInp;
    }

    // student id
    cout << "Numéro d'étudiant :" << endl;
    cin >> id;

    // student name
    cout << "Nom :" << endl;
    cin >> name;

    // student firstname
    cout << "Prénom :" << endl;
    cin >> firstname;

    // student address
    cout << "Adresse :" << endl;
    cin >> address;

    // student phone number
    cout << "Numéro de téléphone :" << endl;
    cin >> phone;

    // student degrees obtained
    while (toupper(deg) == 'O') {

        cout << "Ajouter un diplôme ? (O/N)" << endl;
        cin >> deg;

        if (toupper(deg) == 'N') {
            break;
        }
        if (toupper(deg) != 'O') {
            deg = 'O';
            continue;
        }
        addDegree(degrees);
    }

    // student professional experiences
    while (toupper(exp) == 'O') {

        // add ?
        cout << "Ajouter une expérience professionnelle ? (O/N)" << endl;
        cin >> exp;

        // break the loop
        if (toupper(exp) == 'N') {
            break;
        }
        // ask again
        if (toupper(exp) != 'O') {
            exp = 'O';
            continue;
        }

        addExperience(experiences);
    }

    // first cycle student
    if (stuInp == 1) return createFCStudent(id, name, firstname, address, phone, degrees, experiences);
    // second cycle student
    if (stuInp == 2) return createSCStudent(id, name, firstname, address, phone, degrees, experiences);
    // should not happen
    else throw invalid_argument("Can't create Student with this input.");
}

void listStudents() {

    vector<Student*> sts = Student::students;
    if (sts.size() == 0) {
        cout << "Aucun étudiant" << endl;
        return;
    }

    int vSize = sts.size();
    int maxPage;
    int page = 0;
    int begin = 0;
    int end = min(OBJ_PER_PAGE, vSize);

}