/*
  *Fichier:	Magasin.h
  *Author:	Rémi Lefaivre (Remi_Lefaivre@etu.u-bourgogne.fr)
  *Date: 	11/12/2020
  *Summary: Declaration de la classe Magasin
*/

#ifndef MAGASIN_H
#define MAGASIN_H

#include <vector>

class Magasin{

public:

	Magasin();

	void addProduit(Produit* produit);
	void display();

private:

	std::vector<Produit*> _produit;
/*	std::vector<Client*> _client;
	std::vector<Commande*> _commande; Pas encore implémenté*/ 

};
#endif