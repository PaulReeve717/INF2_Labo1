# INF2_Labo1 | Gestion d'un temps 00:00:00

Implémenter une classe Temps permettant de modéliser des temps.
Un temps se caractérise par 3 données membres (de type unsigned int) : les heures (0 – 23), les minutes (0 – 59) et les secondes (0 – 59).
Quelle que soit l'opération réalisée, un temps doit toujours rester compris dans l'intervalle [00:00:00; 23:59:59].

La classe doit mettre à disposition :
- Un constructeur par défaut permettant d'initialiser les heures, minutes et secondes à
zéro

- Un constructeur à 1 paramètre (de type time_t) permettant, par exemple, de construire
un temps correspondant à l'heure courante du système

- Un constructeur à trois paramètres (heures, minutes et secondes dans cet ordre). Les
paramètres heures et minutes doivent obligatoirement être renseignés à l'appel du constructeur; le paramètre secondes lui est facultatif. S'il n'est pas renseigné à l'appel du constructeur, cela signifie 0 secondes.

- Des accesseurs pour les trois données membres

- Tous les opérateurs de comparaison possibles (<,<=, >, >=, == et !=)

- Un opérateur ++ (en version pré-incrémentation et post-incrémentation)1

- Un opérateur -- (en version pré-décrémentation et post-décrémentation)1

- Un opérateur + permettant d'additionner deux temps et retournant un temps

- Un opérateur +=, permettant de faire, par ex : t1 += t2

- Un opérateur - permettant de soustraire deux temps et retournant un temps

- Un opérateur -=, permettant de faire, par ex : t1 -= t2

- Un opérateur permettant d'afficher un temps t au format "hh:mm:ss" (par ex 23:05:55)
en écrivant cout << t

- Un opérateur de conversion permettant de convertir un objet de type Temps en temps
décimal exprimé en heures. Exemple : la conversion de 01:30:00 doit donner 1.5 [h].
1 Incrémenter, respectivement décrémenter, un temps signifie ajouter, respectivement soustraire, une seconde.