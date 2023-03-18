#include "../include/functions.h"

int stanga,sus,width,height,latura;
int numar = MAX;
bool iesireDinTabla = false;

int TablaDeJoc[MAX][MAX];
int contorizarePiese = 1;

int linieSpecialaJucator1;
int coloanaSpecialaJucator1;

int linieSpecialaJucator2;
int coloanaSpecialaJucator2;


void creareBulina() {
    int linia, coloana;
    int x, y;
    int x1, y1, x2, y2;
    int xmijloc, ymijloc;

    if(ismouseclick(WM_LBUTTONDOWN)) {
       clearmouseclick(WM_LBUTTONDOWN);
       x=mousex();
       y=mousey();

        if (!(x >= stanga && x <= stanga + width && y >= sus && y <= sus + height))
            iesireDinTabla = true;
        else {
            linia = (y - sus) / latura + 1;
            coloana = (x - stanga) / latura + 1;

            if (contorizarePiese % 2 != 0 && TablaDeJoc[linia][coloana] == 0) {

                TablaDeJoc[linia][coloana] = 1;
                linieSpecialaJucator1 = linia;
                coloanaSpecialaJucator1 = coloana;

                setcolor(FUNDAL);
                setfillstyle(SOLID_FILL, FUNDAL);
                x1 = stanga + latura * (coloana - 1);
                y1 = sus + latura * (linia - 1);
                x2 = x1 + latura;
                y2 = y1 + latura;

                xmijloc = (x1 + x2) / 2;
                ymijloc = (y1 + y2) / 2;

                bar(xmijloc - 5, ymijloc - 5, xmijloc + 5, ymijloc + 5);

                setcolor(LIGHTRED);
                setfillstyle(SOLID_FILL, LIGHTRED);
                fillellipse(xmijloc, ymijloc, 5, 5);
                ++contorizarePiese;

            }else if (contorizarePiese % 2 == 0 && TablaDeJoc[linia][coloana] == 0) {

                TablaDeJoc[linia][coloana] = 2;
                linieSpecialaJucator2 = linia;
                coloanaSpecialaJucator2 = coloana;

                setcolor(FUNDAL);
                setfillstyle(SOLID_FILL, FUNDAL);

                x1 = stanga + latura * (coloana - 1);
                y1 = sus + latura * (linia - 1);
                x2 = x1 + latura;
                y2 = y1 + latura;

                xmijloc = (x1 + x2) / 2;
                ymijloc = (y1 + y2) / 2;

                bar(xmijloc - 5, ymijloc - 5, xmijloc + 5, ymijloc + 5);

                setcolor(LIGHTRED);
                setfillstyle(SOLID_FILL, LIGHTGREEN);
                fillellipse(xmijloc, ymijloc, 5, 5);
                ++contorizarePiese;
            }
        }
     }
 }

void desenareTabla() {
    int i, j;
    width = 500;
    height = 600;
    latura = width / numar;
    sus = (getmaxy()-width) / 2;
    stanga = (getmaxx() - height) / 2;
    setbkcolor(LIGHTGRAY);
    clearviewport();
    setcolor(MAGENTA);

    for (i = 1; i <= numar; i++)
        for (j = 1; j <= numar; j++)
            rectangle(stanga + latura * (i - 1), sus + latura * (j - 1), stanga + latura * i, sus + latura * j);
}

bool este5InLiniepeLinie(int TablaDeJoc[MAX][MAX], int linie_curenta, int coloana_curenta, int indicator_jucator) {
    if (TablaDeJoc[linie_curenta][coloana_curenta - 1] == indicator_jucator &&
        TablaDeJoc[linie_curenta][coloana_curenta - 2] == indicator_jucator &&
        TablaDeJoc[linie_curenta][coloana_curenta - 3] == indicator_jucator &&
        TablaDeJoc[linie_curenta][coloana_curenta - 4] == indicator_jucator &&
        coloana_curenta - 1 > 0 && coloana_curenta - 2 > 0 && coloana_curenta - 3 > 0 &&
        coloana_curenta - 4 >= 0)
            return true;

    if (TablaDeJoc[linie_curenta][coloana_curenta + 1] == indicator_jucator &&
        TablaDeJoc[linie_curenta][coloana_curenta + 2] == indicator_jucator &&
        TablaDeJoc[linie_curenta][coloana_curenta + 3] == indicator_jucator &&
        TablaDeJoc[linie_curenta][coloana_curenta + 4] == indicator_jucator &&
        coloana_curenta + 1 < MAX && coloana_curenta + 2 < MAX && coloana_curenta + 3 < MAX &&
        coloana_curenta + 4 <= MAX)
            return true;

    return false;
}

bool este5InLiniepeColoana(int TablaDeJoc[MAX][MAX], int linie_curenta, int coloana_curenta, int indicator_jucator) {
    if (TablaDeJoc[linie_curenta - 1][coloana_curenta] == indicator_jucator &&
        TablaDeJoc[linie_curenta - 2][coloana_curenta] == indicator_jucator &&
        TablaDeJoc[linie_curenta - 3][coloana_curenta] == indicator_jucator &&
        TablaDeJoc[linie_curenta - 4][coloana_curenta] == indicator_jucator &&
        linie_curenta - 1 > 0 && linie_curenta - 2 > 0 && linie_curenta - 3 > 0 &&
        linie_curenta - 4 >= 0)
            return true;

    if (TablaDeJoc[linie_curenta + 1][coloana_curenta] == indicator_jucator &&
        TablaDeJoc[linie_curenta + 2][coloana_curenta] == indicator_jucator &&
        TablaDeJoc[linie_curenta + 3][coloana_curenta] == indicator_jucator &&
        TablaDeJoc[linie_curenta + 4][coloana_curenta] == indicator_jucator &&
        linie_curenta + 1 < MAX && linie_curenta + 2 < MAX && linie_curenta + 3 < MAX &&
        linie_curenta + 4 <= MAX)
            return true;

    return false;
}


bool este5InLiniepeDiagonalaSpreDreapta(int TablaDeJoc[MAX][MAX], int linie_curenta, int coloana_curenta, int indicator_jucator) {
    //caz 1, piesa e prima din coltul dreapta al diagonalei
    //linie_curenta - 1 sau coloana_curenta - 1 verifica acel caz in care iesim din matrice
    if ((linie_curenta - 1 < 0 || coloana_curenta - 1 < 0) || (TablaDeJoc[linie_curenta - 1][coloana_curenta - 1] != indicator_jucator)) {
        int linie2 = linie_curenta + 1;
        int linie3 = linie2 + 1;
        int linie4 = linie3 + 1;
        int linie5 = linie4 + 1;
        int coloana2 = coloana_curenta + 1;
        int coloana3 = coloana2 + 1;
        int coloana4 = coloana3 + 1;
        int coloana5 = coloana4 + 1;

        if (linie2 <= MAX && linie3 <= MAX && linie4 <= MAX && linie5 <= MAX &&
            coloana2 <= MAX && coloana3 <= MAX && coloana4 <= MAX && coloana5 <= MAX) {
            if (TablaDeJoc[linie2][coloana2] == indicator_jucator && TablaDeJoc[linie3][coloana3] == indicator_jucator &&
                TablaDeJoc[linie4][coloana4] == indicator_jucator && TablaDeJoc[linie5][coloana5] == indicator_jucator)
                    return true;
        }return false;

    //cazul 2, atunci cand piesa e a 2 a din capatul de sus stanga al diagonalei

    }else if ((linie_curenta - 2 < 0 || coloana_curenta - 2 < 0) || (TablaDeJoc[linie_curenta - 2][coloana_curenta - 2] != indicator_jucator)) {
        if (TablaDeJoc[linie_curenta - 1][coloana_curenta - 1] == indicator_jucator) {
            int linie3 = linie_curenta + 1;
            int linie4 = linie3 + 1;
            int linie5 = linie4 + 1;
            int coloana3 = coloana_curenta + 1;
            int coloana4 = coloana3 + 1;
            int coloana5 = coloana4 + 1;

            if (linie3 <= MAX && linie4 <= MAX && linie5 <= MAX && coloana3 <= MAX
                && coloana4 <= MAX && coloana5 <= MAX) {
                if (TablaDeJoc[linie3][coloana3] == indicator_jucator &&
                    TablaDeJoc[linie4][coloana4] == indicator_jucator &&
                    TablaDeJoc[linie5][coloana5] == indicator_jucator)
                        return true;
            }

        }else return false;

        //cazul 3, piesa e a treia din capatul de sus stanga al diagonalei

    }else if ((linie_curenta - 3 < 0 || coloana_curenta - 3 < 0) || (TablaDeJoc[linie_curenta - 3][coloana_curenta - 3] != indicator_jucator)) {
        if (TablaDeJoc[linie_curenta - 1][coloana_curenta - 1] == indicator_jucator
            && TablaDeJoc[linie_curenta - 2][coloana_curenta - 2] == indicator_jucator) {
            int linie1 = linie_curenta + 1;
            int linie2 = linie1 + 1;
            int coloana1 = coloana_curenta + 1;
            int coloana2 = coloana1 + 1;

            if (linie1 <= MAX && linie2 <= MAX && coloana1 <= MAX && coloana2 <= MAX) {
                if (TablaDeJoc[linie1][coloana1] == indicator_jucator && TablaDeJoc[linie2][coloana2] == indicator_jucator)
                    return true;
            }

        }else return false;

        //cazul 4, piesa e a 4 a din capatul de sus stanga al diagonalei

    }else if ((linie_curenta - 4 < 0 || coloana_curenta - 4 < 0) || (TablaDeJoc[linie_curenta - 4][coloana_curenta - 4] != indicator_jucator)) {
        if (TablaDeJoc[linie_curenta - 1][coloana_curenta - 1] == indicator_jucator &&
            TablaDeJoc[linie_curenta - 2][coloana_curenta - 2] == indicator_jucator
            && TablaDeJoc[linie_curenta - 3][coloana_curenta - 3] == indicator_jucator) {
            if (linie_curenta + 1 <= MAX && coloana_curenta + 1 <= MAX && TablaDeJoc[linie_curenta+1][coloana_curenta+1] == indicator_jucator)
                return true;

        }else return false;

        //cazul 5, piesa e ultima din diagonala ce porneste din stanga sus
    }else if ((linie_curenta - 5 < 0 || coloana_curenta - 5 < 0) || (TablaDeJoc[linie_curenta - 5][coloana_curenta - 5] != indicator_jucator)) {
        if (TablaDeJoc[linie_curenta - 1][coloana_curenta - 1] == indicator_jucator &&
            TablaDeJoc[linie_curenta - 2][coloana_curenta - 2] == indicator_jucator &&
            TablaDeJoc[linie_curenta - 3][coloana_curenta - 3] == indicator_jucator &&
            TablaDeJoc[linie_curenta - 4][coloana_curenta - 4] == indicator_jucator) {
                return true;
        }else return false;
    }
}

bool este5InLiniepeDiagonalaSpreDreapta2(int TablaDeJoc[MAX][MAX], int linie_curenta, int coloana_curenta, int indicator_jucator) {
    int linie2 = linie_curenta + 1;
    int linie3 = linie2 + 1;
    int linie4 = linie3 + 1;
    int linie5 = linie4 + 1;
    int coloana2 = coloana_curenta + 1;
    int coloana3 = coloana2 + 1;
    int coloana4 = coloana3 + 1;
    int coloana5 = coloana4 + 1;

    if (linie2 < MAX && linie3 < MAX && linie4 < MAX && linie5 <= MAX &&
        coloana2 < MAX && coloana3 < MAX && coloana4 < MAX && coloana5 <= MAX) {
        if (TablaDeJoc[linie2][coloana2] == indicator_jucator &&
            TablaDeJoc[linie3][coloana3] == indicator_jucator &&
            TablaDeJoc[linie4][coloana4] == indicator_jucator &&
            TablaDeJoc[linie5][coloana5] == indicator_jucator)
            return true;
    }

    return false;
}

bool este5InLiniepeDiagonalaSpreStanga(int TablaDeJoc[MAX][MAX], int linie_curenta, int coloana_curenta, int indicator_jucator) {
    //caz 1, piesa e prima din coltul dreapta al diagonalei
    //linie_curenta - 1 sau coloana_curenta - 1 verifica acel caz in care iesim din matrice
    if ((linie_curenta - 1 < 0 || coloana_curenta + 1 > MAX) || (TablaDeJoc[linie_curenta - 1][coloana_curenta + 1] != indicator_jucator)) {
        int linie2 = linie_curenta + 1;
        int linie3 = linie2 + 1;
        int linie4 = linie3 + 1;
        int linie5 = linie4 + 1;
        int coloana2 = coloana_curenta - 1;
        int coloana3 = coloana2 - 1;
        int coloana4 = coloana3 - 1;
        int coloana5 = coloana4 - 1;

        if (linie2 <= MAX && linie3 <= MAX && linie4 <= MAX && linie5 <= MAX &&
            coloana2 >= 0 && coloana3 >= 0 && coloana4 >= 0 && coloana5 >= 0) {
            if (TablaDeJoc[linie2][coloana2] == indicator_jucator && TablaDeJoc[linie3][coloana3] == indicator_jucator &&
                TablaDeJoc[linie4][coloana4] == indicator_jucator && TablaDeJoc[linie5][coloana5] == indicator_jucator)
                    return true;
        }return false;

    //cazul 2, atunci cand piesa e a 2 a din capatul de sus dreapta al diagonalei

    }else if ((linie_curenta - 2 < 0 || coloana_curenta + 2 > MAX) || (TablaDeJoc[linie_curenta - 2][coloana_curenta + 2] != indicator_jucator)) {
        if (TablaDeJoc[linie_curenta - 1][coloana_curenta + 1] == indicator_jucator) {
            int linie3 = linie_curenta + 1;
            int linie4 = linie3 + 1;
            int linie5 = linie4 + 1;
            int coloana3 = coloana_curenta - 1;
            int coloana4 = coloana3 - 1;
            int coloana5 = coloana4 - 1;

            if (linie3 <= MAX && linie4 <= MAX && linie5 <= MAX && coloana3 >= 0
                && coloana4 >= 0 && coloana5 >= 0) {
                if (TablaDeJoc[linie3][coloana3] == indicator_jucator &&
                    TablaDeJoc[linie4][coloana4] == indicator_jucator &&
                    TablaDeJoc[linie5][coloana5] == indicator_jucator)
                        return true;
            }

        }else return false;

        //cazul 3, piesa e a treia din capatul de sus dreapta al diagonalei

    }else if ((linie_curenta - 3 < 0 || coloana_curenta + 3 > MAX) || (TablaDeJoc[linie_curenta - 3][coloana_curenta + 3] != indicator_jucator)) {
        if (TablaDeJoc[linie_curenta - 1][coloana_curenta + 1] == indicator_jucator
            && TablaDeJoc[linie_curenta - 2][coloana_curenta + 2] == indicator_jucator) {
            int linie1 = linie_curenta + 1;
            int linie2 = linie1 + 1;
            int coloana1 = coloana_curenta - 1;
            int coloana2 = coloana1 - 1;

            if (linie1 <= MAX && linie2 <= MAX && coloana1 >= 0 && coloana2 >= 0) {
                if (TablaDeJoc[linie1][coloana1] == indicator_jucator && TablaDeJoc[linie2][coloana2] == indicator_jucator)
                    return true;
            }

        }else return false;

        //cazul 4, piesa e a 4 a din capatul de sus dreapta al diagonalei

    }else if ((linie_curenta - 4 < 0 || coloana_curenta + 4 > MAX) || (TablaDeJoc[linie_curenta - 4][coloana_curenta + 4] != indicator_jucator)) {
        if (TablaDeJoc[linie_curenta - 1][coloana_curenta + 1] == indicator_jucator &&
            TablaDeJoc[linie_curenta - 2][coloana_curenta + 2] == indicator_jucator
            && TablaDeJoc[linie_curenta - 3][coloana_curenta + 3] == indicator_jucator) {
            if (linie_curenta + 1 <= MAX && coloana_curenta - 1 >= 0 && TablaDeJoc[linie_curenta + 1][coloana_curenta - 1] == indicator_jucator)
                return true;

        }else return false;

        //cazul 5, piesa e ultima din diagonala ce porneste din dreapta sus
    }else if ((linie_curenta - 5 < 0 || coloana_curenta - 5 < 0) || (TablaDeJoc[linie_curenta - 5][coloana_curenta - 5] != indicator_jucator)) {
        if (TablaDeJoc[linie_curenta - 1][coloana_curenta + 1] == indicator_jucator &&
            TablaDeJoc[linie_curenta - 2][coloana_curenta + 2] == indicator_jucator &&
            TablaDeJoc[linie_curenta - 3][coloana_curenta + 3] == indicator_jucator &&
            TablaDeJoc[linie_curenta - 4][coloana_curenta + 4] == indicator_jucator) {
                return true;
        }else return false;
    }
}

bool este5InLiniepeDiagonalaSpreStanga2(int TablaDeJoc[MAX][MAX], int linie_curenta, int coloana_curenta, int indicator_jucator) {
    int linie1 = linie_curenta + 1;
    int linie2 = linie1 + 1;
    int linie3 = linie2 + 1;
    int linie4 = linie3 + 1;

    int coloana1 = coloana_curenta - 1;
    int coloana2 = coloana1 - 1;
    int coloana3 = coloana2 - 1;
    int coloana4 = coloana3 - 1;

    if (linie1 < MAX && linie2 < MAX && linie3 < MAX && linie4 <= MAX &&
        coloana1 > 0 && coloana2 > 0 && coloana3 > 0 && coloana4 >= 0) {
            if (TablaDeJoc[linie1][coloana1] == indicator_jucator &&
                TablaDeJoc[linie2][coloana2] == indicator_jucator &&
                TablaDeJoc[linie3][coloana3] == indicator_jucator &&
                TablaDeJoc[linie4][coloana4] == indicator_jucator )
                    return true;
    }

    return false;
}


void afisareCastigator1(int indicator) {
    char sirScor[10] = "Player 1";
    setcolor(BLACK);
    outtextxy(100, 20, sirScor);

    int n;
    n=sprintf (sirScor, "  wins!");
    setcolor(BLACK);

    outtextxy(150, 20, sirScor);
}

void afisareCastigator2(int indicator) {
    char sirScor[16] = "Player 2";
    setcolor(BLACK);
    outtextxy(100, 20, sirScor);

    int n;
    n=sprintf (sirScor, "wins!");
    setcolor(BLACK);

    outtextxy(160, 20, sirScor);
}

