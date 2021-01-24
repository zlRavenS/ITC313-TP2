#include <iostream>
#include <cstdlib>
#include "Magasin.h"

int main() {
	Magasin EasyStore;
	int menup, menu2, menu3;

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
	do {
    case 1: 
    	system("clear");
        std::cout << "-------------------- GESTION DU MAGASIN --------------------" << std::endl;
		std::cout << "\n 1°) Produits" << std::endl;
		std::cout << " 2°) Clients" << std::endl;
		std::cout << " 3°) Commandes" << std::endl;
		std::cout << "\n 0°) Retour" << std::endl;
		std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
		std::cin >> menu2;



		switch(menu2) {

	    case 1:
	    	system("clear");
	        std::cout << "-------------------- PRODUITS DU MAGASIN --------------------" << std::endl;
			std::cout << "\n 1°) Ajouter un produit au magasin" << std::endl;
			std::cout << " 2°) Afficher tous les produits" << std::endl;
			std::cout << " 3°) Afficher un produit en particulier" << std::endl;
			std::cout << " 4°) Changer la quantité d'un produit" << std::endl;
			std::cout << "\n 0°) Retour" << std::endl;
			std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
			std::cin >> menu3;

			switch(menu3) {

			case 1:
			{
				system("clear");
				std::string titre, description;
				int quantite;
				float prix;
				std::cout << "Nom du produit : ";
				std::getline(std::cin, titre);
				std::cout << "\nDescription du produit : ";
				std::getline(std::cin, description);
				std::cout << "\nQuantite : ";
				std::cin >> quantite;
				std::cout << "\nPrix : ";
				std::cin >> prix;
				EasyStore.addProduit(titre, description, quantite, prix);
				std::cout << "\nProduit ajouté !" << std::endl;
				EasyStore.displayProd();
				system("pause");
			}
				break;

			case 2:
			{
				system("clear");
				EasyStore.displayProd();
				system("pause");
			}
				break;

			case 3:
			{
				system("clear");
				std::string nom;
				std::cout << "Nom du produit : ";
				std::getline(std::cin, nom);
				EasyStore.displayProdFiltre(nom);
				std::cout << "Appuyez sur une touche pour continuer" << std::endl;
				system("pause");
			}
				break;

			case 4:
			{
				system("clear");
				std::string n;
				int qtt;
				std::cout << "Nom du produit : ";
				std::getline(std::cin, n);
				std::cout << "Quantité : ";
				std::cin >> qtt;
				EasyStore.setQtt(n, qtt);
				std::cout << "Quantité de " << n << " modifiée à " << qtt << " !" << std::endl;
				std::cout << "Appuyez sur une touche pour continuer" << std::endl;
				system("pause");
			}	
				break;

			case 0:
				break;
			};
			break;

		case 2:
	    	system("clear");
	        std::cout << "-------------------- CLIENTS DU MAGASIN --------------------" << std::endl;
			std::cout << "\n 1°) Enregistrer un client" << std::endl;
			std::cout << " 2°) Afficher tous les clients" << std::endl;
			std::cout << " 3°) Afficher un client en particulier" << std::endl;
			std::cout << " 4°) Ajouter un article au panier d'un client" << std::endl;
			std::cout << " 5°) Retirer un article du panier d'un client" << std::endl;
			std::cout << " 6°) Changer la quantité d'un article du panier d'un client" << std::endl;
			std::cout << "\n 0°) Retour" << std::endl;
			std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
			std::cin >> menu3;

			switch(menu3) {

				case 1:
					break;

				case 2:
					break;

				case 3:
					break;

				case 4:
					break;

				case 0:
					break;
			};




			break;

		case 3:
	    	system("clear");
	        std::cout << "-------------------- COMMANDES DU MAGASIN --------------------" << std::endl;
			std::cout << "\n 1°) Créer une commande" << std::endl;
			std::cout << " 2°) Valider une commande" << std::endl;
			std::cout << " 3°) Afficher toutes les commandes" << std::endl;
			std::cout << " 4°) Afficher une commande en particulier" << std::endl;
			std::cout << "\n 0°) Retour" << std::endl;
			std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
			std::cin >> menu3;

			switch(menu3) {

				case 1:
					break;

				case 2:
					break;

				case 3:
					break;

				case 4:
					break;

				case 0:
					break;
			};

		case 0:
			break;

		};
		}while(menu2 != 0);

		break;





    case 2:
    	system("clear");
        std::cout << "-------------------- GESTION DES UTILISATEURS --------------------" << std::endl;
		std::cout << "\n 1°) Ajouter un article au panier d'un client" << std::endl;
		std::cout << " 2°) Vider le panier d'un client" << std::endl;
		std::cout << " 3°) Changer la quantité d'un article du panier d'un client" << std::endl;
		std::cout << " 4°) Supprimer un article du panier d'un client" << std::endl;
		std::cout << "\n 0°) Retour" << std::endl;
		std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
		std::cin >> menu2;




		break;

	case 3:
		system("clear");
        std::cout << "-------------------- GESTION DES COMMANDES --------------------" << std::endl;
		std::cout << "\n 1°) Changer l'etat d'une commande" << std::endl;
		std::cout << "\n 0°) Quitter" << std::endl;
		std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
		std::cin >> menu2;




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