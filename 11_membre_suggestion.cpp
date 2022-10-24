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
	std::cout << "Suggestion favoris" << std::endl;
	const char * fichier = "groupe.txt";
	Tableau<Membre> membres = extraire(fichier);
	bool suggestion_bool = true;
	// harry
	Tableau<std::string> suggestion_harry = membres[0].suggestion(membres); 
	if(suggestion_harry.taille() != 7){
		std::cout << " ==> ECHEC Nombre de suggestions harry" << std::endl;
		suggestion_bool = false;
	}
	std::string tab_1 [] = {"altered carbon", "audible", "brand new cherry flavor", "catching killers", "fistful of vengeance", "the trial of the chicago 7", "winter on fire: ukraine's fight for freedom"};
	for(std::string s : tab_1)
		if(suggestion_harry.occurrence(s) != 1) {
			std::cout << " ==> ECHEC suggestion manquante harry : " << s << std::endl;
			suggestion_bool = false;
		}
	// alice
	Tableau<std::string> suggestion_alice = membres[2].suggestion(membres); 
	if(suggestion_alice.taille() != 7){
		std::cout << " ==> ECHEC Nombre de suggestions alice" << std::endl;
		suggestion_bool = false;
	}
	std::string tab_2 [] = {"archive 81", "brand new cherry flavor", "catching killers", "fistful of vengeance", "home team", "the woman in the window", "winter on fire: ukraine's fight for freedom"};
	for(std::string s : tab_2)
		if(suggestion_alice.occurrence(s) != 1) {
			std::cout << " ==> ECHEC suggestion manquante alice : " << s << std::endl;
			suggestion_bool = false;
		}

	// florence
	Tableau<std::string> suggestion_florence = membres[4].suggestion(membres); 
	if(suggestion_florence.taille() != 7){
		std::cout << " ==> ECHEC Nombre de suggestions florence" << std::endl;
		suggestion_bool = false;
	}
	std::string tab_3 [] = {"altered carbon", "archive 81", "audible", "brand new cherry flavor", "fistful of vengeance", "izombie", "the woman in the window"};
	for(std::string s : tab_3)
		if(suggestion_florence.occurrence(s) != 1) {
			std::cout << " ==> ECHEC suggestion manquante florence : " << s << std::endl;
			suggestion_bool = false;
		}

	if(suggestion_bool)
			std::cout << " ==> OK" << std::endl;
	return suggestion_bool ? 0 : 1;
}

