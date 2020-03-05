
#include <stdio.h>
#include "Temps.h"

using namespace std;

int main() {
    Temps t1(1, 30, 27),
          t2(8, 8, 8);

    cout << (double)t1 << endl;
    return EXIT_SUCCESS;
}

//tester overflow heure Minute Seconde