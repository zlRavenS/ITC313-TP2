/*
  *Fichier:	Produit.h
  *Author:	Paul Ledoux (Paul_Ledoux@etu.u-bourgogne.fr)
  *Date: 	11/12/2020
  *Summary: Declaration de la classe Produit
*/



#ifndef _PRODUIT_H
#define _PRODUIT_H

#include <iostream>
#include <string>
#include <vector>


//Creation de la classe produit

class Produit {

public:


    Produit(std::string titre, std::string description, int quantite, float prix);
    Produit();

    //Getters et Setters
       
    std::string getTitre();
    std::string getDescription() const;
    int getQuantite() const;
    float getPrix() const;

   // void setQuantite(int quantite);


private:
    std::string _titre;
    std::string _description;
    int _quantite;
    float _prix;



};

// As Usual, surcharge de l'operateur <<

std::ostream& operator << (std::ostream& output, Produit& obj);


#endif