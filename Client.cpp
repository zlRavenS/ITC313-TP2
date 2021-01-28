/*
  *Fichier:	Client.cpp
  *Author:	Paul Ledoux (Paul_Ledoux@etu.u-bourgogne.fr)
  *Date: 	04/01/2021
  *Summary: Declaration de la classe Client
*/

#include "Client.h"


Client::Client(std::string nom, std::string prenom, int id) : _nom(nom), _prenom(prenom), _id(id) { // constructeur de la classe Client 

}


std::string Client::getPrenom() // Getters qui permet de récupérer le prénom d'un client
{
    return _prenom;
}

std::string Client::getNom()  // Getteurs qui permet de récupérer le nom d'un client
{
    return _nom;
}

int Client::getID()   // Getteurs permettant de récupérer l'id d'un client
{
    return _id;
}

std::vector<Produit*> Client::getPanier() // Getteurs permettant de récupérer le panier d'un client
{
	return _panier;
}




void Client::addtoCart(Produit* produit){   // Fonction permettant d'ajouter un produit dans le panier du client
  this->_panier.push_back(produit);
}


void Client::clearCart(){ // Fonction permettant de vider le panier avec la commande "clear"
	_panier.clear();
}

void Client::changeQuantity(std::string titre, int quantite){ // Fonction permettant de changer la quantité d'un produit qui est déjà dans le panier d'un client
	for(int i=0; i< (int) _panier.size(); i++){
		Produit *article = _panier.at(i);
		if(article->getTitre() == titre){
			article->setQuantite(quantite);
		}
	}
}

void Client::deleteProduit(std::string titre){  // Fonction permettant de supprimer un produit du panier du client
  for(int i=0; i< (int) _panier.size(); i++){
    Produit *article = _panier.at(i);
    if(article->getTitre() == titre){
      _panier.erase(_panier.begin()+i);
    }
  }
}



std::ostream& operator << (std::ostream& output, Client& obj) { // surcharge de l'opérateur << pour l'affichage de nos vecteurs
    output << "-" << obj.getNom() << " " << obj.getPrenom() << " | Client n°" << obj.getID() << " | Panier : \n";
    std::vector<Produit*> panier = obj.getPanier();
    if(panier.size() != 0){
    	for (int i=0; i< (int) panier.size(); i++){
    		output << "   -->" << *panier.at(i) << std::endl;
    	};
	};
    output << std::endl;
    return output;
}