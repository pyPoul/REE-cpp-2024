#include <iostream>
#include <vector>

#include "student.hpp"

using namespace std;


Student::Student(
    string id,
    string name,
    string firstname,
    string address,
    string phone,
    vector<DegreeObtained*>* degrees = {},
    vector<Experience*>* experiences = {}
) {
    _id = id;
    _name = name;
    _firstname = firstname;
    _address = address;
    _phone = phone;

    for (vector<Experience*>::const_iterator itPt = experiences->begin(); itPt != experiences->end(); itPt++) {
        _professionalExperiences.push_back(*itPt);
    }

    for (vector<DegreeObtained*>::const_iterator itPt = degrees->begin(); itPt != degrees->end(); itPt++) {
        _degreesObtained.push_back(*itPt);
    }
}

void Student::show() const {

    // [Firstname] [Name] ([0000001])
    cout << _firstname << ' ' << _name << " (" << _id << ")" << endl;
}

void Student::showDegrees() const {

    cout << "Diplômes obtenus :" << endl;
    Degree *d;
    for (vector<DegreeObtained*>::const_iterator itPt = _degreesObtained.begin(); itPt != _degreesObtained.end(); itPt++) {
        d = (*itPt)->degree;
        // [Code] [Name]
        cout << d->code << ' ' << d->name << endl;
    }
}

void Student::showExperiences() const {

    cout << "Expériences professionnelles :" << endl;
    Experience *e;
    for (vector<Experience*>::const_iterator itPt = _professionalExperiences.begin(); itPt != _professionalExperiences.end(); itPt++) {
        e = *itPt;
        // [Company]; [Job] ([from:YY-mm-dd] - [to:YY-mm-dd])
        cout << e->company << "; " << e->job << " (";
        e->start->show();
        cout << " -> ";
        e->end->show();
        cout << ")" << endl;
    }
}


FirstCycleStudent::FirstCycleStudent(
    string id,
    string name,
    string firstname,
    string address,
    string phone,
    string bacSeries,
    const Date* obtDate,
    string obtPlace,
    vector<DegreeObtained*>* degrees = {},
    vector<Experience*>* experiences = {}
) : Student(
    id,
    name,
    firstname,
    address,
    phone
) {
    _bacSeries = bacSeries;
    _dateObt = obtDate;
    _placeObt = obtPlace;
}


SecondCycleStudent::SecondCycleStudent(
    string id,
    string name,
    string firstname,
    string address,
    string phone,
    string discipline,
    vector<DegreeObtained*>* degrees = {},
    vector<Experience*>* experiences = {}
) : Student(
    id,
    name,
    firstname,
    address,
    phone
) {
    _discipline = discipline;
}
