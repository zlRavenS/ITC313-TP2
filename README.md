# ITC313-TP2
## Easy-Store, by Rémi L. and Paul L.

	Ce README.md servira de compte-rendu à la réalisation du TP2 dont le sujet est fourni dans ce dépôt.

Tout d'abord, ce projet avait pour but de réaliser un programme pouvant servir à un magasin. Le but étant de pouvoir lister des produits, des clients et des commandes afin de pouvoir réaliser un véritable achat comme par exemple chez Amazon ou Cdiscount.

La première étape de ce projet repose sur la réflexion autour du sujet. Notre magasin doit pouvoir lister des produits, des clients et des commandes. De ceci découle naturellement nos attributes privés qui seront considérés comme des vecteurs de pointeurs de produits, de clients et de commandes. Les classes de ces attributs seront décalarées plus tard.

#### Question 1 - Création de la classe Magasin

1.a)	En suivant l'énoncé du TP2, nous avons défini dans la classe Magasin les attributs privés et le constructeur par défaut de cette classe.

1.b)	La création de notre objet Magasin se fera naturellement dans la fonction main par la déclaration : Magasin Easystore;



#### Question 2 - Création de la classe Produit

2.a)	Nous allons désormais commencer à définir les attributs privés de notre classe Magasin par la création d'autres classes, ici, la classe Produit. Un produit est défini par un titre (std::string), une description (std::string), une quantité (int), et un prix (float). Tous ces attributs peuvent être définis à partir de la librairie standard.

Nous avons défini ici 2 constructeurs : un par défaut avec des valeurs initiales qui sert pour tester notre programme et un autre constructeur qui prendra en paramètres des valeurs à associer aux attributs privés de notre classe. Les fonctions Getters seront simplement définies afin de renvoyer la valeur des attributs privés de notre objet Produit.

La méthode void Produit::setQuantite(int quantite) permet d'attribuer la valeur quantite à l'attribut privé _quantite de notre objet Produit.

2.b)	Si l'on souhaite afficher un produit sur le terminal, il est impossible avec la librairie standard de mettre un objet de type Produit à la suite d'un std::cout. C'est là qu'intervient la surcharge d'opérateur. La surchage d'opérateur définie à la fin du fichier Produit.cpp nous permet d'afficher un produit à la suite d'un std::cout. Quelques boucles ont été ajoutées dans notre code afin d'avoir un rendu plus propre des Produit dans le terminal et bien alligner chaque attribut par colonne.



#### Question 3 - Ajout de fonctionnalités à Magasin

3.a)	Cette étape a pour but d'implémenter une fonction dans notre classe Magasin tout en utilisant un objet de type Produit, défini précédemment. Cette fonction s'appelle Magasin::addProduit(). En donnant les différents attributs en paramètre, cette fonction va créer un objet dynamique de type Produit et va l'ajouter au vecteur std::vector<Produit*> _produit.

3.b)	La méthode permettant d'afficher tous les produits du magasin est définie dans Magasin::displayProd(). La surcharge de l'opérateur << nous permet d'afficher tous les produits les uns à la suite des autres en utilisant std::cout. L'usage de pointeur nous oblige à définir des référence associées à l'adresse de nos pointeur pour retourner la valeur de notre variable et non pas son adresse.

3.c)	La méthode permettant d'afficher un produit en particulier est définie par la fonction Magasin::displayProdFiltre(). En donnant en paramètre le nom du produit que l'on cherche, cette 		fonction nour renvoie le produit ainsi que sa description, sa quantité et son prix unitaire. Elle repose sur le même principe que la fonction Magasin::displayProd(). Si le nom du produit 	donné en paramètre n'est pas dans la liste des produits (contenue dans _produit), la fonction nous renvoie qu'aucun article a été trouvé à ce nom.

3.d)	La méthode permettant de mettre à jour la quantité d'un produit selectionné par son nom est définie par la fonction Magasin::setQtt(). La valeur de la quantite donnée en paramètre à cette fonction et celle du nom du produit concerné permet de modifier la quantité du produit voulu en parcourant à l'aide d'un boucle les différents titres des produits répertoriés. Si l'article n'est pas en stock, cela sera précisé.



#### Question 4 - Création de la classe Client

4.a)	Afin de créer la classe Client, nous allons définir les attributs privés. Un client est défini par un nom (std::string), un prenom (std::string), un panier (std::vector<Produit*>), et également un id (int) car deux personnes différentes peuvent avoir le même nom et le même prénom. Tous ces attributs peuvent être définis à partir de la librairie standard sauf le _panier. La classe Client doit donc hériter de la classe Produit.

Nous avons défini ici un seul constructeur qui prendra en paramètres un nom et un prénom. Le panier est vide par défaut et l'id sera distribué automatiquement de façon unique à chaque client.

Les getters de cette classe sont définis dans le Client.cpp

4.b)	La fonction Client::addtoCart prend en paramètre un Produit* et l'ajoute au vecteur _panier à l'aide de la fonction push_back(). 

4.c)	La fonction Client::clearCart() permet tout simplement de de vider le _panier à l'aide de la fonction clear() des vecteurs.

4.d)	La fonction Client::changeQuantity() permet de modifier la quantiter d'un article à l'aider du titre de l'article et de la nouvelle quantité de celui-ci en les donnant en paramètres à la fonction. On réutilise la fonction Produit::setQuantite() de la classe Produit.

4.e)	La fonction Client::deleteProduit() permet de supprimer un article du panier en donnant en paramètre le nom du produit concerné. Cette fonction repose sur la fonction erase() liée aux vecteurs.

4.f)	Tout comme pour le Produit, la surcharge de l'opérateur << permet d'afficher directement à la suite d'un std::cout le nom, le prénom, le numéro et le panier d'un client ainsi que le prix total des articles présents dans le panier.



#### Question 5 - Ajout des fonctionnalités au Magasin

5.a)	Tout comme pour ajouter un nouveau Produit, la fonction Magasin::addClient() permet d'ajouter un client dans la variable membre _client. On donne en paramètres de cette fonction le nom et le prénom d'un client, on lui attribue automatiquement un numéro de client et on créé un objet Client qui sera ajouter dans la variable membre.

5.b)	La fonction Magasin::displayClients() utilise la surccharge de l'opérateur <<  dans des boucles afin d'afficher directement le nom, le prénom le numéro du client ainsi que son panier et le prix total de ses articles.

5.c)	La fonction Magasin::displayClientFiltre() permet d'afficher un client en particulier. Nous avons surchargé cette fonction afin que l'on puisse afficher un client en donnant son nom et son prénom en paramètre, ou bien simplement son ID.

5.d)	La fonction Magasin::addtoPanier() est la fonction qui nous a donné le plus de fil à retordre. Cette fonction permet de récupérer une copie du produit donné en paramètre afin de la copier dans le panier du client. L'utilisation d'allocution dynamique ici était nécessaire afin de ne pas lier directement le produit du panier avec le produit du magasin (même quantité dans les deux). Désormais, cette fonction permet d'ajouter un article en x quantité et retirer cette quantité des stocks du magasin

5.e)	La fonction Magasin::deleteProdPanier() permet de supprimer un article du panier à l'aide de la fonction Client::deleteProduit() de la classe Client. Elle permet également de remettre dans les stocks du magasin la quantité de l'article du panier. En surchargeant cette fonction, on peut supprimer un article du panier d'un client à partir de son ID, mais aussi de son no et de son prénom.

5.f)	La fonction Magasin::changeQttPanier() permet d'ajuster la quantité d'un article du panier à l'aide de la fonction Produit::setQuantite() de la classe Produit. Elle permet aussi de mettre à jour la quantité d'articles disponibles dans les stocks du magasin et de changer la quantité d'article du panier. Nous avons surcharger cette fonction pour l'utiliser avec un ID ou bien un nom et un prenom.



#### Question 6 - Création de la classe Commande

6.a)	La classe Client est défini par un numéro de commande (int), un client (Client*), un panier (std::vector<Produit*>) et un status(std::string). 
Bien que cela ne soit pas demandé, nous avons défini les getters de cette classe et le setter setStatus() afin de pouvoir le modifier.

6.b)	Comme précédemment, la surcharge de l'opérateur << permet d'afficher à la suite d'un std::cout le client créateur de la commande, le numéro de commande de celle-ci ainsi que ce qu'il a commandé et le status de la commande. Le status est défini par défaut par "En cours de validation" et peut-être changé par la suite.



#### Question 7 - Ajout des fonctionnalités à Magasin

7.a)	La fonction Magasin::validerCommande() permet de définir le status d'une commande de "En cours de validation" à "Validée" en prenant le numéro de la commande à valider en paramètre.

7.b)	La fonction Magasin::statusCommande() permet de changer l'etat d'une commande à partir d'un menu en prenant en paramètre le numéro de la commande concernée et un chiffre correspondant à un état de commande.

7.c)	La fonction Magasin::displayCommandes() permet d'afficher toutes les commandes grâce à la surcharge de l'opérateur <<. Grâce à une boucle, toutes les commandes seront affichées.

7.d)	La fonction Magasin::displayCommandesFiltre() permet d'afficher les commandes d'un client en particulier. En surchargeant cette fonction, nous pouvons donner en paramètre l'id d'un client ou son nom et son prénom. Nous avons également ajouter une fonction permettant d'afficher une commande précise à l'aide de son numéro, la fonction Magasin::displayCommandeNum()



#### Question 8 - Questions subsidiaires

8.a)	Dans le fichier main.cpp nous avons reproduit une interface graphique sur terminal afin de faciliter la prise en main du programme et de le rendre plus facile d'utilisation notamment pour des personnes n'ayant jamais fait de programmation. Ce menu sera affiché tant que l'utilisateur n'aura pas rentré 0 dans le menu principal. Evidemment, il existe encore quelques exceptions pour certains menus qui peuvent ammener le terminal à être forcé de quitter le programme, malgré le fait que nous ayons essayé de couvrir la plupart de ces possibilités.

8.b)	Cette question nous a posé beaucoup de problèmes concernant l'enregistrement des données dans des fichiers. En effet, nous sommes parvenus à enregistrer des données dans des fichiers mais celles-ci étaient éronnées et ne correspondaient pas du tout aux valeurs rentrées sur le terminal. Nous avons fait le choix de ne pas les implémenter dans notre code car nous préfferons repartir de zéro sur notre programme plutot que d'avoir des informations éronnées enregistrées même s'il est vrai que, dans un vrai magasin, les données sont enregistrées et restituées de façon fidèle et précise.


## Conclusion

	En résumé, ce programme nous aura permis de nous familiariser avec la notion d'héritage et d'allocution dynamique à l'aide de pointeurs et de références. La création d'un programme destinée à être utilisé dans le commerce se doit d'être facile à prendre en main, limiter les exceptions et de répondre aux besoin de personnes comme des caissiers par exemple. C'est typiquement le genre de programme que pour nous demander un supermarché voulant créer un base de donnée à faible coup. De nombreuses fonctions pourraient encore être implémentées comme par exemple une fonction utilisable en période de soldes et applicant un réduction sur une certaine gamme de produit.