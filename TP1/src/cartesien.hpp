#ifndef __ZZ3_CPP1_CARTESIEN__
#define __ZZ3_CPP1_CARTESIEN__
#include <iostream>
#include <cmath>
#include "point.hpp"

class Cartesien : public Point {
    private:
        double _x;
        double _y;
    
    public:
        Cartesien();
        Cartesien(const double, const double);
        Cartesien(const Polaire&);
        void afficher(std::ostream&) const;
        void convertir(Polaire&) const override;
        void convertir(Cartesien&) const override;

        void setX(const double);
        void setY(const double);
        double getX() const;
        double getY() const;
};

#endif