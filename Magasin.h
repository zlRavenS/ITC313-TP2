/*
  *Fichier:	Magasin.h
  *Author:	Rémi Lefaivre (Remi_Lefaivre@etu.u-bourgogne.fr)
  *Date: 	04/12/2020
  *Summary: Declaration de la classe Magasin
*/

#ifndef MAGASIN_H
#define MAGASIN_H

#include <vector>

class Magasin{

public:

	Magasin();

private:

	std::vector<Produit*> _produit;
	std::vector<Client*> _client;
	std::vector<Commande*> _commande;

};
#endif