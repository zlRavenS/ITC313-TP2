#include <iostream>
#include <cstdlib>
#include "Magasin.h"

int main() {
	Magasin EasyStore;
	int menup, menu;

	do{
	system("clear");
	std::cout << "-------------------- MENU DU MAGASIN --------------------" << std::endl;
	std::cout << "\n 1°) Gestion du Magasin" << std::endl;
	std::cout << " 2°) Gestion des Utilisateurs" << std::endl;
	std::cout << " 3°) Gestion des Commandes" << std::endl;
	std::cout << "\n 0°) Quitter" << std::endl;
	std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
	std::cin >> menup;

	switch(menup) {

    case 1:
    	system("clear");
        std::cout << "-------------------- GESTION DU MAGASIN --------------------" << std::endl;
		std::cout << "\n 1°) Produits" << std::endl;
		std::cout << " 2°) Clients" << std::endl;
		std::cout << " 3°) Commandes" << std::endl;
		std::cout << "\n 0°) Quitter" << std::endl;
		std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
		std::cin >> menu;
		break;

    case 2:
    	system("clear");
        std::cout << "-------------------- GESTION DES UTILISATEURS --------------------" << std::endl;
		std::cout << "\n 1°) Ajouter un article au panier d'un client" << std::endl;
		std::cout << " 2°) Vider le panier d'un client" << std::endl;
		std::cout << " 3°) Changer la quantité d'un article du panier d'un client" << std::endl;
		std::cout << " 4°) Supprimer un article du panier d'un client" << std::endl;
		std::cout << "\n 0°) Quitter" << std::endl;
		std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
		std::cin >> menu;
		break;

	case 3:
		system("clear");
        std::cout << "-------------------- GESTION DES COMMANDES --------------------" << std::endl;
		std::cout << "\n 1°) Changer l'etat d'une commande" << std::endl;
		std::cout << " 2°) Clients" << std::endl;
		std::cout << " 3°) Commandes" << std::endl;
		std::cout << "\n 0°) Quitter" << std::endl;
		std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
		std::cin >> menu;
		break;

	case 0:
		system("clear");
		break;
	}
} while(menup != 0);

/*
		// Question 2
	//Création des produits et leurs pointeurs
	Produit prod1;
//	Produit prod2("Xbox", "Console de Jeu", 1, 299.99);
	Produit *p1 = &prod1;
//	Produit *p2 = &prod2;


	//Vérification de l'allocution
//	std::cout << *p1 << "\n" << std::endl;


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

*/
/*		// Question 4
	//Test Création Client
	Client client1("Ledoux", "Paul", 1);
	Client *c1 = &client1;


	//Vérification de l'allocution
/*	std::cout << *c1 << std::endl;
	std::cout << *c2 << "\n" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
*/

	//Test addtoCart()
/*	std::cout << "-----------------------------------" << std::endl;
	c1->addtoCart(p1);
	c1->addtoCart(p2);
	std::cout << *c1 << std::endl;
	c1->deleteProduit("PS5");
	std::cout << "-----------------------------------" << std::endl;
	std::cout << *c1 << std::endl;
*/

/*	//Test clearCart()
	c1->clearCart();
	std::cout << *c1 << std::endl;

	//Test changeQuantity()
	c1->addtoCart("PS5");
	std::cout << *c1 << std::endl;

	c1->changeQuantity("PS5", 3);
	std::cout << *c1 << std::endl;


/*		// Question 5
	EasyStore.addClient("Lefaivre", "Remi");
	EasyStore.addClient("Ping", "Pong");
//	EasyStore.displayClients();

/*	EasyStore.addClient("Ping", "Pong");
	EasyStore.displayClientFiltre("Ping", "Pong");
	EasyStore.displayClientFiltre(1);
	EasyStore.displayClients();
*/
/*
	EasyStore.addtoPanier("Zelda", 1);

	c1->addtoCart(p1);
/*	std::vector<Produit*> panier1 = c1->getPanier();
	Commande comm1(c1, panier1, 1);
	Commande *com1 = &comm1;
	std::cout << *com1 << std::endl;
*/
/*
	EasyStore.creerCommande(1);
	EasyStore.displayCommandesFiltre("Lefaivre", "Remi");
*/

return 0;
}