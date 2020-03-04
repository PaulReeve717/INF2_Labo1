
#include <stdio.h>
#include "Temps.h"

int main() {
    Temps t(5, 1, 22);
    std::cout << t;
    return EXIT_SUCCESS;
}

//tester overflow heure Minute Seconde