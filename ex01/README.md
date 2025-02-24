____ EX01 ____

Pour convertir un int en nombre à virgule fixe, il faut bitshift :

this->value = value << nb_Bits;

But de l'exercice :

1 - Transformer un int, et un float en nombre à virgule fixe. 
Pourquoi?
Parce que c'est plus safe, plus rapide, et ça consomme moins de faire des calculs sur des nombres à virgule fixe, plutôt que sur des floats.

***************** IMPORTANT ! *****************

Pour ce faire, si il s'agît d'un int, on bitshift de nb_Bits. Ça revient à simuler une virgule sans jamais utiliser de float/double.
C'est un peu comme une clef de cryptage 
---> 1(Normal) = 256(en fixe)
---> 2.5(Normal) = 2.5 * 256 = 640 en fixe.

Donc, de cette manière, pour récupérer la valeur d'un nombre à virgule fixe, il suffit de le diviser par 256 (Dans le cas ou on a nb_Bits = 8, pour "annuler" le bitshift).

Donc dans notre exemple, pour retrouver la vraie valeur :

this->value = value << nb_Bits; --> Nombre to virgule fixe
	float realValue = (float)this->value / (1 << nb_Bits);
Et dans notre cas, avec nb_Bits = 8, on peut aussi écrire
	float realValue = (float)this->value / 256;

***********************************************

On utilise donc beaucoup les nombres à virgule fixe en embedded (Sur les systèmes disposant de peu de ram), pour le graphisme (moins couteux en terme de ressources), en audio etc...

2 - Surcharge de l'opérateur <<

Par défaut std::cout << obj ne permet pas d'afficher l'instance d'une classe que l'on a nous-même définie.
Donc, on va surcharger cet opérateur au sein de notre classe, afin qu'il puisse afficher des variables de notre instance de classe. Attention, on déclare le prototype de cette fonction à l'exterieur de la classe dans le hpp.

Cela permet un code plus clair et plus pratique et est utile pour les logs le debogage et l'affichage dans les fichiers.

	std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

std::ostream& : (output stream) ostream est une classe de <iostream> qui gère la sortie des données. C'est la classe qui contient les objets cout, cerr et ofstream(écriture dans un fichier.) Il s'agit du type de retour de la fonction. Elle renvoie une réference sur un objet de la classe ostream.

operator<< ; Définit comment afficher un objet Fixed.

(std::ostream &out, const Fixed& fixed) ; Prend un flux en entrée (cout, cerr, cofstream), et une réference sur un objet fixed à afficher.

CONCLUSION : La surcharge d'opérateur << permet donc d'afficher fixed sans souci. 


----------------------- EN RÉSUMÉ -----------------------------

I - Les nombres à virgules fixe 

Ils permettent de stocker des nombres décimaux sans avoir à utiliser des floats/doubles, ce qui évite les erreurs fréquentes qu'impliquent la représentation binaire de floats/double, et leur consommation de mémoire. 
Un nombre à virgule fixe est stocké comme un entier, mais interprété differemment. 

Pour stocker une valeur décimale dans un entier à virgule, on bitshift et on arrondi avec roundf().

II - La surcharge de l'opérateur '='

Permet d'éviter une copie par défaut d'une instance de classe. Utile notamment dans le cas où l'instance comporte des données allouées dynamiquement.

III - La surcharge de l'opérateur '<<'

Permet d'afficher les variables d'un objet.

IV - Les constructeurs

Le compilateur génère un constructeur par défaut pour chaque classe. Cependant, on peut avoir besoin d'initialiser une instance de classe avec des données différentes que celle par défaut. On peut donc créer des constructeurs qui prennent en paramètre la data que l'on souhaite initialiser différemment au sein de cette dernière.

V - Le constructeur de copy

Permet de créer une copie d'une instance d'objet déjà initiliasée.

En bref, les points importants de l'exercice sont :

✅ Comprendre le principe des nombres en virgule fixe.
✅ Savoir convertir un nombre (int ou float) vers un format fixe et inversement.
✅ Utiliser les surcharges d’opérateurs (<<, =) pour simplifier le code.
✅ Écrire des constructeurs et un destructeur proprement.
✅ Éviter les erreurs de troncature et assurer un bon arrondi (roundf()).
✅ Utiliser intelligemment le décalage binaire (<<, >>) pour optimiser les calculs.


