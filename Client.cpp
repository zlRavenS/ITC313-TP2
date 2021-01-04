/*
  *Fichier:	Client.cpp
  *Author:	Paul Ledoux (Paul_Ledoux@etu.u-bourgogne.fr)
  *Date: 	04/01/2021
  *Summary: Declaration de la classe Client
*/

#include "Client.h"


Client::Client(std::string nom, std::string prenom, int id) : _nom(nom), _prenom(prenom), _id(id) {

}

Client::Client() : _nom("Dos Santos"), _prenom("Miguel"), _id(2) {

}

std::string Client::getPrenom()
{
    return _prenom;
}

std::string Client::getNom()
{
    return _nom;
}

int Client::getID()
{
    return _id;
}

std::vector<Produit*> Client::getPanier()
{
	return _panier;
}




void Client::addtoCart(std::string titre){
  Produit *produit = new Produit(titre, " ", 1, 10);
  this->_panier.push_back(produit);
  delete produit;
}


void Client::clearCart(){
	_panier.clear();
}

void Client::changeQuantity(std::string nom, int quantite){
	for(int i=0; i<_panier.size(); i++){
		Produit *article = _panier.at(i);
		if(article->getTitre() == nom){
			article->setQuantite(quantite);
		}
    delete article;
	}
}

void Client::deleteProduit(std::string titre){
  for(int i=0; i<_panier.size(); i++){
    Produit *article = _panier.at(i);
    if(article->getTitre() == titre){
      _panier.erase(_panier.begin()+(i+1));
    }
    delete article;
  }
}



std::ostream& operator << (std::ostream& output, Client& obj) {
    output << "-" << obj.getNom() << " " << obj.getPrenom() << " | n°" << obj.getID() << " | Panier : \n";
    std::vector<Produit*> panier = obj.getPanier();
    if(panier.size() != 0){
    	for (int i=0; i<panier.size(); i++){
    		output << "   -->" << *panier.at(i) << std::endl;
    	};
	};
    output << std::endl;
    return output;
}