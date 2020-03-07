
#include <stdio.h>
#include "Temps.h"

using namespace std;

int main() {
    Temps t1(23, 59 , 59),
          t2( 10,11,12),
          t3(5,5,5),
          t4(13,31,31);


    // Tests constructeur & affichage

    // Tests selecteur
    cout << "Tests selecteur" << endl;
    cout << "===============" << endl;

    cout << "selection seconde : " << t2.getSeconde() << endl;
    cout << "selection minute  : " << t2.getMinute()  << endl;
    cout << "selection heure   : " << t2.getHeure()   << endl;
    cout << endl;

    // Tests modificateurs
    cout << "Tests selecteur" << endl;
    cout << "===============" << endl;

    t2.setSeconde(30);
    t2.setMinute(30);
    t2.setHeure(12);

    cout << "selection seconde : " << t2 << endl;
    cout << endl;

    // Tests opérateurs de comparaison

    cout << "Tests operateurs d'affectation" << endl;
    cout << "==============================" << endl;

    t2 += t3;
    cout << "add/affect sans depassement   : " << t2 << endl;
    t2 -= t3;
    cout << "soust/affect sans depassement : " << t2 << endl;
    t2 += t4;
    cout << "add/affect avec depassement   : " << t2 << endl;
    t2 -= t4;
    cout << "soust/affect avec depassement : " << t2 << endl;
    cout << endl;


    cout << "Tests operateurs arithmetiques" << endl;
    cout << "==============================" << endl;


    cout << "addition     : " << t2 + t4 <<  endl;
    cout << "soustraction : " << t2 - t4 <<  endl;
    cout << endl;


    cout << "Tests operateurs d'ncrémentation et de decrementation" << endl;
    cout << "=====================================================" << endl;

    cout << "Pre-incrementation  (pre)  : " << ++t1 << endl;
    cout << "Pre-incrementation  (post) : " << t1   << endl;
    cout << "Pre-decrementation  (pre)  : " << --t1 << endl;
    cout << "Pre-decrementation  (post) : " << t1   << endl;
    cout << "Post-incrementation (pre)  : " << t1++ << endl;
    cout << "Post-incrementation (post) : " << t1   << endl;
    cout << "Post-decrementation (pre)  : " << t1-- << endl;
    cout << "Post-decrementation (post) : " << t1   << endl;

    cout << endl;

    return EXIT_SUCCESS;
}

//tester overflow heure Minute Seconde