#include <vector>

#include "../entreprise/entreprise.hpp"
#include "../etudiant/etudiant.hpp"
#include "../datetime/datetime.hpp"

#ifndef RDV_HPP
#define RDV_HPP

using namespace std;


class RDV {

    const Date* _date;
    const Time* _debut;
    const Time* _fin;
    Entreprise* _entreprise;
    Etudiant* _etudiant;

    public:
      static vector<RDV*> listeRdv;

      RDV(const Date*, const Time*, const Time*, Entreprise*, Etudiant*);

      ~RDV() { delete _date; delete _debut; delete _fin; delete _entreprise; delete _etudiant; }
};


#endif  // RDV_HPP
