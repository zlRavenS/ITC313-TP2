/*
  *Fichier:	Produit.h
  *Author:	Paul Ledoux (Paul_Ledoux@etu.u-bourgogne.fr)
  *Date: 	04/01/2021
  *Summary: Declaration de la classe Produit
*/



#ifndef _PRODUIT_H
#define _PRODUIT_H

#include <iostream> // on inclut dans la classe la bibliothèque iostream
#include <string> // on inclut dans la classe la bibliothèque string
#include <vector> // on inclut dans la classe la bibliothèque vector.h


//Creation et définition de la classe produit

class Produit {

public:


    Produit(std::string titre, std::string description, int quantite, float prix); // construteur avec tout les membres de private
    Produit(); // constructeur par défaut

    //Getters et Setters
       
    std::string getTitre(); // Getteur permettant de récupérer le titre du produit
    std::string getDescription() const;  // Getteur permettant de récupérer la description du produit
    int getQuantite() const;  // Getteur permettant de récupérer la quantité du produit
    float getPrix() const;   // Getteur permettant de récupérer le prix du produit

    void setQuantite(int quantite);   // Setteurs permettant de déterminer et/ou d'ajuster la quantité d'un produit


private:
    std::string _titre;   // variable de type string pour le titre
    std::string _description; // variable de type string pour la description
    int _quantite;  // variable de type int pour la quantité
    float _prix;  // variable de type float pour le prix

};

//Surcharge de l'operateur <<

std::ostream& operator << (std::ostream& output, Produit& obj);


#endif