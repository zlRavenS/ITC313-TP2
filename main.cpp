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
	std::cout << "------------------------- MENU DU MAGASIN -------------------------" << std::endl;
	std::cout << "\n 1°) Gestion du Magasin" << std::endl;
	std::cout << "\n 0°) Quitter" << std::endl;
	std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
	std::cin >> menup;
	switch(menup) {
    case 1:
    {	
    	do{
    	system("clear");
        std::cout << "------------------------- GESTION DU MAGASIN -------------------------" << std::endl;
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
	        std::cout << "------------------------- GESTION DES PRODUITS -------------------------" << std::endl;
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

			case 2:
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

			case 3:
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

			case 4:
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

			case 0:
				break;
			};
		}
			break;

		case 2:
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

			switch(menu3) {

				case 1:
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
					break;
				

				case 2:
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

				case 3:
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
								std::cout << "Entrez Q pour quitter" << std::endl;
								std::cin >> q;
							}while( q != "Q" && q != "q" );
						}
							break;

						case 2 :
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

				case 4:
				{
					system("clear");
					std::cout << "------------------------- AJOUTER AU PANIER -------------------------" << std::endl;
					int choix;
					std::cout << "\nTrouver le client par son Nom/Prenom ou son ID ? " << std::endl;
					std::cout << "	1°) Nom/Prenom" << std::endl;
					std::cout << "	2°) ID" << std::endl;
					std::cin >> choix;
					switch(choix) {
						case 1 :
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
							EasyStore.addtoPanier(titre, nom, prenom);
							EasyStore.changeQttPanier(titre, quantite, nom, prenom);
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
						}
							break;

						case 2 :
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
							EasyStore.addtoPanier(titre, id);
							EasyStore.changeQttPanier(titre, quantite, id);
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
						}
							break;
					};
				}
					break;

				case 5:
				{
					system("clear");
					std::cout << "------------------------- RETIRER DU PANIER -------------------------" << std::endl;
					std::string titre;
					int choix;
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
							std::cout << "Nom du produit à retirer du panier : ";
							std::getline(std::cin, titre);
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
							std::getline(std::cin, titre);
							std::cout << "Nom du produit à retirer du panier : ";
							std::getline(std::cin, titre);
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
					std::cout << "------------------------- QUANTITE DU PANIER -------------------------" << std::endl;
					int choix;
					std::cout << "\nTrouver le client par son Nom/Prenom ou son ID ? " << std::endl;
					std::cout << "	1°) Nom/Prenom" << std::endl;
					std::cout << "	2°) ID" << std::endl;
					std::cin >> choix;
					switch(choix) {
						case 1 :
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
							std::cout << "\nQuantité de " << titre << " du panier de " << nom << " " << prenom << " modifié à " << quantite << " !" << std::endl;
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
						}
							break;

						case 2 :
						{
							int id, quantite;
							std::string titre;
							std::cout << "\nID du client : ";
							std::cin >> id;
							std::cout << "\nDe quel produit souhaitez vous modifier la quantite au panier : ";
							std::getline(std::cin, titre);
							std::cout << "\nCombien en voulez-vous : ";
							std::cin >> quantite;
							EasyStore.changeQttPanier(titre, quantite, id);
							std::cout << "\nQuantité de " << titre << " du panier du client n°" << id << " modifié à " << quantite << " !" << std::endl;
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
	        std::cout << "------------------------- COMMANDES DU MAGASIN -------------------------" << std::endl;
			std::cout << "\n 1°) Créer une commande" << std::endl;
			std::cout << " 2°) Valider une commande" << std::endl;
			std::cout << " 3°) Afficher toutes les commandes" << std::endl;
			std::cout << " 4°) Afficher une commande en particulier" << std::endl;
			std::cout << "\n 0°) Retour" << std::endl;
			std::cout << "\n   --> Choisissez votre menu en tapant le numéro correspondant" << std::endl;
			std::cin >> menu3;

			switch(menu3) {

				case 1:
				{
					system("clear");
					std::cout << "------------------------- NOUVELLE COMMANDE -------------------------" << std::endl;
					int choix;
					std::cout << "Sélectionnez la méthode pour créer la commande ?" << std::endl;
					std::cout << "	1°) Nom/Prenom" << std::endl;
					std::cout << "	2°) ID" << std::endl;
					std::cout << "\n	0°) Quitter" << std::endl;
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
							EasyStore.creerCommande(nom, prenom);
							std::this_thread::sleep_for(std::chrono::milliseconds(2000));
						}
							break;

						case 2 :
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

				case 2:
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

				case 3:
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

				case 4:
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
					switch(choix) {
						case 1 :
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

						case 2 :
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

						case 3 :
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

	case 0:
	{
		system("clear");
	}
		break;
	
	};

	}while(menup != 0);

	return 0;
}
