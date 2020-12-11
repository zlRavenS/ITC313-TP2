#include "Produit.h"
#include <iostream>
#include <string>

/*
  *Fichier:	Produit.cpp
  *Author:	Paul Ledoux (Paul_Ledoux@etu.u-bourgogne.fr)
  *Date: 	04/12/2020
  *Summary: Declaration de la classe Produit
*/

Produit::Produit(std::string titre, std::string description, int quantite, float prix) : _titre(titre), _description(description), _quantite(quantite), _prix(prix)
{

}

Produit::Produit() : _titre("PS5"), _description("Console de Jeu"), _quantite(1), _prix(499.99)
{

}

std::string Produit::getTitre() const
{
    return _titre;
}

std::string Produit::getDescription() const
{
    return _description;
}

int Produit::getQuantite() const
{
    return _quantite;
}

float Produit::getPrix() const
{
    return _prix;
}

/*void Produit::setQuantite(int quantite)
{
    _quantite = quantite;
}*/


std::ostream& operator << (std::ostream& output, Produit& obj) {
    output << obj.getTitre() << " 		 " << obj.getDescription() << "  	 (" << obj.getQuantite() << ") 			 " << obj.getPrix() << " €" << std::endl;

    return output;
}