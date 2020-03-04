#ifndef INF2_LABO1_TEMPS_H
#define INF2_LABO1_TEMPS_H

#include <ctime>
#include <iostream>

using uint = unsigned  int;

class Temps {
    // Operateurs de comparaison
    friend bool operator<(const Temps& lhs, const Temps& rhs);
    friend bool operator>(const Temps& lhs, const Temps& rhs);
    friend bool operator<=(const Temps& lhs, const Temps& rhs);
    friend bool operator>=(const Temps& lhs, const Temps& rhs);
    friend bool operator==(const Temps& lhs, const Temps& rhs);
    friend bool operator!=(const Temps& lhs, const Temps& rhs);

    // Operateurs arithmetiques
    friend Temps operator+(Temps lhs, const Temps& rhs);
    friend Temps operator-(Temps lhs, const Temps& rhs);

    // Operateurs de flux
    friend std::ostream& operator<<(std::ostream& lhs, const Temps& rhs);

public:
    // Constructeurs
    Temps();
    Temps( time_t temps );
    Temps( uint heure, uint minute, uint seconde = 0 );

    // Getters
    uint getHeure()   const ;
    uint getMinute()  const ;
    uint getSeconde() const ;

    // Setters
    void setHeure( uint heure );
    void setMinute( uint minute );
    void setSeconde( uint seconde );

    // Operateurs d'incrementation et de decrementation
    Temps& operator++();
    Temps  operator++(int);
    Temps& operator--();
    Temps  operator--(int);

    // Operateurs d'affectation
    Temps&operator+=(const Temps& rhs);
    Temps&operator-=(const Temps& rhs);

    // Operateur de conversion de type
    operator double() const;

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
