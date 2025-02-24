_______ EX00 _______

Article 1

1 - Les floats sont interprétés différemment des ints, qui le sont en binaire. On rencontre donc de temps en temps des inexactitudes lorsque l'on manipule des floats.

2 - Accuracy vs Precision : Les entiers sont exactes, il représentent des valeurs précises sans erreurs
Les floats sont précis, mais pas toujours exact, puisqu'ils contiennent des fois des arrondis. 

3 - Certains floats ne peuvent pas être représentés exactement en binaire, comme 1/3 en base 10, qui contient forcément des "erreurs" d'arrondis. Donc, certaines fois, utiliser "==" pour comparer deux floats peut donner des résultats inattendus.

En conclusion, les ints sont comme des briques : solides et précis mais incapables de représenter des formes fines.
Les floats eux sont comme de la pâte à modeler : flexibles, mais incapables de former des formes net avec précision. 

Les floats sont puissants, mais nécessitent d'être utilisé avec prudence pour éviter des erreurs d'arrondis et comportement inattendus dans les comparaisons et les calculs.

------------------------------------------------------------

Article 2

1 - La norme la plus courante pour la représentation binaire des floats est l'IEEE-754. Elle définit la composition des floats(4 octets) et des doubles(8 octets) en 3 parties :

Un bit de signe (+/-).
Un exposant (l'ordre de grandeur, le nombre de fois qu'un chiffre est multiplié par lui même).
Une mantisse (Qui contient les chiffres significatifs).

2 - Epsilon

Pour éviter les erreurs d'arrondis pendant des tests "==", il est commun d'utiliser la formule Epsilon. Cependant, cette méthode est imparfaite parce que c'est une valeur fixe, et que selon l'ordre des grandeurs des floats comparés, elle peut devenir obsolète. On préferera donc comparer la proximité relative en utilisant des chiffre significatifs plus qu'une valeur fixe Epsilon.

#define EPSILON 1.0e-7
#define flt_equals(a, b) (fabs((a)-(b)) < EPSILON)

3 - Overflow

Si overflow sur un int : Attribution d'une valeur aléatoire.
Sur un float : -♾️ / ♾️
On peut donc tester la validité d'un float avec  :
	if (val == INFINITY)

4 - Soutraction proche / Addition large

Soustraire deux floats proches peut faire que deux bits significatifs s'annulent. Provoquant une réelle perte de précision. Pour éviter ça, on évite les soustractions entre valeurs proches, en réarrangeant les calculs. Somme de séries.

Lorsque l'on additionne des nombres de grandeurs très différentes, les petits termes peuvent être écrasés. 
Solution : Additionner du plus petit au plus grand.

5 - Règle générale 

Éviter les feedback loops (itérations successives utilisant un résultat imprécis.)
Privilégier les recalculs directs plutôt que des modifications incrémentales.
Utiliser des entiers si les valeurs doivent être exactes (Par exemple, stocker des fractions sous formes de numérateurs/dénominateurs)

Exemple : plutôt que de stocker 1/2, 1/3, 1/4 en flottants, stockez simplement le dénominateur et calculez la fraction au besoin :

float fraction = 1.0 / denom;

Cela réduit les erreurs d’arrondi.

**** Conclusion ****

1 - Ne jamais comparer directement deux flottants
2 - Se méfier des overflows/écarts trop importants entre deux float values
3 - Réarranger les calculs pour éviter les pertes de précision
4 - Utiliser des entiers de préference pour garantir une exactitude.

Ces principes sont primordieux en calcul numérique, modélisation scientifique et programmation embedded.

______ Forme Canonique ______

La forme canonique en C++ désigne l'ensemble minimale suffisant de méthodes spéciales pour gérer correctement la création, la copie, la destruction et l'affectations des objets d'une classe.

En C++98 on parle de 4 méthodes, 5 en C++11

I - Le constructeur : C'est une fonction spéciale qui est automatiquement appelé à la création d'une instance de classe. Il sert à initialiser les valeurs de l'objet, et peut recevoir des paramêtres. SI aucun constructeur n'est défini, le compilateur en fait un par défaut.

II - Le constructeur de copie : Si on crée une copie d'une instance dont les ressources sont sur la stack (non dynamique), un constructeur de copie par défaut sert donc à prendre les valeurs de l'instance pour les copier dans une autre.
Cependant si certaines valeurs sont allouées dynamiquement (via pointeurs par exemple) sur la heap, la copie par défaut p eut merder et créer des fuites de mémoires ou des double free. Il faut donc en hardcoder un adapté.

Il est intéressant de réfléchir à si l'on souhaite mettre le constructeur en privé, ou en public.

III - La surcharge d'opérateur d'affectation.

Par défaut, on peut faire :

Fixed A;
Fixed B(A);

Mais dans le cas où on a alloué dynamiquement des variables de la classe, on utilisera une surcharge d'opérateur pour décider de comment allouer dynamiquement les variables de la copie. Pour éviter les doubles free etc...

Fixed A;
Fixed B;

B = A;

Pour ce qui est de la définition de la surcharge d'opérateur dans le .cpp, il s'agit juste de définir le rôle de '='.

____ Const ____

Mettre const après la définition d'une fonction membre permet d'indiquer la méthode n'agit pas sur l'objet sur lequel elle est appelée.

int getRawBits(void) const;


