/** 
 * Utilitaire pour l'extraction des membres à partir d'un fichier.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Automne 2022)
 */

Tableau<Membre> extraire(const char * fichier);

Tableau<Membre> extraire(const char * fichier) {
	std::ifstream etat(fichier);
	std::string ligne;
	char delimiter = ';';
	Tableau<Membre> membres;
	while(std::getline(etat, ligne)) {
		std::string token;
		std::stringstream tokenStream(ligne);
		std::getline(tokenStream, token, delimiter);
		Membre membre(token);
		while(std::getline(tokenStream, token, delimiter))
			membre.ajouterFavori(token);
		membres.ajouter(membre);
	}
	return membres;
}
