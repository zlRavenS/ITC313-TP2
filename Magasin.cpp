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

void Magasin::addProduit(std::string titre, std::string description, int quantite, float prix) {
	Produit *produit = new Produit(titre, description, quantite, prix);
	this->_produit.push_back(produit);
	delete produit;
}


void Magasin::displayProd() {
 	std::cout << "    NOM 	|	 DESCRIPTION 	|	QUANTITE	|	PRIX   "<< std::endl;
 	std::cout << "----------------------------------------------------------------------------"<< std::endl;
 		for (int i=0; i< _produit.size(); i++){
 			std::cout << *_produit.at(i);
 	};
 	std::cout << "\n \n" << std::endl;
}


void Magasin::displayProdFiltre(std::string titre) {
	int j=0;
	for (int i=0; i<_produit.size();i++){
		Produit *p = _produit.at(i); 
 		if(p->getTitre() == titre){
 			j++;
 		}
 	}
 	if( j == 0) {
 		std::cout << "Cet article n'est pas en stock \n" << std::endl;
 	}
 	else{
		std::cout << "    NOM 	|	 DESCRIPTION 	|	QUANTITE	|	PRIX   "<< std::endl;
 		std::cout << "----------------------------------------------------------------------------"<< std::endl;
 		for (int i=0; i<_produit.size(); i++){
 			Produit *p = _produit.at(i); 
 			if(p->getTitre() == titre){
 				std::cout << *p << std::endl;
 			}
 		}
 	}
 	std::cout << "\n" << std::endl;
}


void Magasin::setQtt(std::string titre, int n){
	for (int i=0; i<_produit.size();i++){
		Produit *p = _produit.at(i); 
 		if(p->getTitre() == titre){
 			p->setQuantite(n);
 		}
 	}
 	std::cout << "Quantité de " << titre << " mise à jour !" << std::endl;
 	std::cout << "Il y a désormais " << n  << " " << titre << "\n" << std::endl;
 }






void Magasin::addClient(std::string nom, std::string prenom) {
	int id = _client.size() + 1;
	Client *client = new Client(nom, prenom, id);
	this->_client.push_back(client);
	delete client;
}

 void Magasin::displayClients() {
 	std::cout << "    Nom	 Prénom    |	ID   "<< std::endl;
 	std::cout << "-----------------------------------------------------"<< std::endl;
 		for (int i=0; i< _client.size(); i++){
 			std::cout << *_client.at(i);
 	};
 	std::cout << "\n \n" << std::endl;
}


void Magasin::displayClientFiltre(std::string nom, std::string prenom) {
	int n=0, p=0;
	for (int i=0; i<_client.size();i++){
		Client *c = _client.at(i); 
 		if(c->getNom() == nom){
 			n++;
 		}
 	}
 	if( n == 0) {
 		std::cout << "Cette personne n'est pas un client \n" << std::endl;
 	}
 	else{
 		for (int i=0; i<_client.size();i++){
			Client *c = _client.at(i); 
 			if(c->getPrenom() == prenom){
 				p++;
 			}
 		}
 		if( p != 0) { 		
			std::cout << "    Nom	 Prénom    |	ID   "<< std::endl;
 			std::cout << "-----------------------------------------------------"<< std::endl;
 			for (int i=0; i<_client.size(); i++){
 				Client *c = _client.at(i); 
 				if(c->getPrenom() == prenom){
 					std::cout << *c << std::endl;
 				}
 			}
 		}
 	}
 	std::cout << "\n" << std::endl;
}


void Magasin::displayClientFiltre(int id) {
	int n=0;
	if(id > _client.size()){
		std::cout << "Cet ID ne correspond à aucun client \n" << std::endl;
	}
	else{
		Client *c = _client.at(id-1); 
 			if(c->getID() == id){
 				std::cout << "    Nom	 Prénom    |	ID   "<< std::endl;
 				std::cout << "-----------------------------------------------------"<< std::endl;
 				std::cout << *c << std::endl;
 			}
		}
	std::cout << "\n" << std::endl;
}

/*
void Magasin::addtoPanier(std::string titre, std::string nom, std::string prenom) {
	int n=0, p=0;
	for (int i=0; i<_client.size();i++){
		Client *c = _client.at(i); 
 		if(c->getNom() == nom){
 			n++;
 		}
 	}
 	if( n == 0) {
 		std::cout << "Cette personne n'est pas un client \n" << std::endl;
 	}
 	else{
 		for (int i=0; i<_client.size();i++){
			Client *c = _client.at(i); 
 			if(c->getPrenom() == prenom){
 				p++;
 			}
 		}
 		if( p != 0) { 		
			std::cout << "    Nom	 Prénom    |	ID   "<< std::endl;
 			std::cout << "-----------------------------------------------------"<< std::endl;
 			for (int i=0; i<_client.size(); i++){
 				Client *c = _client.at(i); 
 				if(c->getPrenom() == prenom){
 					for(int j=0; j<_produit.size(); j++){
 						Produit *p = _produit.at(j);
 						if(p->getTitre() == titre){
 							c->addtoCart(titre);
 						}
 					}
 				}
 				std::cout << *c << std::endl;
 			}
 		}
 	}
 	std::cout << "\n" << std::endl;
}
*/






void Magasin::setID(int id)
{
	for (int i=0; i<_client.size();i++){
		Client *c = _client.at(i); 
 		c->setIdentifiant(i+1);
 	}	
}

std::vector<Produit*> Magasin::getProd() {
	return _produit;
}
