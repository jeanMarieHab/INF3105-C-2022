/**
 * Tests unitaires pour Tableau<T>.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Automne 2022)
 */

#include <iostream>
#include "tableau.h"

bool test1(){
    std::cout << "Insertion simple" << std::endl;
    Tableau<int> t;
    t.ajouter(1);
    t.ajouter(2);
    t.ajouter(3);
    t.ajouter(4);
    t.ajouter(5);
    t.ajouter(6);
		t.inserer(-1);
    bool reussi = true;
    if(t[0] != -1){
        std::cout << " ==> ECHEC t[0] != -1" << std::endl;
        reussi=false;
    }
    if(t.taille() != 7){
        std::cout << " ==> ECHEC Taille" << std::endl;
        reussi=false;
    }
		t.inserer(-1, 5);
    if(t[5] != -1){
        std::cout << " ==> ECHEC t[5] != -1" << std::endl;
        reussi=false;
    }
		t.inserer(-1, 3);
    if(t[3] != -1){
        std::cout << " ==> ECHEC t[3] != -1" << std::endl;
        reussi=false;
    }
		t.inserer(-2, 3);
    if(t[3] != -2){
        std::cout << " ==> ECHEC t[3] != -2" << std::endl;
        reussi=false;
    }

    if(reussi)
        std::cout << " ==> OK" << std::endl;
    return reussi;
}

bool test2(){
    bool reussi = true;
    Tableau<int> t;
    int n = 256;
    for(int i = 0; i < n; i++)
        t.inserer(i * 2);
    if(t.taille() != n){
        std::cout << " ==> ECHEC taille()" << std::endl;
        reussi = false;
    }
		for(int i = 0; i < t.taille(); i++)
        if(t[i] != (255 - i)  * 2){
            std::cout << " ==> ECHEC : t[i] = " << t[i] << " != " << ((255 - i) * 2) << std::endl;
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
