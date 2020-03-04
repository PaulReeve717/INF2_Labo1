#include "Temps.h"

/*------------------------------------------------------------------------------------------*/

//initialisation static const
const uint Temps::MAX_HEURE_DANS_JOUR     = 24;
const uint Temps::MAX_MINUTE_DANS_HEURE   = 60;
const uint Temps::MAX_SECONDE_DANS_MINUTE = 60;

// Operateur de comparaison

bool operator<(const Temps& lhs, const Temps& rhs) {
    return false;
}

bool operator>(const Temps& lhs, const Temps& rhs) {
    return false;
}

bool operator<=(const Temps& lhs, const Temps& rhs) {
    return false;
}

bool operator>=(const Temps& lhs, const Temps& rhs) {
    return false;
}

bool operator==(const Temps& lhs, const Temps& rhs) {
    return false;
}

bool operator!=(const Temps& lhs, const Temps& rhs) {
    return false;
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
    return lhs;
}

/*------------------------------------------------------------------------------------------*/

// Constructor

Temps::Temps() {

}

Temps::Temps(time_t temps) {

}

Temps::Temps(uint heure, uint minute, uint seconde) {

}

/*------------------------------------------------------------------------------------------*/

// Getters

uint Temps::getHeure() const {
    return 0;
}

uint Temps::getMinute() const {
    return 0;
}

uint Temps::getSeconde() const {
    return 0;
}

/*------------------------------------------------------------------------------------------*/

// Setters

void Temps::setHeure(uint heure) {

}

void Temps::setMinute(uint minute) {

}

void Temps::setSeconde(uint seconde) {

}

/*------------------------------------------------------------------------------------------*/

// Operateur incrementation et decrementation

Temps& Temps::operator++() {
    return *this;
}

Temps Temps::operator++(int) {
    return Temps();
}

Temps& Temps::operator--() {
    return *this;
}

Temps Temps::operator--(int) {
    return Temps();
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
    heure -= rhs.heure;
    minute -= rhs.minute;
    return *this;
}

/*------------------------------------------------------------------------------------------*/

// Operateur de conversion de type
Temps::operator double() const {
    return 0.0;
}










