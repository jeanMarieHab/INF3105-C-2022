/**
 * Tests unitaires pour Tableau<T>.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Automne 2022)
 */

#include <iostream>
#include "tableau.h"

bool test1(){
    std::cout << "Unicité simple" << std::endl;
    Tableau<int> t;
    t.ajouter(3);
    t.ajouter(4);
    t.ajouter(4);
    t.ajouter(2);
    t.ajouter(1);
    t.ajouter(0);
    t.ajouter(0);
    t.ajouter(3);
    t.ajouter(5);
    t.ajouter(-2);
    t.ajouter(-1);
    bool reussi = true;
    if(t.taille() != 11){
        std::cout << " ==> ECHEC Taille" << std::endl;
        reussi=false;
    }
		t.unique();
    if(t.taille() != 8){
        std::cout << " ==> ECHEC Taille" << std::endl;
        reussi=false;
    }
		if(t.occurrence(3) != 1){
        std::cout << " ==> ECHEC t.occurrence(3) != 1" << std::endl;
        reussi=false;
    }
		if(t.occurrence(4) != 1){
        std::cout << " ==> ECHEC t.occurrence(4) != 1" << std::endl;
        reussi=false;
    }
		if(t.occurrence(0) != 1){
        std::cout << " ==> ECHEC t.occurrence(0) != 1" << std::endl;
        reussi=false;
    }
		if(t.occurrence(-1) != 1){
        std::cout << " ==> ECHEC t.occurrence(-1) != 1" << std::endl;
        reussi=false;
    }

    if(reussi)
        std::cout << " ==> OK" << std::endl;
    return reussi;
}

bool test2(){
    bool reussi = true;
    Tableau<int> t;
    int n = 10000;
		int j = 0;
		int dix = 0;
    for(int i = 0; i < n; i++) {
        t.ajouter(j);
				dix++;
				if(dix == 10) {
					j++;
					dix = 0;
				}
		}
		t.unique();
    if(t.taille() != n / 10){
        std::cout << " ==> ECHEC taille()" << std::endl;
        reussi = false;
    }
    for(int i = 0; i < t.taille(); i++)
        if(t.occurrence(t[i]) != 1){
            std::cout << " ==> ECHEC : t.occurrence(" << t[i] << ") != 1" << std::endl;
            reussi = false;
        }

    if(reussi)
        std::cout << " ==> OK" << std::endl;
    return reussi;
}

int main(){
   	bool testsreussis = true
        && test1()
        && test2()
        ;
		return testsreussis ? 0 : 1;
}
