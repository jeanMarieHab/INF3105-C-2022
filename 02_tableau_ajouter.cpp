/**
 * Tests unitaires pour Tableau<T>.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Automne 2022)
 */

#include <iostream>
#include "tableau.h"

bool test1(){
    std::cout << "Ajouts simples" << std::endl;
    Tableau<int> t;
    t.ajouter(3);
    t.ajouter(1);
    t.ajouter(-2);
    t.ajouter(10);
    t.ajouter(4);
    t.ajouter(3);
    t.ajouter(3);
    t.ajouter(3);
    bool reussi = true;
    if(t[0] != 3){
        std::cout << " ==> ECHEC t[0] != 3" << std::endl;
        reussi=false;
    }
    if(t[1] != 1){
        std::cout << " ==> ECHEC t[1] != 4" << std::endl;
        reussi=false;
    }
		if(t[3] != 10){
        std::cout << " ==> ECHEC t[1] != 4" << std::endl;
        reussi=false;
    }
		if(t[7] != 3){
        std::cout << " ==> ECHEC t[1] != 4" << std::endl;
        reussi=false;
    }

    if(t.taille() != 8){
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

    if(t.taille() != n){
        std::cout << " ==> ECHEC taille()" << std::endl;
        reussi = false;
    }

    for(int i = 0; i < t.taille(); i++)
        if(t[i] != i * 2){
            std::cout << " ==> ECHEC : t[i] = " << t[i] << " != " << (i * 2) << std::endl;
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
