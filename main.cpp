#include <iostream>
#include <cstdlib>
#include <thread>
#include "Magasin.h"

int main() { // on déclare les variables dont nous avons besoin
	Magasin EasyStore;
	int menup, menu2, menu3;
	std::string q;

	do{ // Permet d'afficher le menu de départ en boucle tant que l'utilisateur n'appuie pas sur 0 pour quitter le programme
	system("clear");
	std::cout << "------------------------- MENU DU MAGASIN -------------------------" << std::endl; // Architecture du menu
	std::cout << "\n 1°) Gestion du Magasin" << std::endl;
	std::cout << "\n 0°) Quitter" << std::endl;
	std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
	std::cin >> menup;
	switch(menup) { // Switch pour les choix dans le menu ici une fois que l'user a tapé 1
    case 1:
    {	
    	do{ // Vu que l'user a rentré 1 on clear l'affichage et on affiche le menu de gestion du magasin
    	system("clear");
        std::cout << "------------------------- GESTION DU MAGASIN -------------------------" << std::endl;
		std::cout << "\n 1°) Produits" << std::endl;
		std::cout << " 2°) Clients" << std::endl;
		std::cout << " 3°) Commandes" << std::endl;
		std::cout << "\n 0°) Retour" << std::endl;
		std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
		std::cin >> menu2;



		switch(menu2) { // Nouveau switch pour le menu de gestion du magasin avec tout les choix à la clé
	    case 1: // Vu que l'user a rentré 1 on clear l'affichage et on affiche le menu de gestion des produits
	    {
	    	system("clear");
	        std::cout << "------------------------- GESTION DES PRODUITS -------------------------" << std::endl;
			std::cout << "\n 1°) Ajouter un produit au magasin" << std::endl;
			std::cout << " 2°) Afficher tous les produits" << std::endl;
			std::cout << " 3°) Afficher un produit en particulier" << std::endl;
			std::cout << " 4°) Changer la quantité d'un produit" << std::endl;
			std::cout << "\n 0°) Retour" << std::endl;
			std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
			std::cin >> menu3;

			switch(menu3) { // Nouveau switch pour l'ajout de produit au magasin 

			case 1:
			{
				system("clear"); // Vu que l'user a rentré 1 on clear l'affichage et on affiche le menu permettant d'ajouter un produit au magasin
				std::cout << "------------------------- AJOUT D'UN PRODUIT -------------------------" << std::endl;
				std::string titre, description;
				int quantite;
				float prix;
				std::cout << "	Nom du produit : 0 --> Annuler" << std::endl;
				std::getline(std::cin, titre);
				std::cout << "\nNom du produit : ";
				std::getline(std::cin, titre);
				if(titre != "0") {
					std::cout << "\nDescription du produit : ";
					std::getline(std::cin, description);
					std::cout << "\nQuantite : ";
					std::cin >> quantite;
					std::cout << "\nPrix : ";
					std::cin >> prix;
					EasyStore.addProduit(titre, description, quantite, prix);
					std::cout << "\n" << titre << " ajouté au stocks ! Quantité : " << quantite << std::endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(2000));
				}
			}
				break;

			case 2: // Vu que l'user a rentré 2 on clear l'affichage et on affiche le menu avec tous les produits disponibles + description + prix
			{
				q = "0";
				system("clear");
				std::cout << "------------------------- PRODUITS DU MAGASIN -------------------------" << std::endl;
				EasyStore.displayProd();
				do{
					std::cout << "Entrez Q pour quitter" << std::endl;
					std::cin >> q;
				}while( q != "Q" && q != "q" );
			}
				break;

			case 3: // Vu que l'user a rentré 3 on clear l'affichage et on affiche le menu d'un produit en particulier avec sa description et son prix
			{
				system("clear");
				std::cout << "------------------------- RECHERCHE D'UN PRODUIT -------------------------" << std::endl;
				q = "0";
				std::string nom;
				std::getline(std::cin, nom);
				std::cout << "\nNom du produit : ";
				std::getline(std::cin, nom);
				std::cout << "\n";
				EasyStore.displayProdFiltre(nom);
				do{
					std::cout << "Entrez Q pour quitter" << std::endl;
					std::cin >> q;
				}while( q != "Q" && q != "q" );
			}
				break;

			case 4: // Vu que l'user a rentré 4 on clear l'affichage et on affiche qui permet de modifier la quantité d'un produit
			{
				system("clear");
				std::cout << "------------------------- QUANTITE D'UN PRODUIT -------------------------" << std::endl;
				std::string n;
				int qtt;
				std::getline(std::cin, n);
				std::cout << "\nNom du produit : ";
				std::getline(std::cin, n);
				std::cout << "\nQuantité : ";
				std::cin >> qtt;
				EasyStore.setQtt(n, qtt);
				std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			}	
				break;

			case 0: // Nous permet de revenir au menu précédent
				break;
			};
		}
			break;

		case 2: // Vu que l'user a rentré 2 on clear l'affichage et on affiche le menu de gestion des clients
		{
			system("clear");
	        std::cout << "------------------------- CLIENTS DU MAGASIN -------------------------" << std::endl;
			std::cout << "\n 1°) Enregistrer un client" << std::endl;
			std::cout << " 2°) Afficher tous les clients" << std::endl;
			std::cout << " 3°) Afficher un client en particulier" << std::endl;
			std::cout << " 4°) Ajouter un article au panier d'un client" << std::endl;
			std::cout << " 5°) Retirer un article du panier d'un client" << std::endl;
			std::cout << " 6°) Changer la quantité d'un article du panier d'un client" << std::endl;
			std::cout << "\n 0°) Retour" << std::endl;
			std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
			std::cin >> menu3;

			switch(menu3) { // Boucle permettant de gérer menu3 càd le menu des clients

				case 1: // Vu que l'user a rentré 1 on clear l'affichage et on affiche le menu permettant d'enregistrer un nouveau client
				{
					system("clear");
					std::cout << "------------------------- NOUVEAU CLIENT -------------------------" << std::endl;
					std::string nom, prenom;
					std::cout << "	Nom du client : 0 --> Annuler" << std::endl;
					std::getline(std::cin, nom);
					std::cout << "\nNom du client : ";
					std::getline(std::cin, nom);
					if(nom != "0") {
						std::cout << "\nPrenom du client : ";
					std::getline(std::cin, prenom);
					EasyStore.addClient(nom, prenom);
					std::cout << "\n" << nom << " " << prenom << " est enregistré comme client !" << std::endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(2000));
					}
				}
					break; // On revient au menu précédent
				

				case 2: // Vu que l'user a rentré 2 on clear l'affichage et on affiche le menu des clients enregistrés
				{
					q = "0";
					std::cout << "------------------------- CLIENTS DU MAGASIN -------------------------" << std::endl;
					system("clear");
					EasyStore.displayClients();
					do{
						std::cout << "Entrez Q pour quitter" << std::endl;
						std::cin >> q;
					}while( q != "Q" && q != "q");
				}
					break;

				case 3: // Vu que l'user a rentré  on clear l'affichage et on affiche le menu de rechcerche d'un client en particulier
				{
					int choix;
					do {
					q = "0";
					system("clear");
					std::cout << "------------------------- RECHERCHE D'UN CLIENT -------------------------" << std::endl;
					std::cout << "\nVoulez chercher un client par son Nom/Prenom ou son ID ?" << std::endl;
					std::cout << "	1°) Par son Nom/Prenom" << std::endl;
					std::cout << "	2°) Par son ID" << std::endl;
					std::cin >> choix;
					switch(choix) { // Le menu propose deux choix, soit par recherche via Nom/Prénom soit par ID
						case 1 : // Vu que l'user a rentré 1 on demande le nom du client et le prénom du client pour le retrouver
						{
							std::string nom, prenom;
							std::getline(std::cin, nom);
							std::cout << "\nNom du client : ";
							std::getline(std::cin, nom);
							std::cout << "\nPrenom du client : ";
							std::getline(std::cin, prenom);
							EasyStore.displayClientFiltre(nom, prenom);
							do{
								std::cout << "Entrez Q pour quitter" << std::endl; // Boucle qui oblige les clients à quitter
								std::cin >> q;
							}while( q != "Q" && q != "q" ); // Pour éviter des erreurs, la condition se valide si on est en minuscule ou en majuscule
						}
							break;

						case 2 : // Vu que l'user a rentré 2 on demande à l'user de rentrer l'id pour trouver le client correspondant
						{
							int id;
							std::cout << "\nID du client : ";
							std::cin >> id;
							EasyStore.displayClientFiltre(id);
							do{
								std::cout << "Entrez Q pour quitter" << std::endl;
								std::cin >> q;
							}while( q != "Q" && q != "q" );
						}
							break;

					};
					}while(choix != 1 && choix != 2) ;
				}
					break;

				case 4: // Vu que l'user a rentré 4 on clear l'affichage et on affiche le menu de gestion du panier des clients
				{
					system("clear");
					std::cout << "------------------------- AJOUTER AU PANIER -------------------------" << std::endl;
					int choix;
					std::cout << "\nTrouver le client par son Nom/Prenom ou son ID ? " << std::endl;
					std::cout << "	1°) Nom/Prenom" << std::endl;
					std::cout << "	2°) ID" << std::endl;
					std::cin >> choix;
					switch(choix) { // Cette boucle permet de proposer à l'user de choisir le client en le recherchant par son Nom/Prénom ou son ID
						case 1 : // Vu que l'user a rentré 1 on demande à l'user de rentré le nom et prénom du client mais aussi l'objet qu'il veut ajouter à son panier et la quantité de cet objet
						{
							std::string nom, prenom, titre;
							int quantite;
							std::getline(std::cin, nom);
							std::cout << "\nNom du client : ";
							std::getline(std::cin, nom);
							std::cout << "\nPrenom du client : ";
							std::getline(std::cin, prenom);
							std::cout << "\nNom du produit à ajouter au panier : ";
							std::getline(std::cin, titre);
							std::cout << "\nQuantité de " << titre << " à ajouter : ";
							std::cin >> quantite;
							EasyStore.addtoPanier(titre, quantite, nom, prenom);
							std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // Temps de latence de 2000ms soit 2s pour faire comme si on s'enregistrait les données et pour la visibilité
						}
							break;

						case 2 : // Vu que l'user a rentré 1 on demande à l'user de saisir l'ID du client concerné puis du produit à ajouter au panier ainsi que la quantité du produit désiré ajoutée au panier
						{
							int id, quantite;
							std::string titre;
							std::cout << "\nID du client : ";
							std::cin >> id;
							std::getline(std::cin, titre);
							std::cout << "\nNom du produit à ajouter au panier : ";
							std::getline(std::cin, titre);
							std::cout << "\nQuantité de " << titre << " à ajouter : ";
							std::cin >> quantite;
							EasyStore.addtoPanier(titre, quantite, id);
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
						}
							break;
					};
				}
					break;

				case 5: // Vu que l'user a rentré 5 on clear l'affichage et on affiche le menu de gestion du panier permettant de retirer un objet du panier
				{
					system("clear");
					std::cout << "------------------------- RETIRER DU PANIER -------------------------" << std::endl;
					std::string titre;
					int choix;
					std::cout << "\nTrouver le client par son Nom/Prenom ou son ID ? " << std::endl;
					std::cout << "	1°) Nom/Prenom" << std::endl;
					std::cout << "	2°) ID" << std::endl;
					std::cin >> choix;
					switch(choix) { // Vu que l'user a rentré 1 on demande à l'user de rentrer le nom et prénom du client mais aussi l'objet qu'il veut retirer de son panier
						case 1 :
						{
							std::string nom, prenom;
							std::getline(std::cin, nom);
							std::cout << "\nNom du client : ";
							std::getline(std::cin, nom);
							std::cout << "\nPrenom du client : ";
							std::getline(std::cin, prenom);		
							std::cout << "Nom du produit à retirer du panier : ";
							std::getline(std::cin, titre);
							EasyStore.deleteProdPanier(titre, nom, prenom);
							std::cout << "\nArticle retiré du panier du client !" << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
						}
							break;

						case 2 :// Vu que l'user a rentré 2 on demande à l'user de rentrer l'id du client mais aussi l'objet qu'il veut retirer de son panier
						{
							int id;
							std::cout << "\nID du client : ";
							std::cin >> id;
							std::getline(std::cin, titre);
							std::cout << "\nNom du produit à retirer du panier : ";
							std::getline(std::cin, titre);
							EasyStore.deleteProdPanier(titre, id);
							std::cout << "\nArticle retiré du panier du client !" << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
						}
							break;
					};
				}
					break;

				case 6: // Vu que l'user a rentré 6 on clear l'affichage et on affiche le menu de gestion du panier permettant de modifier la quantité d'un objet du panier
				{
					system("clear");
					std::cout << "------------------------- QUANTITE DU PANIER -------------------------" << std::endl;
					int choix;
					std::cout << "\nTrouver le client par son Nom/Prenom ou son ID ? " << std::endl;
					std::cout << "	1°) Nom/Prenom" << std::endl;
					std::cout << "	2°) ID" << std::endl;
					std::cin >> choix;
					switch(choix) { // Cette boucle permet de proposer à l'user de choisir le client en le recherchant par son Nom/Prénom ou son ID
						case 1 : // Vu que l'user a rentré 1 on demande à l'user de rentrer le nom et prénom du client mais aussi l'objet dont il souhaite modifier la quantité ainsi que la nouvelle quantité indiquée
						{
							std::string nom, prenom, titre;
							int quantite;
							std::getline(std::cin, nom);
							std::cout << "\nNom du client : ";
							std::getline(std::cin, nom);
							std::cout << "\nPrenom du client : ";
							std::getline(std::cin, prenom);
							std::cout << "\nDe quel produit souhaitez vous modifier la quantite au panier : ";
							std::getline(std::cin, titre);
							std::cout << "\nCombien en voulez-vous : ";
							std::cin >> quantite;
							EasyStore.changeQttPanier(titre, quantite, nom, prenom);
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
						}
							break;

						case 2 :// Vu que l'user a rentré 2 on demande à l'user de rentrer l'id du client mais aussi l'objet dont il souhaite modifier la quantité ainsi que la nouvelle quantité indiquée
						{
							int id, quantite;
							std::string titre;
							std::cout << "\nID du client : ";
							std::cin >> id;
							std::getline(std::cin, titre);
							std::cout << "\nDe quel produit souhaitez vous modifier la quantite au panier : ";
							std::getline(std::cin, titre);
							std::cout << "\nCombien en voulez-vous : ";
							std::cin >> quantite;
							EasyStore.changeQttPanier(titre, quantite, id);
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
						}
							break;
					};
				}
					break;

				case 0:{ // Vu que l'user a rentré 0 on retourne ua menu précédent
					break;
			};
		}
			break;

		case 3: // Vu que l'user a rentré 3 on clear l'affichage et on arrive dans le menu de gestion des commandes du magasin
		{
			system("clear");
	        std::cout << "------------------------- COMMANDES DU MAGASIN -------------------------" << std::endl;
			std::cout << "\n 1°) Créer une commande" << std::endl;
			std::cout << " 2°) Valider une commande" << std::endl;
			std::cout << " 3°) Afficher toutes les commandes" << std::endl;
			std::cout << " 4°) Afficher une commande en particulier" << std::endl;
			std::cout << "\n 0°) Retour" << std::endl;
			std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
			std::cin >> menu3;

			switch(menu3) { // Cette boucle permet de proposer à l'user de sélectionner les différentes possibilités du menu Commande

				case 1: // Vu que l'user a rentré 1 on clear l'affichage et on demande à l'user de rentrer le nom et prénom du client ou l'id d'un client afin de créer une nouvelle commande pour ce client
				{
					system("clear");
					std::cout << "------------------------- NOUVELLE COMMANDE -------------------------" << std::endl;
					int choix;
					std::cout << "Sélectionnez la méthode pour créer la commande ?" << std::endl;
					std::cout << "	1°) Nom/Prenom" << std::endl;
					std::cout << "	2°) ID" << std::endl;
					std::cout << "\n	0°) Quitter" << std::endl;
					std::cin >> choix;
					switch(choix) { // Cette boucle permet de proposer à l'user de sélectionner entre deux possibilités, soit en entrant le Nom et Prénom du client ou alors son ID
						case 1 : // Vu que l'user a rentré 1 on demande de rentrer le nom et prénom d'un client et ainsi de créer sa commande
						{
							std::string nom, prenom;
							std::getline(std::cin, nom);
							std::cout << "\nNom du client : ";
							std::getline(std::cin, nom);
							std::cout << "\nPrenom du client : ";
							std::getline(std::cin, prenom);
							EasyStore.creerCommande(nom, prenom);
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
						}
							break;

						case 2 : // Vu que l'user a rentré 2 on demande de rentrer l'id d'un client et ainsi de créer sa commande
						{
							int id;
							std::cout << "\nID du client : ";
							std::cin >> id;
							EasyStore.creerCommande(id);
							std::cout << "\nCommande passée et panier vidé !" << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
						}
							break;

						case 0 :
							break;
					};
				}
					break;

				case 2:// Vu que l'user a rentré 2 on lui demande le numéro de commande mais aussi s'il veut valider cette commande
				{
					system("clear");
					std::cout << "------------------------- VALIDATION DE COMMANDE -------------------------" << std::endl;
					int num;
					std::string ch;
					std::cout <<  "Numéro de la commande : ";
					std::cin >> num;
					EasyStore.displayCommandeNum(num);
					std::cout << "\nVoulez vous valider cette commande ? Oui -> O ; Non -> Autres" << std::endl;
					std::cin >> ch;
					if( ch == "O") {
						EasyStore.validerCommande(num);
						std::cout << "\nCommande n°" << num << " validée !" << std::endl;
						std::this_thread::sleep_for(std::chrono::milliseconds(2000));
					}
				}
					break;

				case 3: // Vu que l'user a rentré 3 on clear l'affichage et on affiche toutes les commandes ainsi que leurs statuts
				{
					q = "0";
					system("clear");
					std::cout << "------------------------- COMMANDES DU MAGASIN -------------------------" << std::endl;
					EasyStore.displayCommandes();
					do{
						std::cout << "Entrez Q pour quitter" << std::endl;
						std::cin >> q;
					}while( q != "Q" && q != "q" );
				}

					break;

				case 4: // Vu que l'user a rentré 4 on clear l'affichage et on va lancer un autre do while
				{
					int choix;
					do {
					q = "0";
					system("clear");
					std::cout << "------------------------- RECHERCHE D'UNE COMMANDE -------------------------" << std::endl;
					std::cout << "\nVoulez chercher la commande d'un client par son Nom/Prenom, son ID ou le N° de la commande ?" << std::endl;
					std::cout << "	1°) Par son Nom/Prenom" << std::endl;
					std::cout << "	2°) Par son ID" << std::endl;
					std::cout << "	3°) Par son N° de commande" << std::endl;
					std::cin >> choix;
					switch(choix) { // Cette boucle permet de demander à l'user s'il veut procéder à la recherche d'une commande avec son Nom/Prénom, son ID ou son N° de commande
						case 1 : // Recherche d'une commande par Nom et Prénom
						{
							std::string nom, prenom;
							std::getline(std::cin, nom);
							std::cout << "\nNom du client : ";
							std::getline(std::cin, nom);
							std::cout << "\nPrenom du client : ";
							std::getline(std::cin, prenom);
							EasyStore.displayCommandesFiltre(nom, prenom);
							do{
								std::cout << "Entrez Q pour quitter" << std::endl;
								std::cin >> q;
							}while( q != "Q" && q != "q" );
						}
							break;

						case 2 : // recherche d'une commande par ID
						{
							int id;
							std::cout << "ID du client : ";
							std::cin >> id;
							EasyStore.displayCommandesFiltre(id);
							do{
								std::cout << "Entrez Q pour quitter" << std::endl;
								std::cin >> q;
							}while( q != "Q" && q != "q" );
						}
							break;

						case 3 : // Recherche d'une commande par Numéro de commande
						{
							int num;
							std::cout << "\nNuméro de la commande : ";
							std::cin >> num;
							EasyStore.displayCommandeNum(num);
							do{
								std::cout << "Entrez Q pour quitter" << std::endl;
								std::cin >> q;
							}while( q != "Q" && q != "q" );
						}
							break;

					};
					}while(choix != 1 && choix != 2 && choix != 3) ;
				}
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

	case 0: // On clear l'affichage et on arrête le switch
	{
		system("clear");
	}
		break;
	
	};

	}while(menup != 0);

	return 0; // Ferme la fenêtre pour l'affichage
}
