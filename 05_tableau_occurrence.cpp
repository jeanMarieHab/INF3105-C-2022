/**
 * Tests unitaires pour Tableau<T>.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Automne 2022)
 */

#include <iostream>
#include "tableau.h"

bool test1(){
    std::cout << "Occurrencess simples" << std::endl;
    Tableau<int> t;
    t.ajouter(3);
    t.ajouter(1);
    t.ajouter(7);
    t.ajouter(-2);
    t.ajouter(10);
    t.ajouter(3);
    t.ajouter(-1);
    t.ajouter(7);
    t.ajouter(3);
    bool reussi = true;
    if(t.occurrence(3) != 3){
        std::cout << " ==> ECHEC t.occurrence(3) != 3" << std::endl;
        reussi=false;
    }
		if(t.occurrence(7) != 2){
        std::cout << " ==> ECHEC t.occurrence(7) != 2" << std::endl;
        reussi=false;
    }
		if(t.occurrence(10) != 1){
        std::cout << " ==> ECHEC t.occurrence(10) != 1" << std::endl;
        reussi=false;
    }	
		if(t.occurrence(-1) != 1){
        std::cout << " ==> ECHEC t.occurrence(-1) != 1" << std::endl;
        reussi=false;
    }
		if(t.occurrence(13) != 0){
        std::cout << " ==> ECHEC t.occurrence(13) != 0" << std::endl;
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
		int j = 0;
    for(int i = 0; i < n; i++){
				t.ajouter(j);
				j = i % 3105;
		}
    for(int i = 0; i < 3105; i++){
				if(i == 0 && t.occurrence(i) != 44){
						std::cout << " ==> ECHEC t.occurrence(" << i << ") != " << 44 << std::endl;
						reussi=false;
    		}
				if(1 <= i && i <= 660 && t.occurrence(i) != 43){
						std::cout << " ==> ECHEC t.occurrence(" << i << ") != " << 43 << std::endl;
						reussi=false;
    		}
				if(661 <= i && i <= 3104 && t.occurrence(i) != 42){
						std::cout << " ==> ECHEC t.occurrence(" << i << ") != " << 42 << std::endl;
						reussi=false;
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
