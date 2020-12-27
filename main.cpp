#include <iostream>
#include "Magasin.h"

int main() {
	// --- PARTIE I ---

		// Question 1
	//Création du Magasin vide
	Magasin EasyStore;


		// Question 2
	//Création des produits et leurs pointeurs
/*	Produit prod1;
	Produit prod2("Xbox", "Console de Jeu", 1, 299.99);
	Produit *p1 = &prod1;
	Produit *p2 = &prod2;


	//Vérification de l'allocution
	std::cout << *p1 << "\n" << std::endl;
*/

		// Question 3
	//Test de la fonction addProduit()
	EasyStore.addProduit("Xbox", "Console de Jeu", 1, 299.99);
	EasyStore.addProduit("PS5", "Console de Jeu", 2, 499.99);
	//EasyStore.displayProd();

	//Test de la fonction displayFiltre()
	//EasyStore.displayProdFiltre("PS5");
	
	//Test de la fonction setQtt()
	//EasyStore.setQtt("Xbox", 5);
	//EasyStore.displayProd();


		// Question 4
	//Test Création Client
	Client client1("Ledoux", "Paul", 1);
	Client client2;
	Client *c1 = &client1;
	Client *c2 = &client2;


	//Vérification de l'allocution
	std::cout << *c1 << std::endl;
	std::cout << *c2 << "\n" << std::endl;

	//Test addtoCart()
//	c1->addtoCart("Xbox");
//	std::cout << *c1 << std::endl;
/*
	//Test clearCart()
	c1->clearCart();
	std::cout << *c1 << std::endl;

	//Test changeQuantity()
	c1->addtoCart(p2);
	std::cout << *c1 << std::endl;
	c1->changeQuantity("Xbox", 3);
	std::cout << *c1 << std::endl;


		// Question 5
	EasyStore.addClient("Lefaivre", "Remi");
	EasyStore.displayClients();

	EasyStore.addClient("Ping", "Pong");
	EasyStore.displayClientFiltre("Ping", "Pong");
	EasyStore.displayClientFiltre(1);
*/

return 0;
}