

#include "Temps.h"

/*------------------------------------------------------------------------------------------*/

//operateur de comparaison

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

//operateur arithmetique

Temps operator+(Temps lhs, const Temps& rhs) {
    return Temps();
}

Temps operator-(Temps lhs, const Temps& rhs) {
    return Temps();
}

/*------------------------------------------------------------------------------------------*/

//operateur de flux

std::ostream &operator<<(std::ostream& lhs, const Temps& rhs) {
    return lhs;
}

/*------------------------------------------------------------------------------------------*/

//constructor

Temps::Temps() {

}

Temps::Temps(time_t temps) {

}

Temps::Temps(uint heure, uint minute, uint seconde) {

}

/*------------------------------------------------------------------------------------------*/

//getters

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

//setters

void Temps::setHeure(uint heure) {

}

void Temps::setMinute(uint minute) {

}

void Temps::setseconde(uint seconde) {

}

/*------------------------------------------------------------------------------------------*/

//operateur incrementation et decrementation

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

//operateur d'affectation

Temps& Temps::operator+=(const Temps& rhs) {
    return *this;
}

Temps& Temps::operator-=(const Temps& rhs) {
    return *this;
}












