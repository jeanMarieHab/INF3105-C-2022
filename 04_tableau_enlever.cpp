/**
 * Tests unitaires pour Tableau<T>.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Automne 2022)
 */

#include <iostream>
#include "tableau.h"

bool test1(){
    std::cout << "Suppressions simples" << std::endl;
    Tableau<int> t;
    t.ajouter(3);
    t.ajouter(1);
    t.ajouter(-2);
    t.ajouter(10);
    t.ajouter(4);
    t.ajouter(-1);
    t.ajouter(7);
    t.ajouter(19);
    bool reussi = true;
		t.enlever();
    if(t[0] != 1){
        std::cout << " ==> ECHEC t[0] != 1" << std::endl;
        reussi=false;
    }
    if(t.taille() != 7){
        std::cout << " ==> ECHEC Taille" << std::endl;
        reussi=false;
    }
		t.enlever();
    if(t[0] != -2){
        std::cout << " ==> ECHEC t[0] != -2" << std::endl;
        reussi=false;
    }
		if(t.taille() != 6){
        std::cout << " ==> ECHEC Taille" << std::endl;
        reussi=false;
    }
		t.enlever();
		t.enlever();
		if(t[3] != 19){
        std::cout << " ==> ECHEC t[3] != 19" << std::endl;
        reussi=false;
    }
		if(t[2] != 7){
        std::cout << " ==> ECHEC t[2] != 7" << std::endl;
        reussi=false;
    }
    if(t.taille() != 4){
        std::cout << " ==> ECHEC Taille" << std::endl;
        reussi=false;
    }
    if(reussi)
        std::cout << " ==> OK" << std::endl;
    return reussi;
}

bool test2(){
    bool reussi = true;
    Tableau<int> t;
    int n = 2 * 256 * 256;
    for(int i = 0; i < n; i++)
				t.ajouter(i * 2);
		int d = 0;
    for(int i = 0; i < t.taille(); i += 10){
				t.enlever(i);
				d++;
		}
		if(t.taille() != n - d){
        std::cout << " ==> ECHEC Taille" << std::endl;
        reussi=false;
    }
		int j = 1;
		int dix = 0;
		for(int i = 0; i < n - d; i++){
				if(t[i] != (i + j) * 2){
						std::cout << " ==> ECHEC t[" << i - j << "] != " << (i + j) * 2 << std::endl;
						reussi=false;
				}
				dix++;
				if(dix == 10){
						j++;
						dix = 0;
				}
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
