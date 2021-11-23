// Gardien //---------------------------------------------------------------------------------------
#ifndef _NOMBRE_HPP_
#define _NOMBRE_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

// Classe  N o m b r e //---------------------------------------------------------------------------
class Nombre {
	//---------------------------------------------------------------------------------------------Amis
	friend Nombre operator+(const Nombre &,const Nombre &);
	friend Nombre operator-(const Nombre &,const Nombre &);
	friend Nombre operator*(const Nombre &,const Nombre &);
	friend Nombre operator/(const Nombre &,const Nombre &);

	friend std::ostream & operator<<(std::ostream &,const Nombre &);

	//----------------------------------------------------------------------------------------Attributs
 private:
	double valeur_;
	//-------------------------------------------------------------------------------------------Pause
	static void pause(unsigned n) { std::this_thread::sleep_for(std::chrono::milliseconds(50*n)); }

 public:
	//-----------------------------------------------------------------------------Constructeur defaut
	Nombre(double valeur = 0.0) : valeur_(valeur) { pause(1); }

	//------------------------------------------------------------------------------Constructeur copie
	Nombre(const Nombre & nombre) : valeur_(nombre.valeur_) { pause(1); }

	//------------------------------------------------------------------------------Affectation valeur
	Nombre & operator=(double valeur) {
		valeur_=valeur;
		pause(1);
		return *this;
	}	

	//-------------------------------------------------------------------------------Affectation copie
	Nombre & operator=(const Nombre & nombre) {
		valeur_=nombre.valeur_;
		pause(1);
		return *this;
	}

	//-----------------------------------------------------------------------------Conversion (double)
	operator double() const { return valeur_; }
};

// Surcharge operateurs //--------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------operator+
inline Nombre operator+(const Nombre & a,const Nombre & b) {
	Nombre::pause(10);
	return (a.valeur_+b.valeur_);
}

//-----------------------------------------------------------------------------------------operator-
inline Nombre operator-(const Nombre & a,const Nombre & b) {
	Nombre::pause(10);
	return (a.valeur_-b.valeur_);
}

//-----------------------------------------------------------------------------------------operator*
inline Nombre operator*(const Nombre & a,const Nombre & b) {
	Nombre::pause(10);
	return (a.valeur_*b.valeur_);
}

//-----------------------------------------------------------------------------------------operator/
inline Nombre operator/(const Nombre & a,const Nombre & b) {
	Nombre::pause(1000);
	return (a.valeur_/b.valeur_);
}

//-------------------------------------------------------------------------------operator<< (Nombre)
inline std::ostream & operator<<(std::ostream & flux,const Nombre & nombre) {
	flux << nombre.valeur_;
	return flux;
}

//-------------------------------------------------------------------------------operator<< (vector)
inline std::ostream & operator<<(std::ostream & flux,const std::vector<Nombre> & vecteur) {
	std::cout << "[";
	for (unsigned i = 0; i<vecteur.size(); ++i) flux << " " << vecteur[i];
	std::cout << " ]";
	return flux;
}

// Fin //-------------------------------------------------------------------------------------------

template <typename T>
void for_sequentiel(unsigned x, unsigned y, T f) {
	for (unsigned i = x; i < y; i++) {
		f(i);
	}
}

template <int N,typename T>
void for_parallele(unsigned x, unsigned y, T f) {
	std::thread t[N];
	unsigned taille = y-x;
	for (unsigned i = 0; i<N; ++i) t[i] = std::thread(for_sequentiel<T>,i*taille/N, (i+1)*taille/N, f);
	for (unsigned i = 0; i<N; ++i) t[i].join();

}

#endif
