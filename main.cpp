
#include <stdio.h>
#include "Temps.h"

using namespace std;

int main() {
    Temps t1(5, 5, 5),
          t2(8, 8, 8);

    cout << t1 << endl;
    cout << t1 + t2 << endl;
    cout << t1 - t2 << endl;
    cout << t2 - t1 << endl;
    return EXIT_SUCCESS;
}

//tester overflow heure Minute Seconde