/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire no. 1 - classe Temps
 Fichier     : main.cpp
 Auteur(s)   : Paul Reeve, Kylian Bourcoud, Marco Maziero
 Date        : 06.03.2020

 But         : Contient les protocoles de test des constructeurs, fonctions de surcharge d'opérateurs
               et accesseurs de la classe Temps.

 Remarque(s) : Informations complémentaires :
                    - Les 8 variables de type Temps utilisées pour les tests sont :
                            - t1 qui vaut : "00:00:00"
                            - t2 qui vaut : "10:11:12"
                            - t3 qui vaut : "05:05:05"
                            - t4 qui vaut : "13:31:31"
                            - t5 qui vaut : "01:30:00"
                            - t6 qui vaut : l'heure actuelle du système
                            - tPetit qui vaut  : "10:10:10"
                            - tPetit2 qui vaut : "10:10:10"
                            - tGrand qui vaut  : "11:11:11"

                    - La librairie "iomanip" est utilisée pour l'affichage des temps
                      convertis en type double.
 Compilateur : MinGW 6.3.0
 -----------------------------------------------------------------------------------
*/

#include "Temps.h"
#include <iomanip>

using namespace std;

int main() {
    // -------------------------------------------------------------------

    time_t heureActuelle;
    time(&heureActuelle);
    Temps t1,
          t2( 10,11,12),
          t3(5,5, 5),
          t4(13,31,31),
          t5 = {1, 30},
          t6 = heureActuelle,
          tPetit(10,10,10),
          tGrand(11, 11, 11);

    Temps tPetit2 = tPetit;

    cout << "Creation du temps t1 : " << t1 << endl
         << "Creation du temps t2 : " << t2 << endl
         << "Creation du temps t3 : " << t3 << endl
         << "Creation du temps t4 : " << t4 << endl
         << "Creation du temps t5 : " << t5 << endl
         << "Creation du temps t6 : " << t6 << endl
         << "Creation du temps tPetit  : " << tPetit << endl
         << "Creation du temps tPetit2 : " << tPetit2 << endl
         << "Creation du temps tGrand  : " << tGrand << endl;

    cout << endl;

    // -------------------------------------------------------------------

    cout << "Tests selecteur" << endl;
    cout << "===============" << endl;

    cout << "selection seconde : " << t2.getSeconde() << endl;
    cout << "selection minute  : " << t2.getMinute()  << endl;
    cout << "selection heure   : " << t2.getHeure()   << endl;
    cout << endl;

    // -------------------------------------------------------------------

    cout << "Tests modificateurs" << endl;
    cout << "===================" << endl;

    t2.setSeconde(30);
    t2.setMinute(30);
    t2.setHeure(12);

    cout << "modification seconde : " << t2.getSeconde() << endl;
    cout << "modification minute  : " << t2.getMinute()  << endl;
    cout << "modification heure   : " << t2.getHeure()   << endl;

    cout << endl;

    // -------------------------------------------------------------------

    cout << "Tests operateurs de comparaison" << endl;
    cout << "===============================" << endl;
    cout << boolalpha;

    cout << "tPetit < tGrand  : " << (tPetit < tGrand) << endl;
    cout << "tPetit > tGrand  : " << (tPetit > tGrand) << endl;
    cout << "tPetit <= tGrand : " << (tPetit <= tGrand) << endl;
    cout << "tPetit >= tGrand : " << (tPetit >= tGrand) << endl;
    cout << "tPetit == tGrand : " << (tPetit == tGrand) << endl;
    cout << "tPetit == tPetit2 : " << (tPetit == tPetit2) << endl;
    cout << "tPetit != tGrand : " << (tPetit != tGrand) << endl;

    tPetit.setHeure(tPetit.getHeure() + 1);
    cout << "(Meme heure) tPetit < tGrand  : " << (tPetit < tGrand) << endl;
    cout << "(Meme heure) tPetit == tGrand : " << (tPetit == tGrand) << endl;
    tPetit.setMinute(tPetit.getMinute() + 1);

    cout << "(Meme heure & minute) tPetit < tGrand  : " << (tPetit < tGrand) << endl;
    cout << "(Meme heure & minute) tPetit == tGrand : " << (tPetit == tGrand) << endl;

    cout << noboolalpha;
    cout << endl;

    // -------------------------------------------------------------------

    cout << "Tests operateurs d'affectation" << endl;
    cout << "==============================" << endl;

    t2 += t3;
    cout << "add/affect   sans depassement : " << t2 << endl;
    t2 -= t3;
    cout << "soust/affect sans depassement : " << t2 << endl;
    t2 += t4;
    cout << "add/affect   avec depassement : " << t2 << endl;
    t2 -= t4;
    cout << "soust/affect avec depassement : " << t2 << endl;

    cout << endl;

    // -------------------------------------------------------------------

    cout << "Tests operateurs arithmetiques" << endl;
    cout << "==============================" << endl;

    cout << "addition     : " << t2 + t4 <<  endl;
    cout << "soustraction : " << t2 - t4 <<  endl;

    cout << endl;

    // -------------------------------------------------------------------

    cout << "Tests operateurs d'incrementation et de decrementation" << endl;
    cout << "======================================================" << endl;

    cout << "Pre-decrementation  (pre)  : " << --t1 << endl;
    cout << "Pre-decrementation  (post) : " << t1   << endl;
    cout << "Pre-incrementation  (pre)  : " << ++t1 << endl;
    cout << "Pre-incrementation  (post) : " << t1   << endl;
    cout << "Post-decrementation (pre)  : " << t1-- << endl;
    cout << "Post-decrementation (post) : " << t1   << endl;
    cout << "Post-incrementation (pre)  : " << t1++ << endl;
    cout << "Post-incrementation (post) : " << t1   << endl;

    cout << endl;

    // -------------------------------------------------------------------

    cout << "Tests operateur de flux" << endl;
    cout << "=======================" << endl;

    cout << "Variable t1 : " << t1 << endl
         << "Variable t2 : " << t2 << endl
         << "Variable t3 : " << t3 << endl
         << "Variable t4 : " << t4 << endl
         << "Variable t5 : " << t5 << endl
         << "Variable t6 : " << t6 << endl
         << "Variable tPetit  : " << tPetit << endl
         << "Variable tPetit2 : " << tPetit2 << endl
         << "Variable tGrand  : " << tGrand << endl;

    cout << endl;

    // -------------------------------------------------------------------

    cout << "Tests operateur de conversion" << endl;
    cout << "=============================" << endl;

    cout << fixed << setprecision(3)
         << "Variable t1 : " << (double)t1 << endl
         << "Variable t2 : " << (double)t2 << endl
         << "Variable t3 : " << (double)t3 << endl
         << "Variable t4 : " << (double)t4 << endl
         << "Variable t5 : " << (double)t5 << endl
         << "Variable t6 : " << (double)t6 << endl
         << "Variable tPetit  : " << (double)tPetit << endl
         << "Variable tPetit2 : " << (double)tPetit2 << endl
         << "Variable tGrand  : " << (double)tGrand << endl;

    cout << endl;

    // -------------------------------------------------------------------

    return EXIT_SUCCESS;
}

// TODO : Tester overflow heure Minute Seconde