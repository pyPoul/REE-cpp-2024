
#include "student/student.hpp"


int main() {

    Student* etu = new Student("numEtu", "nom", "prenom", "adresse", "012345678", {}, {});
    etu->show();

    return 0;
}
