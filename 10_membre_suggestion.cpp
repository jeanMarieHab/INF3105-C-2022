/**
 * Tests unitaires pour Membre.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Automne 2022)
 */

#include <iostream>
#include <fstream>
#include <sstream>

#include "membre.h"
#include "extraction.h"

int main(int argc, char** argv) {
	std::cout << "Suggestion favoris (membre)" << std::endl;
	const char * fichier = "groupe.txt";
	Tableau<Membre> membres = extraire(fichier);
	bool suggestion_bool = true;
	// harry lula
	Tableau<std::string> suggestion_harry_lula = membres[0].suggestion(membres[1]); 
	if(suggestion_harry_lula.taille() != 3){
		std::cout << " ==> ECHEC Nombre de suggestions harry" << std::endl;
		suggestion_bool = false;
	}
	std::string tab_1 [] = {"brand new cherry flavor", "the trial of the chicago 7", "fistful of vengeance"};
	for(std::string s : tab_1)
		if(suggestion_harry_lula.occurrence(s) != 1) {
			std::cout << " ==> ECHEC suggestion manquante harry : " << s << std::endl;
			suggestion_bool = false;
		}
	// lula harry
	Tableau<std::string> suggestion_lula_harry = membres[1].suggestion(membres[0]); 
	if(suggestion_lula_harry.taille() != 3){
		std::cout << " ==> ECHEC Nombre de suggestions lula" << std::endl;
		suggestion_bool = false;
	}
	std::string tab_2 [] = {"archive 81", "izombie", "home team"};
	for(std::string s : tab_2)
		if(suggestion_lula_harry.occurrence(s) != 1) {
			std::cout << " ==> ECHEC suggestion manquante lula : " << s << std::endl;
			suggestion_bool = false;
		}

	// alice martin
	Tableau<std::string> suggestion_alice_martin = membres[2].suggestion(membres[3]); 
	if(suggestion_alice_martin.taille() != 3){
		std::cout << " ==> ECHEC Nombre de suggestions alice" << std::endl;
		suggestion_bool = false;
	}
	std::string tab_3 [] = {"archive 81", "the woman in the window", "winter on fire: ukraine's fight for freedom"};
	for(std::string s : tab_3)
		if(suggestion_alice_martin.occurrence(s) != 1) {
			std::cout << " ==> ECHEC suggestion manquante alice : " << s << std::endl;
			suggestion_bool = false;
		}

	// martin florence
	Tableau<std::string> suggestion_martin_florence = membres[3].suggestion(membres[4]);
	if(suggestion_martin_florence.taille() != 3){
		std::cout << " ==> ECHEC Nombre de suggestions martin" << std::endl;
		suggestion_bool = false;
	}
	std::string tab_4 [] = {"the trial of the chicago 7", "home team", "catching killers"};
	for(std::string s : tab_4)
		if(suggestion_martin_florence.occurrence(s) != 1) {
			std::cout << " ==> ECHEC suggestion manquante martin : " << s << std::endl;
			suggestion_bool = false;
		}

	if(suggestion_bool)
			std::cout << " ==> OK" << std::endl;
	return suggestion_bool ? 0 : 1;
}

