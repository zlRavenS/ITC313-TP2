/*
  *Fichier:	Magasin.h
  *Author:	Rémi Lefaivre (Remi_Lefaivre@etu.u-bourgogne.fr)
  *Date: 	11/12/2020
  *Summary: Declaration de la classe Magasin
*/

#ifndef MAGASIN_H
#define MAGASIN_H

#include <vector>
#include "Produit.h"

class Magasin{

public:

	Magasin();

	void addProduit(Produit* produit);
	void display();
	void displayFiltre(std::string nom);
	void setQtt(int n, std::string nom);

private:

	std::vector<Produit*> _produit;
	/*std::vector<Client*> _client;
	std::vector<Commande*> _commande;*/

};
#endif