/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire no. 1 - classe Temps
 Fichier     : Temps.cpp
 Auteur(s)   : Paul Reeve, Kylian Bourcoud, Marco Maziero
 Date        : 06.03.2020

 But         : Implémentation complète de la classe Temps. Contient l'implémentation de toutes
               fonctions de surcharge d'opérateurs demandées, ainsi que les constructeurs et les accesseurs.

 Remarque(s) : Information complémentaire :
                    - Il n y a aucun contrôle des valeurs données au constructeur ou aux modificateurs

                    - Le constructeur prenant comme paramètre une variable de type "time_t" utilise
                      une fonction nomée "atoi()" qui permet de transformer le buffer de "char"
                      en nombre entier. Ce nombre entier est ensuite transformé en "unsigned int".
                      (Source : http://www.cplusplus.com/reference/cstdlib/atoi/)

                    - "setw" de la librairie "iomanip" est utilisée pour afficher correctement
                       le bon nombre de caractères lors de l'affichage d'un temps.

                    - Les opérateurs d'incrémentation appelle l'opérateur += et celui de décrémentation
                      le -= afin d'éviter une redondance du code.

 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
*/

#include "Temps.h"
#include <iomanip>
using namespace std;

/*------------------------------------------------------------------------------------------*/

// Initialisation static const
const uint Temps::MAX_HEURE_DANS_JOUR     = 24;
const uint Temps::MAX_MINUTE_DANS_HEURE   = 60;
const uint Temps::MAX_SECONDE_DANS_MINUTE = 60;

// Opérateurs de comparaison

bool operator<(const Temps& lhs, const Temps& rhs) {
    return  lhs.heure   < rhs.heure     ||
            lhs.minute  < rhs.minute    ||
            lhs.seconde < rhs.seconde;
}

bool operator>(const Temps& lhs, const Temps& rhs) {
    return (rhs < lhs);
}

bool operator<=(const Temps& lhs, const Temps& rhs) {
    return !(rhs < lhs);
}

bool operator>=(const Temps& lhs, const Temps& rhs) {
    return !(lhs < rhs);
}

bool operator==(const Temps& lhs, const Temps& rhs) {
    return  lhs.heure   == rhs.heure    &&
            lhs.minute  == rhs.minute   &&
            lhs.seconde == rhs.seconde;
}

bool operator!=(const Temps& lhs, const Temps& rhs) {
    return !(lhs == rhs);
}

/*------------------------------------------------------------------------------------------*/

// Opérateurs arithmètique

Temps operator+(Temps lhs, const Temps& rhs) {
    lhs += rhs;
    return lhs;
}

Temps operator-(Temps lhs, const Temps& rhs) {
    lhs -= rhs;
    return lhs;
}

/*------------------------------------------------------------------------------------------*/

// Opérateur de flux

std::ostream &operator<<(std::ostream& lhs, const Temps& rhs) {
    return lhs << setfill('0')
               << setw(2) << rhs.heure      << ":"
               << setw(2) << rhs.minute     << ":"
               << setw(2) << rhs.seconde;
}

/*------------------------------------------------------------------------------------------*/

// Constructeurs

Temps::Temps() {
    heure = minute = seconde = 0;
}

Temps::Temps(time_t temps) {
    char h[4], m[4], s[4];
    strftime(h, sizeof(h), "%H", localtime(&temps));
    strftime(m, sizeof(m), "%M", localtime(&temps));
    strftime(s, sizeof(s), "%S", localtime(&temps));
    heure   = uint(atoi(h));
    minute  = uint(atoi(m));
    seconde = uint(atoi(s));
}

Temps::Temps(uint heure, uint minute, uint seconde) : heure(heure), minute(minute), seconde(seconde) {}

/*------------------------------------------------------------------------------------------*/

// Sélécteurs

uint Temps::getHeure() const {
    return heure;
}

uint Temps::getMinute() const {
    return minute;
}

uint Temps::getSeconde() const {
    return seconde;
}

/*------------------------------------------------------------------------------------------*/

// Modificateurs

void Temps::setHeure(uint heure) {
    this->heure = heure;
}

void Temps::setMinute(uint minute) {
    this->minute = minute;
}

void Temps::setSeconde(uint seconde) {
    this->seconde = seconde;
}

/*------------------------------------------------------------------------------------------*/

// Opérateurs d'incrémentation et décrémentation

Temps& Temps::operator++() {
    *this += Temps(0,0,1);
    return *this;
}

Temps Temps::operator++(int) {
    Temps temp =  *this;
    *this   += Temps(0,0,1);
    return temp;
}

Temps& Temps::operator--() {
    *this -= Temps(0,0,1);
    return *this;
}

Temps Temps::operator--(int) {
    Temps temp =  *this;
    *this   -= Temps(0,0,1);
    return temp;
}

/*------------------------------------------------------------------------------------------*/

// Opérateurs d'affectations

Temps& Temps::operator+=(const Temps& rhs) {
    heure   += rhs.heure;
    minute  += rhs.minute;
    seconde += rhs.seconde;

    minute  += seconde / MAX_SECONDE_DANS_MINUTE;
    heure   += minute  / MAX_MINUTE_DANS_HEURE;

    heure   %= MAX_HEURE_DANS_JOUR;
    minute  %= MAX_MINUTE_DANS_HEURE;
    seconde %= MAX_SECONDE_DANS_MINUTE;

    return *this;
}

Temps& Temps::operator-=(const Temps& rhs) {
    heure   += MAX_HEURE_DANS_JOUR;
    minute  += MAX_MINUTE_DANS_HEURE;
    seconde += MAX_SECONDE_DANS_MINUTE;

    heure   -= rhs.heure;
    minute  -= rhs.minute;
    seconde -= rhs.seconde;

    if( !(seconde / MAX_SECONDE_DANS_MINUTE) )
        minute -= 1;

    if( !(minute / MAX_MINUTE_DANS_HEURE) )
        heure -= 1;

    heure   %= MAX_HEURE_DANS_JOUR;
    minute  %= MAX_MINUTE_DANS_HEURE;
    seconde %= MAX_SECONDE_DANS_MINUTE;



    return *this;
}

/*------------------------------------------------------------------------------------------*/

// Opérateur de conversion de type
Temps::operator double() const {
    return double(heure)
           + (double(minute) / MAX_MINUTE_DANS_HEURE)
           + (double(seconde) / (MAX_SECONDE_DANS_MINUTE * MAX_SECONDE_DANS_MINUTE));
}











