#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "datetime.hpp"
#include "degree.h"
#include "experience.h"
#include "student.hpp"
#include "utils.cpp"

using namespace std;


void addDegree(vector<DegreeObtained*>* degrees) {

    string code;
    string name;
    string obtDate;
    string obtPlace;
    Degree* degree = {};
    DegreeObtained* dO = {};

    cout << "Code :" << endl;
    cin >> code;

    cout << "Nom :" << endl;
    cin >> name;

    while (obtDate.length() != 10) {
        cout << "Date d'obtention : (format AAA-MM-JJ)" << endl;
    }

    cout << "Lieu d'obtention :" << endl;
    cin >> obtPlace;

    degree->_code = code;
    degree->_name = name;

    dO->_degree = degree;
    dO->_dateObt = stringToDate(obtDate);
    dO->_placeObt = obtPlace;

    degrees->push_back(dO);
}

void addExperience(vector<Experience*>* experiences) {

    string start;
    string end;
    string company;
    string job;
    Experience* exp = {};

    while (start.length() != 10) {

        cout << "Début :" << endl;
        cin >> start;
    }

    while (end.length() != 10) {

        cout << "Fin :" << endl;
        cin >> end;
    }

    cout << "Nom de l'entreprise :" << endl;
    cin >> company;

    cout << "Poste occupé :" << endl;
    cin >> job;

    exp->_start = stringToDate(start);
    exp->_end = stringToDate(end);
    exp->_company = company;
    exp->_job = job;

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

    cout << "Série du baccalauréat :" << endl;
    cin >> bacSeries;

    while (obtDate.length() != 10) {
        cout << "Date d'obtention : (format AAAA-MM-JJ)" << endl;
        cin >> obtDate;
    }

    cout << "Lieu d'obtention :" << endl;
    cin >> obtPlace;

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
    vector<DegreeObtained*>*,
    vector<Experience*>*
) {

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
    // student's cycle
    while (stuInp < 1 || stuInp > 2) {
        cout << "Ajouter un étudiant :\n 1. étudiant de premier cycle.\n 2. étudiant de second cycle." << endl;
        cin >> stuInp;
    }

    // student's id
    cout << "Numéro d'étudiant :" << endl;
    cin >> id;

    // student's name
    cout << "Nom :" << endl;
    cin >> name;

    // student's firstname
    cout << "Prénom :" << endl;
    cin >> firstname;

    // student's address
    cout << "Adresse :" << endl;
    cin >> address;

    // student's phone number
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
