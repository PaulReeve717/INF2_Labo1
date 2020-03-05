#include "Temps.h"
#include <iomanip>
using namespace std;

/*------------------------------------------------------------------------------------------*/

//initialisation static const
const uint Temps::MAX_HEURE_DANS_JOUR     = 24;
const uint Temps::MAX_MINUTE_DANS_HEURE   = 60;
const uint Temps::MAX_SECONDE_DANS_MINUTE = 60;

// Operateur de comparaison

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

// Operateur arithmetique

Temps operator+(Temps lhs, const Temps& rhs) {
    lhs += rhs;
    return lhs;
}

Temps operator-(Temps lhs, const Temps& rhs) {
    lhs -= rhs;
    return lhs;
}

/*------------------------------------------------------------------------------------------*/

// Operateur de flux

std::ostream &operator<<(std::ostream& lhs, const Temps& rhs) {
    return lhs << setfill('0')
               << setw(2) << rhs.heure      << ":"
               << setw(2) << rhs.minute     << ":"
               << setw(2) << rhs.seconde;
}

/*------------------------------------------------------------------------------------------*/

// Constructeur

Temps::Temps() {
    heure = minute = seconde = 0;
}

Temps::Temps(time_t temps) {
    char h[2], m[2], s[2];
    strftime(h, sizeof(h), "%H", localtime(&temps));
    strftime(m, sizeof(m), "%M", localtime(&temps));
    strftime(s, sizeof(s), "%S", localtime(&temps));
    heure   = uint(atoi(h));
    minute  = uint(atoi(m));
    seconde = uint(atoi(s));
}

Temps::Temps(uint heure, uint minute, uint seconde) : heure(heure), minute(minute), seconde(seconde) {}

/*------------------------------------------------------------------------------------------*/

// Sélecteurs

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

// Opérateur incrementation et décrementation

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

// Operateur d'affectation

Temps& Temps::operator+=(const Temps& rhs) {
    heure   += rhs.heure;
    minute  += rhs.minute;
    seconde += rhs.seconde;

    heure   += minute  / MAX_MINUTE_DANS_HEURE;
    minute  += seconde / MAX_SECONDE_DANS_MINUTE;

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

    minute  -= MAX_SECONDE_DANS_MINUTE / seconde;
    heure   -= MAX_MINUTE_DANS_HEURE   / minute ;  ;

    heure   %= MAX_HEURE_DANS_JOUR;
    minute  %= MAX_MINUTE_DANS_HEURE;
    seconde %= MAX_SECONDE_DANS_MINUTE;



    return *this;
}

/*------------------------------------------------------------------------------------------*/

// Operateur de conversion de type
Temps::operator double() const {
    return double(heure)
           + (double(minute) / MAX_MINUTE_DANS_HEURE)
           + (double(seconde) / (MAX_SECONDE_DANS_MINUTE * MAX_SECONDE_DANS_MINUTE));
}











