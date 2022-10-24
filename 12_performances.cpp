/**
 * Performances des fonctions occurrence et unique.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Automne 2022)
 */

#include <iostream>
#include "tableau.h"


int compteurAcomparaisons = 0;
class A{
  private:
    int x;
  public:
    A(int x_=0) : x(x_) {}
    bool operator < (const A& o) const{ 
       compteurAcomparaisons++;
       return x < o.x;
    }
    bool operator <= (const A& o) const{ 
       compteurAcomparaisons++;
       return x <= o.x;
    }
    bool operator == (const A& o) const{ 
       compteurAcomparaisons++;
       return x == o.x;
    }
    bool operator != (const A& o) const{ 
       compteurAcomparaisons++;
       return x != o.x;
    }

    bool operator >= (const A& o) const{ 
       compteurAcomparaisons++;
       return x >= o.x;
    }
    bool operator > (const A& o) const{ 
       compteurAcomparaisons++;
       return x > o.x;
    }
};

int main(){
    Tableau<A> t;
    int n = 500;
    for(int i = 0; i < n; i++)
        t.inserer(i * 2);
    for(int i = 0; i < n; i++)
        t.inserer(i * 2);
    for(int i = 0; i < n; i++)
        t.inserer(i * 2);

    compteurAcomparaisons = 0;
    for(int i = 0; i < 500; i++){
       int o = t.occurrence(i * 2);
       if(o != 3){
           std::cout << "Erreur occurrence A : " << o << " au lieu de 3 !" << std::endl;
       }
    }
    std::cout << "Nombre d'opérations pour la fonction occurrence : " << compteurAcomparaisons << std::endl;

		compteurAcomparaisons = 0;
		t.unique();
	  if(t.taille() != 500)
    		std::cout << "Erreur unique A (taille) : " << t.taille() << " au lieu de 500 !" << std::endl;
    std::cout << "Nombre d'opérations pour la fonction unique : " << compteurAcomparaisons << std::endl;

    return 0;
}
