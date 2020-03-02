

#ifndef INF2_LABO1_TEMPS_H
#define INF2_LABO1_TEMPS_H

#include <ctime>
#include <iostream>

using uint = unsigned  int;

class Temps {
    //operateur de comparaison
    friend bool operator<(const Temps& lhs, const Temps& rhs);
    friend bool operator>(const Temps& lhs, const Temps& rhs);
    friend bool operator<=(const Temps& lhs, const Temps& rhs);
    friend bool operator>=(const Temps& lhs, const Temps& rhs);
    friend bool operator==(const Temps& lhs, const Temps& rhs);
    friend bool operator!=(const Temps& lhs, const Temps& rhs);

    //operateur arithmetique
    friend Temps operator+(Temps lhs, const Temps& rhs);
    friend Temps operator-(Temps lhs, const Temps& rhs);

    //operateur de flux
    friend std::ostream& operator<<(std::ostream& lhs, const Temps& rhs);

public:
    //constructor
    Temps();
    Temps( time_t temps );
    Temps( uint heure, uint minute, uint seconde = 0 );

    //getters
    uint getHeure()   const ;
    uint getMinute()  const ;
    uint getSeconde() const ;

    //setters
    void setHeure( uint heure );
    void setMinute( uint minute );
    void setseconde( uint seconde );

    //operateur incrementation et decrementation
    Temps& operator++();
    Temps  operator++(int);
    Temps& operator--();
    Temps  operator--(int);

    //operateur d'affectation
    Temps&operator+=(const Temps& rhs);
    Temps&operator-=(const Temps& rhs);

    //operateur de conversion
    // a definir

private:
    //champs
    uint heure;
    uint minute;
    uint seconde;
};


#endif //INF2_LABO1_TEMPS_H
