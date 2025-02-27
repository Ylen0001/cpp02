_______EX03_______

1 - Créer la classe Point

- Déclarer Fixed x et Fixed y
- Le constructeur doit initialiser deux objets Fixed, et pour ça il faut utiliser la liste d'initialisation : Point::Point() : x(0), y(0) {}. Le fait que x(0) et y(0) soit placé avant {} autorise à initialiser x et y. Si on le faisait sous le format :
Point::Point()
{
    this->x = Fixed(0);  // ❌ ERREUR : Impossible de modifier un `const`
    this->y = Fixed(0);  // ❌ ERREUR
}

2 - BSP (Binary Space Partitionning)

Le BSP est utilise notamment dans les moteurs graphiques de jeux videos afin de definir les objets visibles sur un axe donne. 
Ce qui permet d'optimiser les ressources requises pour afficher uniquement la partie visible d'un environnement.

On dispose de 4 donnees (vecteurs x/y) : Les trois sommets du triangle, et le vecteur de l'objet.

On va tout d'abord essayer d'identifier si nous avons bien un triangle avec les trois sommets. On utilise un produit vectoriel en 2D
Si le resultat est positif alors C est a gauche du segment AB
Si il est negatif alors il est a droite
Si le resultat est nul, alors ABC sont allignes.

Desormais, pour savoir si vecteur de l'objet est une position interieure au triangle, il suffit de refaire ce calcul 3 fois
Une fois par segment du triangle. Si le point est du meme cote de chaque segment, il est a l'interieur du triangle.


___ NOTIONS IMPORTANTES DE L'EX02 ___

1 - La declaration de fonctions de Point.hpp dans un fichier Bsp.cpp
2 - L'acces, via les getter, a des variables constantes d'une classe dans des fonctions membres.
3 - L'utilisation du BSP pour identifier l'emplacement d'un point sur un plan 2D par rapport a 3 autres vecteurs de position.
4 - L'utilisation d'une instance d'une classe au sein d'une autre classe, et les notions relatives aux constructeurs/destructeurs.
5 - L'initialisation par liste d'initialisation des attributs const d'une classe, puisqu'ils ne peuvent etre modifies plus tard.
6 - La forme canonique (Constructeur par defaut, constructeur avec parametre, surcharge d'operateur et destructeur.)

IMPORTANT : J'ai des doutes sur la surcharge d'operateur '=' au sein de la classe Point. Je l'ai void puisque cela me parait 
interdit de pouvoir attribuer une valeur a une variable const membre d'une classe. Il faudra demander pour s'en assurer. Sinon l'ensemble semble correct. 
PS : Effectivement, il semble bien que cela etait demande dans le sujet juste pour mettre en valeur que cela etait impossible.

PS2 : Peut-etre qu'il faut passer la fonction bsp en static bool. Il faut se pencher sur le sujet. 