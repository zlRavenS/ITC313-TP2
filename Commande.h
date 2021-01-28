/*
  *Fichier:	Commande.h
  *Author:	Rémi Lefaivre (Remi_Lefaivre@etu.u-bourgogne.fr)
  *Date: 	28/01/2021
  *Summary: Declaration de la classe Commande
*/

#ifndef COMMANDE_H
#define COMMANDE_H

#include <vector> 	// on inclut dans la classe la bibliothèque vector
#include "Client.h" 	// on inclut dans la classe la classe Client.h
#include "Produit.h"	// on inclut dans la classe la classe Produit.h

//Creation et définition de la classe Commande

class Commande{

public:

	Commande(Client* client, std::vector<Produit*> panier, int numero);	// construteur contenant tous les membres appartenant à private

	Client* getClient() const;	// Getteur permettant de récupérer les infos du client
	std::vector<Produit*> getPanier() const;	// Getteur permettant de récupérer le panier du client pour la commande
	std::string getStatus() const;	// Getteur permettant de récupérer le statut de la commande
	int getNumero() const;	// Getteur permettant de récupérer le numéro de la commande

	void setStatus(std::string etat); // Setteur permettant de déterminer et/ou changer l'état de la commande

private:

	int _numero;	// variable de type int pour le numéro de la commande
	Client* _client;	// variable de type Client* pour le client
	std::vector<Produit*> _panier;	// variable de type vector contenant le pointeur Produit* pour le panier
	std::string _status; 	// variable de type string pour le statut de la commande

};

std::ostream& operator << (std::ostream& output, Commande& obj);	// Surcharge de l'operateur <<
#endif