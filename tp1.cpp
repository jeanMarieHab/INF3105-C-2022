/** 
 * Programme principal pour utiliser la classe Membre.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Automne 2022)
 */


#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include "membre.h"
#include "extraction.h"


/**
 * La fonction main est le point d'entrée. En principe, vous n'avez pas à modifier.
 * 		argc = nombre d'arguments (le premier implicite étant l'exécutable) 
 * 		argv = tableau de chaines de caractères poitnant vers les arguments
 */
int main(int argc, char** argv) {
	// Il faut minimalement fournir un nom de fichier à lire
	if(argc < 2) {
		cerr << "Vous devez fournir un nom de fichier !" << endl; 
		return 1;
	}
	Tableau<Membre> membres = extraire(argv[1]);
	int i = 0;
	// Cas d'exécution avec un unique nom de membre
	if(argc == 3)
		while(i < membres.taille()) {
			if(argv[2] == membres[i].identifiant()) {
				Tableau<string> tab = membres[i].suggestion(membres);
				cout << tab << endl;
				break;
			}
			i++;
		}
	// Cas d'exécution avec deux noms de membres
	if(argc == 4) {
		Membre un,  deux;
		for(i = 0; i < membres.taille(); i++) {
			if(argv[2] == membres[i].identifiant())
				un = membres[i];
			if(argv[3] == membres[i].identifiant())
				deux = membres[i];
		}
		Tableau<string> tab = un.suggestion(deux);
		cout << tab << endl;
	}
	return 0;
}

