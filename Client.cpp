/*
  *Fichier:	Client.cpp
  *Author:	Paul Ledoux (Paul_Ledoux@etu.u-bourgogne.fr)
  *Date: 	16/12/2020
  *Summary: Declaration de la classe Client
*/

#include "Client.h"
#include <iostream>
#include <string>
#include <vector>


Client::Client(std::string nom, std::string prenom, int id, std::vector<Produit> panier) : _nom(nom), _prenom(prenom), _id(id), _panier(panier){

}

Client::Client(){

}

std::string Produit::getPrenom()
{
    return _prenom;
}

std::string Produit::getNom()
{
    return _nom;
}

int Produit::getID()
{
    return _id;
}

std::vector<Produit> getPanier()
{
	return _panier;
}

void Produit::add(){



}