/*
  *Fichier:	Client.h
  *Author:	Paul Ledoux (Paul_Ledoux@etu.u-bourgogne.fr)
  *Date: 	04/01/2021
  *Summary: Declaration de la classe Client
*/

#ifndef _CLIENT_H
#define _CLIENT_H

#include <iostream> // on inclut dans la classe la bibliothèque iostream
#include <string>	// on inclut dans la classe la bibliothèque string
#include <vector>	// on inclut dans la classe la bibliothèque vector
#include "Produit.h"// on lie le .cpp à la classe qui le définit

//Creation et définition de la classe Client

class Client{

public:

	Client(std::string nom, std::string prenom, int id);	// construteur contenant tous les membres appartenant à private

	int getID(); // Getteur permettant de récupérer l'id du client
	std::string getPrenom(); // Getteur permettant de récupérer le prénom du client
	std::string getNom();	// Getteur permettant de récupérer le nom du client
	std::vector<Produit*> getPanier(); // Getteur permettant de récupérer le panier du client

	void addtoCart(Produit* produit);	// fonction permettant d'ajouter un produit au panier
	void clearCart();	// fonction permettant de vider le panier
	void changeQuantity(std::string titre, int quantite);	// fonction permettant de changer la quantité d'un item dans le panier
	void deleteProduit(std::string titre);	// fonction permettant de supprimer un produit du panier

private:

	int _id;	// variable de type int pour l'ID
	std::string _prenom; 	// variable de type string pour le prénom du client
	std::vector<Produit*> _panier;	// variable de type vector contenant un pointeur "Produit*" pour le panier du client

};


std::ostream& operator << (std::ostream& output, Client& obj);	// Surcharge de l'operateur <<

#endif