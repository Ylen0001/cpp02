_______EX03_______

1 - Créer la classe Point

- Déclarer Fixed x et Fixed y
- Le constructeur doit initialiser deux objets Fixed, et pour ça il faut utiliser la liste d'initialisation : Point::Point() : x(0), y(0) {}. Le fait que x(0) et y(0) soit placé avant {} autorise à initialiser x et y. Si on le faisait sous le format :
Point::Point()
{
    this->x = Fixed(0);  // ❌ ERREUR : Impossible de modifier un `const`
    this->y = Fixed(0);  // ❌ ERREUR
}

