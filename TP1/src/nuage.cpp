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

Cartesien barycentre(Nuage & n) {
    int n_size = n.size();
    double sum_x = 0;
    double sum_y = 0;
    Cartesien c;
    
    Nuage::const_iterator it = n.begin();
    while (it != n.end()) {
        (*it)->convertir(c);
        sum_x += c.getX();
        sum_y += c.getY();
        it++;
    }

    return Cartesien(sum_x/n_size, sum_y/n_size);
}

Cartesien BarycentreCartesien::operator()(Nuage & n) {
    return barycentre(n);
}

Polaire BarycentrePolaire::operator()(Nuage & n) {
    return Polaire(barycentre(n));
}