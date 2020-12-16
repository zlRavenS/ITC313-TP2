/*
  *Fichier:	Magasin.cpp
  *Author:	Rémi Lefaivre (Remi_Lefaivre@etu.u-bourgogne.fr)
  *Date: 	11/12/2020
  *Summary: Declaration de la classe Magasin
*/

#include <iostream>

#include "Magasin.h"

Magasin::Magasin(){

}

void Magasin::addProduit(Produit* produit) {
	_produit.push_back(produit);
}


void Magasin::display() {
 	std::cout << "    NOM 	|	 DESCRIPTION 	|	QUANTITE	|	PRIX   "<< std::endl;
 	std::cout << "----------------------------------------------------------------------------"<< std::endl;
 		for (int i=0; i< _produit.size(); i++){
 			std::cout << *_produit.at(i);
 	};
}


void Magasin::displayFiltre(std::string nom) {
	int j=0;
	for (int i=0; i<_produit.size();i++){
		Produit *p = _produit.at(i); 
 		if(p->getTitre() == nom){
 			j++;
 		}
 	}
 	if( j == 0) {
 		std::cout << "Cet article n'est pas en stock \n" << std::endl;
 	}
 	else{
		std::cout << "    NOM 	|	 DESCRIPTION 	|	QUANTITE	|	PRIX   "<< std::endl;
 		std::cout << "----------------------------------------------------------------------------"<< std::endl;
 		for (int i=0; i<j; i++){
 			Produit *p = _produit.at(i); 
 			if(p->getTitre() == nom){
 				std::cout << *p << std::endl;
 			}
 		}
 	}
}

/*
void Magasin::setQtt(int n, Produit produit){
 	produit->setQuantite(n);
 }*/