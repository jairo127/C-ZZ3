#ifndef __ZZ3_CPP1_NUAGE__
#define __ZZ3_CPP1_NUAGE__
#include <vector>
#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"

class Nuage {
    // using vector_pt = std::vector<Point*>;
    // using const_iterator = std::vector<Point*>::const_iterator;
    private:
        std::vector<Point*> _pts;

    public:
        typedef std::vector<Point*>::const_iterator const_iterator;

        Nuage();
        void ajouter(Point&);
        unsigned int size(void) const;
        std::vector<Point*>::const_iterator begin(void) const;
        std::vector<Point*>::const_iterator end(void) const;
};

Cartesien barycentre(Nuage&);

class BarycentreCartesien {
    public:
        Cartesien operator()(Nuage&);
};

class BarycentrePolaire {
    public:
        Polaire operator()(Nuage&);
};

#endif