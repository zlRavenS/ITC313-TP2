#include "Produit.h"
#include <iostream>
#include <string>

/*
  *Fichier:	Produit.cpp
  *Author:	Paul Ledoux (Paul_Ledoux@etu.u-bourgogne.fr)
  *Date: 	04/12/2020
  *Summary: Declaration de la classe Produit
*/

Produit::Produit(std::string titre, std::string description, int quantite, float prix)
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

float Produit::getPrixU() const
{
    return _prix;
}

void Produit::setQuantite(int quantite)
{
    _quantite = quantite;
}


std::ostream& operator << (std::ostream& output, Produit& obj) {
    output << obj.getTitre() << "  " << obj.getDescription() << "   (" << obj.getQuantite() << ")  " << obj.getPrix() << "  €" << std::endl;

    return output;
}