#include <iostream>
#include <vector>

#include "student.hpp"
#include "../registration/registration.hpp"
#include "../meeting/meeting.hpp"

using namespace std;


vector<Student*> Student::students;

// constructor
Student::Student(
    string id,
    string name,
    string firstname,
    string address,
    string phone,
    vector<DegreeObtained*>* degrees = nullptr,
    vector<Experience*>* experiences = nullptr
) {
    _id = id;
    _name = name;
    _firstname = firstname;
    _address = address;
    _phone = phone;

    _degreesObtained = new vector<DegreeObtained*>();
    if (degrees) {  // if degrees is not nullptr
        for (vector<Experience*>::const_iterator itPt = experiences->begin(); itPt != experiences->end(); itPt++) {
            _professionalExperiences->push_back(*itPt);
        }
    }

    _professionalExperiences = new vector<Experience*>();
    if (experiences) {  // if experiences is not nullptr
        for (vector<DegreeObtained*>::const_iterator itPt = degrees->begin(); itPt != degrees->end(); itPt++) {
            _degreesObtained->push_back(*itPt);
        }
    }
}

// destructor
Student::~Student() {
    
    for (DegreeObtained* d: *_degreesObtained) delete d;
    _degreesObtained->clear();
    for (Experience* e: *_professionalExperiences) delete e;
    _professionalExperiences->clear();
}

void Student::show() const {

    // [Firstname] [Name] ([0000001])
    cout << _firstname << ' ' << _name << " (" << _id << ")" << endl;
}

void Student::showDegrees() const {

    cout << "Diplômes obtenus :" << endl;
    const Degree *d;
    for (vector<DegreeObtained*>::const_iterator itPt = _degreesObtained->begin(); itPt != _degreesObtained->end(); itPt++) {
        d = (*itPt)->_degree;
        // [Code] [Name] ([Date:YYYY-mm-dd])
        cout << d->_code << ' ' << d->_name << " (";
        (*itPt)->_dateObt->show();
        cout << ")" << endl;
    }
}

void Student::showExperiences() const {

    cout << "Expériences professionnelles :" << endl;

    Experience *e;
    for (vector<Experience*>::const_iterator itPt = _professionalExperiences->begin(); itPt != _professionalExperiences->end(); itPt++) {
        e = *itPt;
        // [Company]; [Job] ([from:YYYY-mm-dd] -> [to:YYYY-mm-dd])
        cout << e->_company << "; " << e->_job << " (";
        e->_start->show();
        cout << " -> ";
        e->_end->show();
        cout << ")" << endl;
    }
}

void Student::showRegistration() const {

    cout << "Inscription administrative :" << endl;

    Registration* r;
    vector<Registration*> re = Registration::registrations;
    // looking for the registration
    for (vector<Registration*>::const_iterator itPt = re.begin(); itPt != re.end(); itPt++) {

        r = (*itPt);
        if (r->student() == this) {
            // print student's registration
            r->show();
            return;
        }
    }
}

void Student::showResume() const {

    cout << _firstname << ' ' << _name << endl;
    showRegistration();
    showDegrees();
    showExperiences();
}

// `auto` prevents circular dependency issues with meeting.hpp
auto Student::getMeetings() const {

    Meeting::meetings* studentMeetings = {};
    Meeting::meetings ml = Meeting::meetingList;
    // looking for student's meetings
    for (Meeting::meetings::const_iterator itPt = ml.begin(); itPt != ml.end(); itPt++) {

        Student* s = (*itPt)->student();
        if (s == this) studentMeetings->insert(*itPt);
    }
    return studentMeetings;
}


// constructor
FirstCycleStudent::FirstCycleStudent(
    string id,
    string name,
    string firstname,
    string address,
    string phone,
    string bacSeries,
    const Date* obtDate,
    string obtPlace,
    vector<DegreeObtained*>* degrees = nullptr,
    vector<Experience*>* experiences = nullptr
) : Student(
    id,
    name,
    firstname,
    address,
    phone,
    degrees,
    experiences
) {
    _bacSeries = bacSeries;
    _dateObt = obtDate;
    _placeObt = obtPlace;
}

FirstCycleStudent::~FirstCycleStudent() {
    
    for (DegreeObtained* d: *_degreesObtained) delete d;
    _degreesObtained->clear();
    for (Experience* e: *_professionalExperiences) delete e;
    _professionalExperiences->clear();
    delete _dateObt;
}

void FirstCycleStudent::show() const {

    // [Firstname] [Name] ([0000001]) (Premier cycle)
    cout << _firstname << ' ' << _name << " (" << _id << ") (Premier cycle)" << endl;
}


// constructor
SecondCycleStudent::SecondCycleStudent(
    string id,
    string name,
    string firstname,
    string address,
    string phone,
    string discipline,
    vector<DegreeObtained*>* degrees = nullptr,
    vector<Experience*>* experiences = nullptr
) : Student(
    id,
    name,
    firstname,
    address,
    phone,
    degrees,
    experiences
) {
    _discipline = discipline;
}

SecondCycleStudent::~SecondCycleStudent() {
    
    for (DegreeObtained* d: *_degreesObtained) delete d;
    _degreesObtained->clear();
    for (Experience* e: *_professionalExperiences) delete e;
    _professionalExperiences->clear();
}

void SecondCycleStudent::show() const {

    // [Firstname] [Name] ([0000001]) (Second cycle)
    cout << _firstname << ' ' << _name << " (" << _id << ") (Second cycle)" << endl;
}