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

    // Opérateurs arithmètiques
    friend Temps operator+(Temps lhs, const Temps& rhs);
    friend Temps operator-(Temps lhs, const Temps& rhs);

    // Opérateur de flux
    friend std::ostream& operator<<(std::ostream& lhs, const Temps& rhs);

public:
    // Constructeurs
    Temps();
    Temps( time_t temps );
    Temps( uint heure, uint minute, uint seconde = 0 );

    // Sélecteurs
    uint getHeure()   const ;
    uint getMinute()  const ;
    uint getSeconde() const ;

    // Modificateurs
    void setHeure( uint heure );
    void setMinute( uint minute );
    void setSeconde( uint seconde );

    // Opérateurs d'incrementation et de decrementation
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
