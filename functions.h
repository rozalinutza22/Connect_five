#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <winbgim.h>
#include <stdlib.h>

using namespace std;

#define MAX 40
#define FUNDAL CYAN

extern int stanga,sus,width,height,latura;
extern int numar;
extern bool iesireDinTabla;

extern int TablaDeJoc[MAX][MAX];
extern int contorizarePiese;

extern int linieSpecialaJucator1;
extern int coloanaSpecialaJucator1;

extern int linieSpecialaJucator2;
extern int coloanaSpecialaJucator2;

void creareBulina();
void desenareTabla();
bool este5InLiniepeLinie(int TablaDeJoc[MAX][MAX], int linie_curenta, int coloana_curenta, int indicator_jucator);
bool este5InLiniepeColoana(int TablaDeJoc[MAX][MAX], int linie_curenta, int coloana_curenta, int indicator_jucator);
bool este5InLiniepeDiagonalaSpreDreapta(int TablaDeJoc[MAX][MAX], int linie_curenta, int coloana_curenta, int indicator_jucator);
bool este5InLiniepeDiagonalaSpreDreapta2(int TablaDeJoc[MAX][MAX], int linie_curenta, int coloana_curenta, int indicator_jucator);
bool este5InLiniepeDiagonalaSpreStanga(int TablaDeJoc[MAX][MAX], int linie_curenta, int coloana_curenta, int indicator_jucator);
bool este5InLiniepeDiagonalaSpreStanga2(int TablaDeJoc[MAX][MAX], int linie_curenta, int coloana_curenta, int indicator_jucator);
void afisareCastigator1(int indicator);
void afisareCastigator2(int indicator);

#endif // FUNCTIONS_H
