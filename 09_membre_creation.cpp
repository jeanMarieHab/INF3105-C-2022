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
	std::cout << "Creation membres" << std::endl;
	const char * fichier = "groupe.txt";
	Tableau<Membre> membres = extraire(fichier);
	bool nb_membres = true;
	if(membres.taille() != 5){
		std::cout << " ==> ECHEC Nombre de membres" << std::endl;
		nb_membres = false;
	}
	if(nb_membres)
			std::cout << " ==> OK" << std::endl;
	bool taille_favoris = true;
	for(int i = 0; i < membres.taille(); i++) {
		if(membres[i].identifiant() == "harry" && membres[i].favoris().taille() != 4) {
			std::cout << " ==> ECHEC Taille favoris 'harry'" << std::endl;
			taille_favoris = false;
		}
		if(membres[i].identifiant() == "lula" && membres[i].favoris().taille() != 4) {
			std::cout << " ==> ECHEC Taille favoris 'lula'" << std::endl;
			taille_favoris = false;
		}
		if(membres[i].identifiant() == "alice" && membres[i].favoris().taille() != 4) {
			std::cout << " ==> ECHEC Taille favoris 'alice'" << std::endl;
			taille_favoris = false;
		}
		if(membres[i].identifiant() == "martin" && membres[i].favoris().taille() != 3) {
			std::cout << " ==> ECHEC Taille favoris 'martin'" << std::endl;
			taille_favoris = false;
		}
		if(membres[i].identifiant() == "florence" && membres[i].favoris().taille() != 4) {
			std::cout << " ==> ECHEC Taille favoris 'florence'" << std::endl;
			taille_favoris = false;
		}
	}
	if(taille_favoris)
		std::cout << " ==> OK" << std::endl;
	bool testsreussis = true
			&& nb_membres
			&& taille_favoris
			;
	return testsreussis ? 0 : 1;
}

