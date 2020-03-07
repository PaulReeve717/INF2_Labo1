/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire no. 1 - classe Temps
 Fichier     : Temps.h
 Auteur(s)   : Paul Reeve, Kylian Bourcoud, Marco Maziero
 Date        : 06.03.2020

 But         : Définition de la classe Temps ainsi que de ses variables membre privées
               et de ses fonction membres et amies (constructeurs, fonctions de
               surcharge d'opérateurs, accesseurs)

 Remarque(s) : Informations complémentaires :
                    - L'alias "uint" a été crée pour remplacer la notation "unsigned int" afin d'économiser
                      de la place et gagner en visibilité.

                    - Des variables statiques constantes ont élé crées pour exprimer le nombre d'heures
                      dans une jour, le nombre de minutes dans une heur et le nombre de secondes dans
                      une minute. Ceci dans le but de faciliter un éventuel changement de données.

 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
*/

#ifndef INF2_LABO1_TEMPS_H
#define INF2_LABO1_TEMPS_H

#include <ctime>
#include <iostream>

using uint = unsigned  int;

class Temps {
    // Opérateurs de comparaison
    friend bool operator<(const Temps& lhs, const Temps& rhs);
    friend bool operator>(const Temps& lhs, const Temps& rhs);
    friend bool operator<=(const Temps& lhs, const Temps& rhs);
    friend bool operator>=(const Temps& lhs, const Temps& rhs);
    friend bool operator==(const Temps& lhs, const Temps& rhs);
    friend bool operator!=(const Temps& lhs, const Temps& rhs);

    // Opérateurs arithmétiques
    friend Temps operator+(Temps lhs, const Temps& rhs);
    friend Temps operator-(Temps lhs, const Temps& rhs);

    // Opérateur de flux
    friend std::ostream& operator<<(std::ostream& lhs, const Temps& rhs);

public:
    // Constructeurs
    Temps();
    Temps( time_t temps );
    Temps( uint heure, uint minute, uint seconde = 0 );

    // Sélécteurs
    uint getHeure()   const ;
    uint getMinute()  const ;
    uint getSeconde() const ;

    // Modificateurs
    void setHeure( uint heure );
    void setMinute( uint minute );
    void setSeconde( uint seconde );

    // Opérateurs d'incrémentation et de décrémentation
    Temps& operator++();
    Temps  operator++(int);
    Temps& operator--();
    Temps  operator--(int);

    // Opérateurs d'affectation
    Temps&operator+=(const Temps& rhs);
    Temps&operator-=(const Temps& rhs);

    // Opérateur de conversion de type
    explicit operator double() const;

private:
    // Champs
    uint heure,
         minute,
         seconde;

    //champs statiques
    static const uint MAX_HEURE_DANS_JOUR,
                      MAX_MINUTE_DANS_HEURE,
                      MAX_SECONDE_DANS_MINUTE;
};


#endif // INF2_LABO1_TEMPS_H
