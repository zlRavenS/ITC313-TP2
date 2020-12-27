/*
  *Fichier:	Client.h
  *Author:	Paul Ledoux (Paul_Ledoux@etu.u-bourgogne.fr)
  *Date: 	16/12/2020
  *Summary: Declaration de la classe Client
*/

#ifndef _CLIENT_H
#define _CLIENT_H

#include <iostream>
#include <string>
#include <vector>
#include "Produit.h"

class Client{

public:

	Client(std::string nom, std::string prenom, int id);
	Client();

	int getID();
	std::string getPrenom();
	std::string getNom();
	std::vector<Produit*> getPanier();

	void addtoCart(Produit* produit);
	void clearCart();
	void changeQuantity(std::string nom, int quantite);
	void deleteProduit();

	void setIdentifiant(int id);

private:

	int _id;
	std::string _prenom;
	std::string _nom;
	std::vector<Produit*> _panier;

};

std::ostream& operator << (std::ostream& output, Client& obj);

#endif