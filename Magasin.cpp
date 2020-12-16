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
 	std::cout << "\n \n" << std::endl;
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
 		for (int i=0; i<_produit.size(); i++){
 			Produit *p = _produit.at(i); 
 			if(p->getTitre() == nom){
 				std::cout << *p << std::endl;
 			}
 		}
 	}
 	std::cout << "\n" << std::endl;
}


void Magasin::setQtt(int n, std::string nom){
	for (int i=0; i<_produit.size();i++){
		Produit *p = _produit.at(i); 
 		if(p->getTitre() == nom){
 			p->setQuantite(n);
 		}
 	}
 	std::cout << "Quantité de " << nom << " mise à jour !" << std::endl;
 	std::cout << "Il y a désormais " << n << nom << "\n" << std::endl;
 }