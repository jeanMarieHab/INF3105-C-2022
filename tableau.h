/** 
 * Squelette pour classe générique Tableau<T>.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105-40 - Structures de données et algorithmes (Automne 2022)
 *
 * Jean Marie HABWINTAHE - HABJ15017805
 * Jabes ADASZ - ADAJ14048000
 *
 */

#if !defined(_TABLEAU___H_)
#define _TABLEAU___H_

#include <assert.h>

template<class T>
class Tableau {

public:
    Tableau(int capacite_initiale = 4);

    Tableau(const Tableau &autre);

    ~Tableau();

    void redimensionner(int nouvCapacite);

    /**
       * description:  ajoute un élément à la fin.
       *
       * @param  			 une référence vers un paramètre de type T.
       */
    void ajouter(const T &element);

    /**
     * description:  retourne le nombre d'éléments dans le
     * 							 tableau. Cette fonction ne doit pas modifier
     * 							 le tableau courant.
     *
     * @return       un entier représentant la taille du tableau
     *               courant.
     */
    int taille() const;

    /**
     * description:  insère un élément à la position 'index'. Les
     * 							 éléments à partir de index sont décalés d'une
     * 							 postion vers la droite.
     *
     * @param        - une référence vers un paramètre de type T.
     * 							 - un entier représentant la position où sera
     * 							 inséré l'élément.
     */
    void inserer(const T &element, int index = 0);

    /**
     * description:  enlève un élément à la position 'index'. Les
     * 							 éléments après index sont décalés d'une postion
     * 							 vers la gauche.
     *
     * @param        un entier représentant la position d'où sera
     * 						 	 enlevé l'élément.
     */
    void enlever(int index = 0);

    /**
     * description:  compte le nombre d'occurrence d'un élément dans
     * 							 le tableau. Cette fonction ne doit pas modifier
     * 							 le tableau courant.
     *
     * @param        une référence vers un paramètre de type T.
     *
     * @return       un entier représentant le nombre de fois que
     * 							 l'élément apparaît dans le tableau courant.
     */
    int occurrence(const T &element) const;

    /**
     * description:  vide le tableau sans libérer la mémoire.
     */
    void vider();

    /**
    * description:   élimine tous les doublants dans le tableau
    * 							 courant.
    */
    void unique();

    /**
     * description:  surcharge des opérateurs
     * 									- d'accès []
     * 									- d'accès et de mondification []
     * 									- d'égalité ==
     * 									- d'affectation de tableau =
     */
    const T &operator[](int index) const;

    T &operator[](int index);

    bool operator==(const Tableau<T> &autre) const;

    Tableau<T> &operator=(const Tableau<T> &autre);

private:
    T *elements;
    int nbElements;
    int capacite;

    /**
     * description:  surcharge de l'opérateur d'affichage <<. Cet
     * 							 opérateur permettra d'afficher, sur une ligne,
     * 							 les éléments d'un tableau séparé par un
     * 							 point-virgule (;).
     */
    template<typename U>
    friend std::ostream &operator<<(std::ostream &, const Tableau<U> &);
};

template<class T>
Tableau<T>::Tableau(int capacite_initiale) {
    capacite = capacite_initiale;
    nbElements = 0;
    elements = new T[capacite];
}

template<class T>
Tableau<T>::Tableau(const Tableau &autre) {
    capacite = autre.capacite;
    nbElements = autre.nbElements;
    elements = new T[capacite];

    for (int i = 0; i < nbElements; i++) {
        elements[i] = autre.elements[i];
    }
}

template<class T>
Tableau<T>::~Tableau() {
    delete[] elements;
    elements = nullptr;
}

template<class T>
void Tableau<T>::vider() {

    nbElements = 0;
    int *a = NULL;
    a = new T[capacite];

    for (int i = 0; i < capacite; i++) {
        a[i] = 0;
    }

    delete[] a;
    a = NULL;

}

template<class T>
void Tableau<T>::redimensionner(int nouvCapacite) {
    capacite = nouvCapacite;
    T *temp = new T[capacite];
    for (int i = 0; i < nbElements; ++i) {
        temp[i] = elements[i];
    }
    delete[] elements;
    elements = temp;
}

template<class T>
int Tableau<T>::taille() const {
    return nbElements;
}

template<class T>
void Tableau<T>::ajouter(const T &item) {
    assert(nbElements <= capacite);
    if (nbElements == capacite) {
        redimensionner(capacite * 2);
    }
    elements[nbElements++] = item;
}

template<class T>
void Tableau<T>::inserer(const T &element, int index) {
    if (nbElements == capacite) {
        redimensionner(capacite * 2);
    }
    for (int i = nbElements; i > index; --i) {
        elements[i] = elements[i - 1];
    }
    elements[index] = element;
    nbElements++;
}

template<class T>
void Tableau<T>::enlever(int index) {
    nbElements--;
    for (int i = index; i < nbElements; ++i) {
        elements[i] = elements[i + 1];
    }
}

template<class T>
int Tableau<T>::occurrence(const T &element) const {
    int counter = 0;

    for (int i = 0; i < nbElements; i++) {
        if (element == elements[i]) {
            counter++;
        }
    }
    return counter;
}

template<class T>
void Tableau<T>::unique() {
    for (int i = 0; i < nbElements; i++) {
        for (int j = i + 1; j < nbElements; j++) {
            if (elements[i] == elements[j]) {
                for (int k = j; k < nbElements - 1; k++) {
                    elements[k] = elements[k + 1];
                }
                nbElements--;
                j--;
            }
        }
    }
}

template<class T>
const T &Tableau<T>::operator[](int index) const {
    assert(index < nbElements);
    return elements[index];
}

template<class T>
T &Tableau<T>::operator[](int index) {
    assert(index < nbElements);
    return elements[index];
}

template<class T>
Tableau<T> &Tableau<T>::operator=(const Tableau<T> &autre) {
    if (this == &autre) {
        return *this;
    }

    nbElements = autre.nbElements;
    if (capacite < autre.nbElements) {
        delete[] elements;
        capacite = autre.nbElements;
        elements = new T[capacite];
    }

    for (int i = 0; i < nbElements; i++) {
        elements[i] = autre.elements[i];
    }
    return *this;
}

template<class T>
bool Tableau<T>::operator==(const Tableau<T> &autre) const {
    if (this == &autre) {
        return true;
    }
    if (nbElements != autre.nbElements) {
        return false;
    }
    for (int i = 0; i < nbElements; i++) {
        if (elements[i] != autre.elements[i]) {
            return false;
        }
        return true;
    }
}

template<typename U>
std::ostream &operator<<(std::ostream &os, const Tableau<U> &tab) {
    for (int i = 0; i < tab.nbElements; ++i) {
        if (i < tab.nbElements - 1) {
            os << tab.elements[i] << ";";
        } else
            os << tab.elements[i] << std::endl;
    }
    return os;

}

#endif