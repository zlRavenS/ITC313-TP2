/*
  *Fichier:	Commande.cpp
  *Author:	Rémi Lefaivre (Remi_Lefaivre@etu.u-bourgogne.fr)
  *Date: 	04/01/2021
  *Summary: Declaration de la classe Commande
*/

#include <iostream>

#include "Commande.h"

Commande::Commande(Client* client, std::vector<Produit*> panier, int numero) : _client(client), _panier(panier), _numero(numero), _status("En cours de validation") { // Constructeur de la classe Commande

}

Client* Commande::getClient() {   // Getteurs récupérant le Client de la commande
	return _client;
}

std::vector<Produit*> Commande::getPanier() { // Getteur permettant de récupérer le panier d'un client pour passer la commande
	return _panier;
}

std::string Commande::getStatus() { // Getteur permettant de récupérer le statut d'une commande
	return _status;
}

int Commande::getNumero() { // Getteur permettant de récupérer le numéro d'une commande
	return _numero;
}


void Commande::setStatus(std::string etat) {  // Setteur permettant de changer le statut de la commande : Ecnours de prépartation et validé
	_status = etat;
}



std::ostream& operator << (std::ostream& output, Commande& obj) { // Surcharge de l'opérateur << permettant d'afficher les commandes
	Client* client = obj.getClient();
    output << "Commande n°" << obj.getNumero() << " de " << client->getNom() << " " << client->getPrenom() << std::endl;
    std::cout << " ||| STATUS : " << obj.getStatus() << std::endl;
    return output;
}