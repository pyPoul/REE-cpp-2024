#include <vector>
#include <string>

#include "../datetime/datetime.hpp"
#include "../degree/degree.h"
#include "../experience/experience.h"

#ifndef STUDENT_HPP
#define STUDENT_HPP

using namespace std;


class Student {

    protected:
        string _id;
        string _name;
        string _firstname;
        string _address;
        string _phone;
        vector<DegreeObtained*>* _degreesObtained;
        vector<Experience*>* _professionalExperiences;

    public:
      static vector<Student*> students;

      // constructor
      Student(
          string,
          string,
          string,
          string,
          string,
          vector<DegreeObtained*>*,
          vector<Experience*>*
      );

      // destructor
      virtual ~Student(void);

      virtual void show(void) const;
      void showDegrees(void) const;
      void showExperiences(void) const;
      void showRegistration(void) const;
      void showResume(void) const;

      void addDegree(DegreeObtained* d) { _degreesObtained->push_back(d); }
      void addExperience(Experience* e) { _professionalExperiences->push_back(e); }

      // returns Meeting::meetings*
      auto getMeetings(void) const;
};


class FirstCycleStudent : public Student {

    string _bacSeries;
    const Date* _dateObt;
    string _placeObt;

    public:
      FirstCycleStudent(
          string,
          string,
          string,
          string,
          string,
          string,
          const Date*,
          string,
          vector<DegreeObtained*>*,
          vector<Experience*>*
      );

      ~FirstCycleStudent(void);

      void show(void) const;
};


class SecondCycleStudent : public Student {

    string _discipline;

    public:
      SecondCycleStudent(
          string,
          string,
          string,
          string,
          string,
          string,
          vector<DegreeObtained*>*,
          vector<Experience*>*
      );

      ~SecondCycleStudent(void);

      void show(void) const;
};


#endif  // STUDENT_HPP
