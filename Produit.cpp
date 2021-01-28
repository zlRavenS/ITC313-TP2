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

Produit::Produit(Produit* prod) : _titre(prod->getTitre()), _description(prod->getDescription()), _quantite(prod->getQuantite()), _prix(prod->getPrix()) // Constructeur de la classe Produit prenant en paramètres un pproduit : la PS4
{

}

Produit::Produit() : _titre("PS5"), _description("Console de Jeu"), _quantite(1), _prix(499.99) // Constructeur de la classe Produit prenant en paramètres un pproduit : la PS4
{

}

std::string Produit::getTitre() const
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



std::ostream& operator << (std::ostream& output, Produit& obj) {
    int sizetitre, sizedesc, sizeqtt, qtt;
    sizetitre = obj.getTitre().length();
    sizedesc = obj.getDescription().length();
    qtt = obj.getQuantite();
    if(qtt >= 1){
      sizeqtt = 1;
    }
    if(qtt >= 10){
      sizeqtt = 2;
    }
    if(qtt >= 100){
      sizeqtt = 3;
    }
    if(qtt >= 1000){
      sizeqtt = 4;
    }
    std::string espT, espD, espQ;
    for(int i = sizetitre; i<22; i++) {
      espT += " ";
    }
    for(int i = sizedesc; i<26; i++) {
      espD += " ";
    }
    for(int i = sizeqtt; i<7; i++) {
      espQ += " ";
    }
    output << obj.getTitre() << espT << obj.getDescription() << espD << "(" << obj.getQuantite() << ")" << espQ;
    if(obj.getPrix() != 0) {
       output << obj.getPrix() << " €";
    };
    return output;
}