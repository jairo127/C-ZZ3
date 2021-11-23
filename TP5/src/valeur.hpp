#ifndef __CPP5_ZZ3_VALEUR__
#define __CPP5_ZZ3_VALEUR__

#include <iostream>
#include <string>

class Valeur {
    private:
        double _note;
        std::string _etudiant; 

    public:
        Valeur(double note = 0, std::string etudiant = "inconnu") : _note(note), _etudiant(etudiant) {}

        double getNote() const { return _note; }
        void setNote(const double note) { _note = note; }
        std::string getEtudiant() const { return _etudiant; }
        void setEtudiant(const std::string etudiant) { _etudiant = etudiant; }
        double getNombre() const { return _note; }
        void setNombre(const double nombre) { _note = nombre; }

        bool operator<(Valeur const & r) const {
            return this->getNombre() < r.getNombre();
        }
};

std::ostream & operator<<(std::ostream & o,Valeur const & v){
	o << "(" << v.getEtudiant() << ";" << v.getNote() << ")";
	return o;
}

#endif