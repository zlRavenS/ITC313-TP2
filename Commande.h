/*
  *Fichier:	Commande.h
  *Author:	Rémi Lefaivre (Remi_Lefaivre@etu.u-bourgogne.fr)
  *Date: 	04/01/2021
  *Summary: Declaration de la classe Commande
*/

#ifndef COMMANDE_H
#define COMMANDE_H

#include <vector>
#include "Client.h"

class Commande{

public:

	Commande(Client* client, std::vector<Produit*> panier, int numero);

	Client* getClient();
	std::vector<Produit*> getPanier();
	std::string getStatus();
	int getNumero();

	void setStatus(std::string etat);

private:

	int _numero;
	Client* _client;
	std::vector<Produit*> _panier;
	std::string _status;

};

std::ostream& operator << (std::ostream& output, Commande& obj);

#endif