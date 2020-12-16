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
	std::cout << *p1 << "\n" << std::endl;

	//Test de la fonction addProduit()
	EasyStore.addProduit(p1);
	EasyStore.addProduit(p2);
	EasyStore.display();

	//Test de la fonction displayFiltre()
	EasyStore.displayFiltre("PS5");
	
	//Test de la fonction setQtt()
	EasyStore.setQtt(5, "Xbox");
	EasyStore.display();

return 0;
}