/*
  *Fichier:	Magasin.cpp
  *Author:	Rémi Lefaivre (Remi_Lefaivre@etu.u-bourgogne.fr)
  *Date: 	04/01/2021
  *Summary: Declaration de la classe Magasin
*/

#include <iostream>

#include "Magasin.h"

Magasin::Magasin(){

}

////////////// Fonctions des Produits //////////////

void Magasin::addProduit(std::string titre, std::string description, int quantite, float prix) {
	Produit *produit = new Produit(titre, description, quantite, prix);
	this->_produit.push_back(produit);
}

void Magasin::displayProd() {
 	std::cout << "         NOM         |       DESCRIPTION       |  QTT  |    PRIX    "<< std::endl;
 	std::cout << "-----------------------------------------------------------------------"<< std::endl;
 		for (int i=0; i< (int) _produit.size(); i++){
 			std::cout << *_produit.at(i) << std::endl;
 	};
 	std::cout << "\n" << std::endl;
}

void Magasin::displayProdFiltre(std::string titre) {
	int j=0;
	for (int i=0; i< (int) _produit.size();i++){
		Produit *p = _produit.at(i); 
 		if(p->getTitre() == titre){
 			j++;
 		}
 	}
 	if( j == 0) {
 		std::cout << "\nCet article n'est pas en stock\n" << std::endl;
 	}
 	else{
		std::cout << "         NOM         |       DESCRIPTION       |  QTT  |    PRIX    "<< std::endl;
 		std::cout << "-----------------------------------------------------------------------"<< std::endl;
 		for (int i=0; i< (int) _produit.size(); i++){
 			Produit *p = _produit.at(i); 
 			if(p->getTitre() == titre){
 				std::cout << *p << std::endl;
 			}
 		}
 	}
 	std::cout << "\n" << std::endl;
}

void Magasin::setQtt(std::string titre, int n){
	int comptp = 0;
	for (int i=0; i< (int) _produit.size();i++){
		Produit *p = _produit.at(i); 
 		if(p->getTitre() == titre){
 			p->setQuantite(n);
 			comptp++;
 		}
 	}
 	if(comptp != 0) {
		std::cout << "\nQuantité de " << titre << " mise à jour !" << std::endl;
	 	std::cout << "Il y a désormais " << n  << " " << titre << "\n" << std::endl;
 	}
 	else {
 		std::cout << "Cet article n'est pas en stock !" << std::endl;
 	}
 }





////////////// Fonctions des Clients //////////////

void Magasin::addClient(std::string nom, std::string prenom) {
	int id = _client.size()+1;
	Client *client = new Client(nom, prenom, id);
	this->_client.push_back(client);
}

void Magasin::displayClients() {
 	std::cout << "       Nom       Prénom      |   n° Client    |  Panier ->  "<< std::endl;
 	std::cout << "----------------------------------------------------------"<< std::endl;
 	for (int i=0; i< (int) _client.size(); i++){
 		std::cout << *_client.at(i);
 	};
 	std::cout << "\n" << std::endl;

 }


void Magasin::displayClientFiltre(std::string nom, std::string prenom) {
	int n=0, p=0;
	for (int i=0; i< (int) _client.size();i++){
		Client *c = _client.at(i); 
 		if(c->getNom() == nom){
 			n++;
 		}
 	}
 	if( n == 0) {
 		std::cout << "\n\nCette personne n'est pas un client" << std::endl;
 	}
 	else{
 		for (int i=0; i< (int) _client.size();i++){
			Client *c = _client.at(i); 
 			if(c->getPrenom() == prenom){
 				p++;
 			};
 		};
 		if( p != 0) { 		
			std::cout << "       Nom       Prénom      |   n° Client    |  Panier ->  "<< std::endl;
 			std::cout << "-----------------------------------------------------"<< std::endl;
 			for (int i=0; i< (int) _client.size(); i++){
 				Client *c = _client.at(i); 
 				if(c->getPrenom() == prenom){
 					std::cout << *c << std::endl;
 				};
 			};
 		};
 		if( p == 0 ) {
 			std::cout << "\nCette personne n'est pas un client" << std::endl;
 		};
 	};
 	std::cout << "\n" << std::endl;
}

void Magasin::displayClientFiltre(int id) {
	if(id > (int) _client.size()){
		std::cout << "\nCet ID ne correspond à aucun client" << std::endl;
	}
	else{
		std::string nom = _client.at(id-1)->getNom();
		std::string prenom = _client.at(id-1)->getPrenom();
		displayClientFiltre(nom, prenom);
		}
	std::cout << "\n" << std::endl;
}

void Magasin::addtoPanier(std::string titre, int qtt, std::string nom, std::string prenom) {
	int id = 0, comptc=0, comptp=0;
	for(int i=0; i< (int) _client.size(); i++){
		if((_client.at(i)->getNom() == nom) && (_client.at(i)->getPrenom() == prenom)) {
			id = _client.at(i)->getID();
			comptc++;
		};
	}
	if(comptc == 0){
		std::cout << "\nCette personne n'est pas un client" << std::endl;
	}
	if(comptc != 0) {
		Client *client = _client.at(id-1);
		for(int j=0; j< (int) _produit.size(); j++) {
			if(_produit.at(j)->getTitre() == titre) {
				Produit *prod = new Produit(_produit.at(j));
				prod->setQuantite(qtt);
				client->addtoCart(prod);
				_produit.at(j)->setQuantite((_produit.at(j)->getQuantite()) - (qtt));
				comptp++;
			};
		};
		if(comptp == 0) {
			std::cout << "\nCet article n'est pas en stock" << std::endl;
		}
		else {
			std::cout << "\n" << titre << " ajouté au panier de " << nom << " " << prenom << " avec succès !" << std::endl;
		}
	}
}

void Magasin::addtoPanier(std::string titre, int qtt, int id) {
	if(id > (int) _client.size()){
		std::cout << "\nCet ID ne correspond à aucun client" << std::endl;
	}
	else{
		std::string nom = _client.at(id-1)->getNom();
		std::string prenom = _client.at(id-1)->getPrenom();
		addtoPanier(titre, qtt, nom, prenom);
	};
}

void Magasin::deleteProdPanier(std::string titre, std::string nom, std::string prenom) {
	int id = 0, comptc = 0, comptp = 0;
	for(int i=0; i< (int) _client.size(); i++){
		if((_client.at(i)->getNom() == nom) && (_client.at(i)->getPrenom() == prenom)) {
			id = _client.at(i)->getID();
			comptc++;
		}
	}
	if(comptc == 0){
		std::cout << "\nCette personne n'est pas un client" << std::endl;
	}
	if(comptc != 0) {
		Client *client = _client.at(id-1);
		std::vector<Produit*> panier = _client.at(id-1)->getPanier();
		for(int j=0; j< (int) panier.size(); j++){
			if(panier.at(j)->getTitre() == titre) {
				int qtt = panier.at(j)->getQuantite();
				client->deleteProduit(titre);
				_produit.at(j)->setQuantite((_produit.at(j)->getQuantite()) + (qtt));
				comptp++;
			};
		};
		if(comptp == 0) {
			std::cout << "\nCet article n'est pas dans le panier" << std::endl;
		}
	}
}

void Magasin::deleteProdPanier(std::string titre, int id) {
	if(id > (int) _client.size()){
		std::cout << "\nCet ID ne correspond à aucun client" << std::endl;
	}
	else{
		std::string nom = _client.at(id-1)->getNom();
		std::string prenom = _client.at(id-1)->getPrenom();
		deleteProdPanier(titre, nom, prenom);
	}
}

void Magasin::changeQttPanier(std::string titre, int quantite, std::string nom, std::string prenom) {
	int id = 0, comptp = 0;
	for(int i=0; i< (int) _client.size(); i++){
		if((_client.at(i)->getNom() == nom) && (_client.at(i)->getPrenom() == prenom)) {
			id = _client.at(i)->getID();
		}
	}
	Client *client = _client.at(id-1);
	std::vector<Produit*> panier = _client.at(id-1)->getPanier();
	for(int j=0; j< (int) panier.size(); j++){
		if(panier.at(j)->getTitre() == titre) {
			int qtt = panier.at(j)->getQuantite();
			_produit.at(j)->setQuantite((_produit.at(j)->getQuantite()) + (qtt));
			client->changeQuantity(titre, quantite);
			_produit.at(j)->setQuantite((_produit.at(j)->getQuantite()) - (quantite));
			std::cout << "\nQuantité de " << titre << " du panier de " << nom << " " << prenom << " modifié à " << quantite << " !" << std::endl;
			comptp++;
		};
	};
	if(comptp == 0) {
		std::cout << "\nCet article n'est pas dans le panier" << std::endl;
	}
}

void Magasin::changeQttPanier(std::string titre, int quantite, int id) {
	std::string nom = _client.at(id-1)->getNom();
	std::string prenom = _client.at(id-1)->getPrenom();
	changeQttPanier(titre, quantite, nom, prenom);
}



////////////// Fonctions des Commandes //////////////

void Magasin::creerCommande(std::string nom, std::string prenom){
	int id = 0;
	for(int i=0; i< (int) _client.size(); i++){
		if((_client.at(i)->getNom() == nom) && (_client.at(i)->getPrenom() == prenom)) {
			id = _client.at(i)->getID();
		};
	};
	Client* client = _client.at(id-1);
	std::vector<Produit*> panier = _client.at(id-1)->getPanier();
	if(panier.size() != 0) {
		int numero = _commande.size()+1;
		Commande *commande = new Commande (client, panier, numero);
		this->_commande.push_back(commande);
		_client.at(id-1)->clearCart();
		std::cout << "\nCommande de " << nom << " " << prenom << " passée et panier vidé !" << std::endl;
	}
	else {
		std::cout << "Vous ne pouvez pas faire de commande sans articles dans votre panier !" << std::endl;
	}
}

void Magasin::creerCommande(int id){
	Client* client = _client.at(id-1);
	std::vector<Produit*> panier = _client.at(id-1)->getPanier();
	int numero = _commande.size()+1;
	Commande *commande = new Commande (client, panier, numero);
	this->_commande.push_back(commande);
	_client.at(id-1)->clearCart();
}

void Magasin::validerCommande(int numero) {
	for(int i=0; i< (int) _commande.size(); i++){
    Commande *commande = _commande.at(i);
    if(commande->getNumero() == numero){
      commande->setStatus("Validée");
    }
  }
}

void Magasin::displayCommandes() {
 	for (int i=0; i< (int) _commande.size(); i++){
 		std::cout << *_commande.at(i);
		std::cout << "PANIER :"<< std::endl;
		std::vector<Produit*> panier = _commande.at(i)->getPanier();
		for(int j=0; j<(int) panier.size(); j++){
			std::cout << "	--> " << *panier.at(j) << std::endl;
		};
		std::cout << "\n" << std::endl;
	};
	std::cout << "\n" << std::endl;
}

void Magasin::displayCommandesFiltre(std::string nom, std::string prenom) {
	int compt = 0;
	for (int i=0; i< (int) _commande.size(); i++){
 		Client* client = _commande.at(i)->getClient();
 		std::string NOM = client->getNom();
 		std::string PRENOM = client->getPrenom();
 		if( (NOM == nom) && (PRENOM == prenom) ) {
 			compt++;
 			std::cout << "\n" << std::endl;
 			std::cout << *_commande.at(i);
			std::cout << "PANIER :"<< std::endl;
			std::vector<Produit*> panier = _commande.at(i)->getPanier();
			for(int j=0; j<(int) panier.size(); j++){
				std::cout << "	--> " << *panier.at(j) << std::endl;
			};
			std::cout << "\n" << std::endl;
 		};
 	};
 	if(compt == 0) {
 		std::cout << "\n" << nom << " " << prenom << " n'est pas un client" << std::endl;
 		std::cout << "\n" << std::endl;
 	}
}

void Magasin::displayCommandesFiltre(int id) {
	if(id <= (int) _client.size()) {
		std::string nom = _client.at(id-1)->getNom();
		std::string prenom = _client.at(id-1)->getPrenom();
		displayCommandesFiltre(nom, prenom);
	}
	else {
 		std::cout << "\nCet ID ne correspond à aucun client" << std::endl;
 		std::cout << "\n" << std::endl;
 	}
 }


void Magasin::displayCommandeNum(int num) {
	if( num <= (int) _commande.size()) {
		std::cout << "\n" << std::endl;
 	std::cout << *_commande.at(num-1);
 	std::cout << "PANIER :"<< std::endl;
 	std::vector<Produit*> panier = _commande.at(num-1)->getPanier();
	for(int j=0; j<(int) panier.size(); j++){
		std::cout << "	--> " << *panier.at(j) << std::endl;
	};
 	std::cout << "\n" << std::endl;
 	}
 	else {
 		std::cout << "\nCette commande n'existe pas" << std::endl;
 		std::cout << "\n" << std::endl;
 	}
 };