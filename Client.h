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

	Produit();
	Produit(std::string nom, std::string prenom, int id, std::vector<Produit> panier);

	int getID();
	std::string getPrenom();
	std::string getNom();
	std::vector<Produit> getPanier();

	void add();




private:

	int _id;
	std::string _prenom;
	std::string _nom;
	std::vector<Produit> _panier;



}