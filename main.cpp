#include <iostream>
#include <cstdlib>
#include <thread>
#include "Magasin.h"

int main() {
	Magasin EasyStore;
	int menup, menu2, menu3;
	std::string q;

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
    {	
    	do{
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
	    {
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
				std::getline(std::cin, titre);
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
				std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			}
				break;

			case 2:
			{
				q = "0";
				system("clear");
				EasyStore.displayProd();
				do{
					std::cout << "Entrez Q (en majuscule svp) pour quitter" << std::endl;
					std::cin >> q;
				}while( q != "Q" );
			}
				break;

			case 3:
			{
				system("clear");
				q = "0";
				std::string nom;
				std::getline(std::cin, nom);
				std::cout << "Nom du produit : ";
				std::getline(std::cin, nom);
				EasyStore.displayProdFiltre(nom);
				do{
					std::cout << "Entrez Q (en majuscule svp) pour quitter" << std::endl;
					std::cin >> q;
				}while( q != "Q" && q != "q" );
			}
				break;

			case 4:
			{
				system("clear");
				std::string n;
				int qtt;
				std::getline(std::cin, n);
				std::cout << "Nom du produit : ";
				std::getline(std::cin, n);
				std::cout << "Quantité : ";
				std::cin >> qtt;
				EasyStore.setQtt(n, qtt);
				std::cout << "Quantité de " << n << " modifiée à " << qtt << " !" << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			}	
				break;

			case 0:
				break;
			};
		}
			break;

		case 2:
		{
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
				{
					system("clear");
					std::string nom, prenom;
					std::getline(std::cin, nom);
					std::cout << "Nom du client : ";
					std::getline(std::cin, nom);
					std::cout << "\nPrenom du client : ";
					std::getline(std::cin, prenom);
					EasyStore.addClient(nom, prenom);
					std::cout << "\nClient enregistré !" << std::endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(2000));
				}
					break;
				

				case 2:
				{
					q = "0";
					system("clear");
					EasyStore.displayClients();
					do{
						std::cout << "Entrez Q (en majuscule svp) pour quitter" << std::endl;
						std::cin >> q;
					}while( q != "Q" );
				}
					break;

				case 3:
				{
					q = "0";
					int choix;
					do {
					system("clear");
					std::cout << "Voulez chercher un client par son Nom/Prenom ou son ID ?" << std::endl;
					std::cout << "	1°) Par son Nom/Prenom" << std::endl;
					std::cout << "	2°) Par son ID" << std::endl;
					std::cin >> choix;
					switch(choix) {
						case 1 :
						{
							std::string nom, prenom;
							std::getline(std::cin, nom);
							std::cout << "\nNom du client : ";
							std::getline(std::cin, nom);
							std::cout << "\nPrenom du client : ";
							std::getline(std::cin, prenom);
							EasyStore.displayClientFiltre(nom, prenom);
							do{
								std::cout << "Entrez Q (en majuscule svp) pour quitter" << std::endl;
								std::cin >> q;
							}while( q != "Q" && q != "q" );
						}
							break;

						case 2 :
						{
							int id;
							std::cout << "ID du client : ";
							std::cin >> id;
							EasyStore.displayClientFiltre(id);
							do{
								std::cout << "Entrez Q (en majuscule svp) pour quitter" << std::endl;
								std::cin >> q;
							}while( q != "Q" && q != "q" );
						}
							break;

					};
					}while(choix != 1 && choix != 2) ;
				}
					break;

				case 4:
				{
					system("clear");
					std::string titre;
					int choix;
					std::getline(std::cin, titre);
					std::cout << "Nom du produit à ajouter au panier : ";
					std::getline(std::cin, titre);
					std::cout << "\nTrouver le client par son Nom/Prenom ou son ID ? " << std::endl;
					std::cout << "	1°) Nom/Prenom" << std::endl;
					std::cout << "	2°) ID" << std::endl;
					std::cin >> choix;
					switch(choix) {
						case 1 :
						{
							std::string nom, prenom;
							std::getline(std::cin, nom);
							std::cout << "Nom du client : ";
							std::getline(std::cin, nom);
							std::cout << "Prenom du client : ";
							std::getline(std::cin, prenom);
							EasyStore.addtoPanier(titre, nom, prenom);
							std::cout << "\nArticle ajouté au panier du client !" << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
						}
							break;

						case 2 :
						{
							int id;
							std::cout << "ID du client : ";
							std::cin >> id;
							EasyStore.addtoPanier(titre, id);
							std::cout << "\nArticle ajouté au panier du client !" << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
						}
							break;
					};
				}
					break;

				case 5:
				{
					system("clear");
					std::string titre;
					int choix;
					std::getline(std::cin, titre);
					std::cout << "Nom du produit à retirer du panier: ";
					std::getline(std::cin, titre);
					std::cout << "\nTrouver le client par son Nom/Prenom ou son ID ? " << std::endl;
					std::cout << "	1°) Nom/Prenom" << std::endl;
					std::cout << "	2°) ID" << std::endl;
					std::cin >> choix;
					switch(choix) {
						case 1 :
						{
							std::string nom, prenom;
							std::getline(std::cin, nom);
							std::cout << "\nNom du client : ";
							std::getline(std::cin, nom);
							std::cout << "\nPrenom du client : ";
							std::getline(std::cin, prenom);
							EasyStore.deleteProdPanier(titre, nom, prenom);
							std::cout << "\nArticle retiré du panier du client !" << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
						}
							break;

						case 2 :
						{
							int id;
							std::cout << "ID du client : ";
							std::cin >> id;
							EasyStore.deleteProdPanier(titre, id);
							std::cout << "\nArticle retiré du panier du client !" << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
						}
							break;
					};
				}
					break;


				case 6:
				{
					system("clear");
					std::string titre;
					int choix, quantite;
					std::getline(std::cin, titre);
					std::cout << "De quel produit souhaitez vous modifier la quantite au panier : ";
					std::getline(std::cin, titre);
					std::cout << "\nCombien en voulez-vous : ";
					std::cin >> quantite;
					std::cout << "\nTrouver le client par son Nom/Prenom ou son ID ? " << std::endl;
					std::cout << "	1°) Nom/Prenom" << std::endl;
					std::cout << "	2°) ID" << std::endl;
					std::cin >> choix;
					switch(choix) {
						case 1 :
						{
							std::string nom, prenom;
							std::getline(std::cin, nom);
							std::cout << "\nNom du client : ";
							std::getline(std::cin, nom);
							std::cout << "\nPrenom du client : ";
							std::getline(std::cin, prenom);
							EasyStore.changeQttPanier(titre, quantite, nom, prenom);
							std::cout << "\nQuantité de l'article du panier du client modifié !" << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
						}
							break;

						case 2 :
						{
							int id;
							std::cout << "ID du client : ";
							std::cin >> id;
							EasyStore.changeQttPanier(titre, quantite, id);
							std::cout << "\nQuantité de l'article du panier du client modifié !" << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
						}
							break;
					};
				}
					break;

				case 0:{
				}
					break;
			};
		}
			break;

		case 3:
		{
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
		}

		case 0:
			break;
		};
		}while(menu2 != 0);
	}
		break;

    case 2:
    {
    	system("clear");
        std::cout << "-------------------- GESTION DES UTILISATEURS --------------------" << std::endl;
		std::cout << "\n 1°) Ajouter un article au panier d'un client" << std::endl;
		std::cout << " 2°) Vider le panier d'un client" << std::endl;
		std::cout << " 3°) Changer la quantité d'un article du panier d'un client" << std::endl;
		std::cout << " 4°) Supprimer un article du panier d'un client" << std::endl;
		std::cout << "\n 0°) Retour" << std::endl;
		std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
		std::cin >> menu2;
    }
		break;

	case 3:
	{
		system("clear");
        std::cout << "-------------------- GESTION DES COMMANDES --------------------" << std::endl;
		std::cout << "\n 1°) Changer l'etat d'une commande" << std::endl;
		std::cout << "\n 0°) Quitter" << std::endl;
		std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
		std::cin >> menu2;
	}
		break;

	case 0:
	{
		system("clear");
	}
		break;
	
	};

	}while(menup != 0);

	return 0;
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
}
