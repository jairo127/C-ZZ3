#ifndef __ZZ3_CPP1_Polaire__
#define __ZZ3_CPP1_Polaire__
#include <iostream>
#include <cmath>
#include "point.hpp"

class Polaire : public Point {
    private:
        double _a;
        double _d;
    
    public:
        Polaire();
        Polaire(const double, const double);
        Polaire(const Cartesien&);
        void afficher(std::ostream&) const;
        void convertir(Polaire&) const override;
        void convertir(Cartesien&) const override;

        void setAngle(const double);
        void setDistance(const double);
        double getAngle() const;
        double getDistance() const;
};

#endif