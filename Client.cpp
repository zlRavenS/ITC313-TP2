/*
  *Fichier:	Client.cpp
  *Author:	Paul Ledoux (Paul_Ledoux@etu.u-bourgogne.fr)
  *Date: 	04/01/2021
  *Summary: Declaration de la classe Client
*/

#include "Client.h"


Client::Client(std::string nom, std::string prenom, int id) : _nom(nom), _prenom(prenom), _id(id) {

}


std::string Client::getPrenom() const
{
    return _prenom;
}

std::string Client::getNom() const
{
    return _nom;
}

int Client::getID() const
{
    return _id;
}

std::vector<Produit*> Client::getPanier() const
{
	return _panier;
}




void Client::addtoCart(Produit* produit){
  this->_panier.push_back(produit);
}


void Client::clearCart(){
	_panier.clear();
}

void Client::changeQuantity(std::string titre, int quantite){
	for(int i=0; i< (int) _panier.size(); i++){
		Produit *article = _panier.at(i);
		if(article->getTitre() == titre){
			article->setQuantite(quantite);
		}
	}
}

void Client::deleteProduit(std::string titre){
  for(int i=0; i< (int) _panier.size(); i++){
    Produit *article = _panier.at(i);
    if(article->getTitre() == titre){
      _panier.erase(_panier.begin()+i);
    }
  }
}



std::ostream& operator << (std::ostream& output, Client& obj) {
    int sizeNom, sizeNum;
    float total = 0;
    sizeNom = obj.getPrenom().length() + obj.getNom().length();
    int id = obj.getID();
    if(id >= 1){
      sizeNum = 1;
    }
    if(id >= 10){
      sizeNum = 2;
    }
    if(id >= 100){
      sizeNum = 3;
    }
    if(id >= 1000){
      sizeNum = 4;
    }
    std::string espNom, espNum;
    for(int i = sizeNom; i<26; i++) {
      espNom += " ";
    }
    for(int i = sizeNum; i<5; i++) {
      espNum += " ";
    }
    output << "-" << obj.getNom() << " " << obj.getPrenom()  << espNom << " | Client n°" << obj.getID() << espNum << " | Panier : \n";
    std::vector<Produit*> panier = obj.getPanier();
    if(panier.size() != 0){
    	for (int i=0; i< (int) panier.size(); i++){
    		output << "   -->" << *panier.at(i) << std::endl;
        total += (panier.at(i)->getPrix())*((float) (panier.at(i)->getQuantite()));
    	};
      std::cout << "   --> TOTAL :" << total << " €" << std::endl;
    };
    output << std::endl;
    return output;
}