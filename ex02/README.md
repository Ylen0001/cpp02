_______EX02_______

Notions :

Fixed const	b(Fixed(5.05f) * Fixed(2));

1 - Pourquoi utiliser b(Fixed(5.05f) * Fixed(2)) plutôt que b(0,05f * 2) ?

D'une part pour voir si on a bien codé la surcharge d'opérateur *. Si ce n'était pas le cas, ça ne compilerait pas.
Ensuite, observation intéressante : Pour créer b, on utilise le copy constructor. Et en paramètre on lui envoie 2 instances de Fixed. Une qui utilise le float constructor, l'autre le int. 
Le calcul des valeur en paramètres de la fonction est effectué avant l'appel à la fonction. Donc, voilà ce qu'il se passe en détail.

On appelle le copy constructor pour créer b. 
En paramètres du copy constructor, le calcul de Fixed(5.05f) * Fixed(2) est effectué avant l'appel à la fonction.
Donc, Fixed(5.05f) est un appel au float constructor, qui renvoie un &Fixed.
Fixed(2) est un appel au int constructor, qui renvoie également un &Fixed.
Les deux Fixed sont multiplié via la surcharge d'opérateur *.
Les deux Fixed passent par le destructor (les calculs sont terminés).
Fixed b vaut la multiplication des deux Fixed en paramètres.

2 - La différence entre la pré et la post incrémentation

Fixed& Fixed::operator++() ----> Pré 

Fixed Fixed::operator++(int) --> Post

La seule raison pour laquelle on met un int anonyme en paramètres est pour une simple question de synthaxe pour identifier la post incrémentation. Ce n'est qu'un indicateur, on n'utilise pas le int dans la fonction.

3 - This

This permet :

- D'éviter les confusions, si jamais la fonction prend un paramètre qui à le même nom que la variable de l'instance de classe. Ça rend le tout plus lisible.
- Sinon, on l'utilise pour renvoyer un pointeur sur l'objet de classe.
ex : return *this.

