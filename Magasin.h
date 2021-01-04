/*
  *Fichier:	Magasin.h
  *Author:	Rémi Lefaivre (Remi_Lefaivre@etu.u-bourgogne.fr)
  *Date: 	04/01/2021
  *Summary: Declaration de la classe Magasin
*/

#ifndef MAGASIN_H
#define MAGASIN_H

#include <vector>
#include "Produit.h"
#include "Client.h"

class Magasin{

public:

	Magasin();

	void addProduit(std::string titre, std::string description, int quantite, float prix);
	void displayProd();
	void displayProdFiltre(std::string titre);
	void setQtt(std::string titre, int n);

	void addClient(std::string nom, std::string prenom);
	void displayClients();
	void displayClientFiltre(std::string nom, std::string prenom);
	void displayClientFiltre(int id);
	void addtoPanier(std::string titre, std::string nom, std::string prenom);
	void addtoPanier(std::string titre, int id);

	void setID(int id);
	std::vector<Produit*> getProd();

private:

	std::vector<Produit*> _produit;
	std::vector<Client*> _client;
	//std::vector<Commande*> _commande;

};
#endif