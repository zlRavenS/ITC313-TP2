#include <iostream>
#include "Magasin.h"

int main() {

	Magasin EasyStore;
	Produit* prod1 = new Produit();

	std::cout << prod1 << std::endl;

	EasyStore.addProduit(prod1);
	EasyStore.display();

return 0;
}