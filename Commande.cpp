/*
  *Fichier:	Commande.cpp
  *Author:	Rémi Lefaivre (Remi_Lefaivre@etu.u-bourgogne.fr)
  *Date: 	04/01/2021
  *Summary: Declaration de la classe Commande
*/

#include <iostream>

#include "Commande.h"

Commande::Commande(Client* client, std::vector<Produit*> panier, int numero) : _client(client), _panier(panier), _numero(numero), _status("En cours de validation") {

}

Client* Commande::getClient() {
	return _client;
}

std::vector<Produit*> Commande::getPanier() {
	return _panier;
}

std::string Commande::getStatus() {
	return _status;
}

int Commande::getNumero() {
	return _numero;
}


void Commande::setStatus(std::string etat) {
	_status = etat;
}



std::ostream& operator << (std::ostream& output, Commande& obj) {
	Client* client = obj.getClient();
    output << "Commande n°" << obj.getNumero() << " de " << client->getNom() << " " << client->getPrenom() << std::endl;
    std::cout << " ||| STATUS : " << obj.getStatus() << std::endl;
    return output;
}