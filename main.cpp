#include <iostream>
#include "Magasin.h"

int main() {
	//Création du Magasin vide
	Magasin EasyStore;

	//Création des produits et leurs pointeurs
	Produit prod1;
	Produit prod2("Xbox", "Console de Jeu", 1, 299.99);
	Produit *p1 = &prod1;
	Produit *p2 = &prod2;

	//Vérification de l'allocution
	std::cout << *p1 << std::endl;
	std::cout << "\n" << std::endl;

	//Test de la fonction addProduit()
	EasyStore.addProduit(p1);
	EasyStore.addProduit(p2);
	EasyStore.display();
	std::cout << "\n" << std::endl;

	//Test de la fonction displayFiltre()
	EasyStore.addProduit(p2);
	EasyStore.displayFiltre("Switch");
	std::cout << "\n" << std::endl;

return 0;
}