/*
  *Fichier:	Magasin.cpp
  *Author:	Rémi Lefaivre (Remi_Lefaivre@etu.u-bourgogne.fr)
  *Date: 	04/12/2020
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
	for (int i=0; i<_produit.size();i++){
<<<<<<< Updated upstream
 		std::cout << "NOM 		DESCRIPTION 		QUANTITE		PRIX "<< std::endl;
=======
 		std::cout << "    NOM 	|	 DESCRIPTION 	|	QUANTITE	|	PRIX   "<< std::endl;
>>>>>>> Stashed changes
 		std::cout << _produit.at(i) << std::endl;
 	}
}
