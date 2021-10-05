#include "nuage.hpp"

Nuage::Nuage() {}

void Nuage::ajouter(Point& p) {
    _pts.push_back(&p);
}

unsigned int Nuage::size(void) const {
    return _pts.size();
}

std::vector<Point*>::const_iterator Nuage::begin(void) const {
    return _pts.begin();
}

std::vector<Point*>::const_iterator Nuage::end(void) const {
    return _pts.end();
}

Cartesien barycentre(Nuage n) {
    int n_size = n.size();
    double sum_x = 0;
    double sum_y = 0;
    
    Nuage::const_iterator it = n.begin();
    while (it != n.end()) {
    }
    return Cartesien();
}