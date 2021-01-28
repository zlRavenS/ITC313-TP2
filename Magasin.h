/*
  *Fichier:	Magasin.h
  *Author:	Rémi Lefaivre (Remi_Lefaivre@etu.u-bourgogne.fr)
  *Date: 	04/01/2021
  *Summary: Declaration de la classe Magasin
*/

#ifndef MAGASIN_H
#define MAGASIN_H

#include <vector>	// on inclut dans la classe la bibliothèque vector
#include "Produit.h" // on inclut dans la classe la classe Produit.h
#include "Client.h"	// on inclut dans la classe la classe Client.h
#include "Commande.h" // on inclut dans la classe la classe Commande.h

class Magasin{

public:

	Magasin(); // Constructeur de base de la classe Magasin

	void addProduit(std::string titre, std::string description, int quantite, float prix);	// fonctionner permettant d'ajouter un produit au magasin
	void displayProd();	// fonction permettant d'afficher le "display" (affichage) du magasin
	void displayProdFiltre(std::string titre);	// fonction du filtre produit
	void setQtt(std::string titre, int n);	// Setteurs permettant de changer la quantité de produit en stock

	void addClient(std::string nom, std::string prenom);	// fonction permettant d'ajouter un client

	void displayClients();	// fonction permettant d'afficher les clients
	void displayClientFiltre(std::string nom, std::string prenom);	// fonction permettant d'afficher le filtre clients
	void displayClientFiltre(int id);

	void addtoPanier(std::string titre, int qtt, std::string nom, std::string prenom);	// fonction permettant d'ajouter des articles au panier 
	void addtoPanier(std::string titre, int qtt, int id);

	void deleteProdPanier(std::string titre, std::string nom, std::string prenom);	// fonction permettant de supprimer un produit du panier
	void deleteProdPanier(std::string titre, int id);

	void changeQttPanier(std::string titre, int quantite, std::string nom, std::string prenom);	// fonction permettant de chnager la quantité de produit voulue dans le panier
	void changeQttPanier(std::string titre, int quantite, int id);

	void creerCommande(std::string nom, std::string prenom);		// fonction permettant de créer une commande pour un client à partir de son nom/prénom
	void creerCommande(int id);		// fonction permettant de créer une commande pour un client à partir de son ID
	void validerCommande(int numero);		// fonction permettant de valider la commande en cours

	void displayCommandes();	// Affiche l'ensemble des commandes
	void displayCommandesFiltre(std::string nom, std::string prenom);	// filtre pour trier les commandes
	void displayCommandesFiltre(int id);
	void displayCommandeNum(int num);

private:

	std::vector<Produit*> _produit; // variable de type vecteur prenant le pointeur Produit* pour le produit
	std::vector<Client*> _client;	// variable de type vecteur prenant le pointeur Client* pour le client
	std::vector<Commande*> _commande;	// variable de type vecteur prenant le pointeur Commande* pour une commande

};
#endif