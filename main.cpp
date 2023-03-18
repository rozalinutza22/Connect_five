#include <winbgim.h>
#include <stdlib.h>
#include "include/functions.h"

using namespace std;

int main() {
    initwindow(800,600);
    desenareTabla();

    while (!iesireDinTabla) {
        if (iesireDinTabla == true)
            return 0;

    creareBulina();

    if (contorizarePiese >= 9) {
        if (contorizarePiese % 2 == 0) {
            if (este5InLiniepeLinie(TablaDeJoc, linieSpecialaJucator2, coloanaSpecialaJucator2, 2) ||
                este5InLiniepeColoana(TablaDeJoc, linieSpecialaJucator2, coloanaSpecialaJucator2, 2) ||
                este5InLiniepeDiagonalaSpreDreapta(TablaDeJoc, linieSpecialaJucator2, coloanaSpecialaJucator2, 2) ||
                este5InLiniepeDiagonalaSpreDreapta2(TablaDeJoc, linieSpecialaJucator2, coloanaSpecialaJucator2, 2) ||
                este5InLiniepeDiagonalaSpreStanga(TablaDeJoc, linieSpecialaJucator2, coloanaSpecialaJucator2, 2) ||
                este5InLiniepeDiagonalaSpreStanga2(TablaDeJoc, linieSpecialaJucator2, coloanaSpecialaJucator2, 2)) {

                    afisareCastigator2(2);
                    iesireDinTabla = true;
                   // return 0;
            }else if (este5InLiniepeLinie(TablaDeJoc, linieSpecialaJucator1, coloanaSpecialaJucator1, 1) ||
                este5InLiniepeColoana(TablaDeJoc, linieSpecialaJucator1, coloanaSpecialaJucator1, 1) ||
                este5InLiniepeDiagonalaSpreDreapta(TablaDeJoc, linieSpecialaJucator1, coloanaSpecialaJucator1, 1) ||
                este5InLiniepeDiagonalaSpreDreapta2(TablaDeJoc, linieSpecialaJucator1, coloanaSpecialaJucator1, 1) ||
                este5InLiniepeDiagonalaSpreStanga(TablaDeJoc, linieSpecialaJucator1, coloanaSpecialaJucator1, 1) ||
                este5InLiniepeDiagonalaSpreStanga2(TablaDeJoc, linieSpecialaJucator1, coloanaSpecialaJucator1, 1)) {

                    afisareCastigator1(1);
                    iesireDinTabla = true;
                   // return 0;
                }
        }else if (contorizarePiese % 2 != 0) {
            if (este5InLiniepeLinie(TablaDeJoc, linieSpecialaJucator1, coloanaSpecialaJucator1, 1) ||
                este5InLiniepeColoana(TablaDeJoc, linieSpecialaJucator1, coloanaSpecialaJucator1, 1) ||
                este5InLiniepeDiagonalaSpreDreapta(TablaDeJoc, linieSpecialaJucator1, coloanaSpecialaJucator1, 1) ||
                este5InLiniepeDiagonalaSpreDreapta2(TablaDeJoc, linieSpecialaJucator1, coloanaSpecialaJucator1, 1) ||
                este5InLiniepeDiagonalaSpreStanga(TablaDeJoc, linieSpecialaJucator1, coloanaSpecialaJucator1, 1) ||
                este5InLiniepeDiagonalaSpreStanga2(TablaDeJoc, linieSpecialaJucator1, coloanaSpecialaJucator1, 1)) {

                    afisareCastigator1(1);
                    iesireDinTabla = true;
                   // return 0;
                }else if (este5InLiniepeLinie(TablaDeJoc, linieSpecialaJucator2, coloanaSpecialaJucator2, 2) ||
                este5InLiniepeColoana(TablaDeJoc, linieSpecialaJucator2, coloanaSpecialaJucator2, 2) ||
                este5InLiniepeDiagonalaSpreDreapta(TablaDeJoc, linieSpecialaJucator2, coloanaSpecialaJucator2, 2) ||
                este5InLiniepeDiagonalaSpreDreapta2(TablaDeJoc, linieSpecialaJucator2, coloanaSpecialaJucator2, 2) ||
                este5InLiniepeDiagonalaSpreStanga(TablaDeJoc, linieSpecialaJucator2, coloanaSpecialaJucator2, 2) ||
                este5InLiniepeDiagonalaSpreStanga2(TablaDeJoc, linieSpecialaJucator2, coloanaSpecialaJucator2, 2)) {

                    afisareCastigator2(2);
                    iesireDinTabla = true;
                }
            }
        }
    }

   getch();
   closegraph();
   return 0;
}

