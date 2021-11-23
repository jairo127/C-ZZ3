// Entetes //---------------------------------------------------------------------------------------
#include "catch.hpp"

#include <cmath>
#include <random>

#include "Nombre.hpp"


// Tests //-----------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------ 1
TEST_CASE ( "TP3_Valeur::Constructeur" ) {
	unsigned compteur = 0;
	
	const unsigned taille = 12;

	std::vector<Nombre> a(taille);
	std::vector<Nombre> b(taille);
	std::vector<Nombre> c(taille);

	for_sequentiel(0,taille, [&] (unsigned i) { a[i] = ++compteur; } );
	for_sequentiel(0,taille, [&] (unsigned i) { b[i] = ++compteur; } );

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "compteur = " << compteur << std::endl;

	for_sequentiel(0,taille, [&] (unsigned i) { c[i] = a[i]*b[i]; } );
	
	std::cout << "c = " << c << std::endl;

	REQUIRE ( a[0] == 1 );
	REQUIRE ( a[taille-1] == taille );
	REQUIRE ( b[0] == taille+1 );
	REQUIRE ( b[taille-1] == taille*2 );
	REQUIRE ( c[0] == taille+1 );
	REQUIRE ( c[taille-1] == taille*2*taille );
}

// Fin //-------------------------------------------------------------------------------------------
