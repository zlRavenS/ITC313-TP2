#include "Produit.h"
#include <iostream>
#include <string>

/*
  *Fichier:	Produit.cpp
  *Author:	Paul Ledoux (Paul_Ledoux@etu.u-bourgogne.fr)
  *Date: 	04/01/2021
  *Summary: Declaration de la classe Produit
*/

Produit::Produit(std::string titre, std::string description, int quantite, float prix) : _titre(titre), _description(description), _quantite(quantite), _prix(prix) // Constructeur de la classe produit
{

}

Produit::Produit() : _titre("PS5"), _description("Console de Jeu"), _quantite(1), _prix(499.99) // Constructeur de la classe Produit prenant en paramètres un pproduit : la PS4
{

}

std::string Produit::getTitre() // Getteur permettant de récupérer le Titre d'un produit
{
    return _titre;
}

std::string Produit::getDescription() const // Getteur permettant de récupérer la description d'un produit
{
    return _description;
}

int Produit::getQuantite() const // Getteur permettant de récupérer la quantité d'un produit
{
    return _quantite;
}

float Produit::getPrix() const // Getteur permettant de récupérer le prix d'un produit
{
    return _prix;
}

void Produit::setQuantite(int quantite) // Setteur permettant de 
{
    _quantite = quantite;
}


std::ostream& operator << (std::ostream& output, Produit& obj) { // Surcharge de l'opérateur << permettant d'afficher correctement les articles/produits du magasin
    output << obj.getTitre() << "             " << obj.getDescription() << "                   (" << obj.getQuantite() << ")            ";
    if(obj.getPrix() != 0) {
       output << obj.getPrix() << " €";
    };
    return output;
}