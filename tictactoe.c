#include <stdlib.h>
#include <stdio.h>

#include "tictactoe.h"
void zapelnij(char plansza[3][3]){
    int i,j;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            plansza[i][j]=' ';
        }
    }
}

/* FUNKCJA WPISUJE DO TABLICY ODPOWIEDNI ZNAK WYBRANY PRZEZ GRACZA */
void aktualizujPlansze(const int x, const int y, char plansza[3][3], char znak){
    plansza[x][y] = znak;
}

/* FUNKCJA ODPOWIADA ZA ZMIANE AKTUALNEGO GRACZA PO PRZEZ ZAMIAN� PODAWANEJ ZMIENNEJ */
void aktualnyGracz(char *gracz){
    if(*gracz=='x'){
        *gracz = 'o';
    } else if(*gracz=='o'){
        *gracz = 'x';
    }
}

int sprawdzWolnePola(char plansza[3][3]){
    int i,j;
    int zlicz=0;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(plansza[i][j]==' '){
                zlicz++;
            }
        }
    }
    if(zlicz>=1){
        return 1;
    } else {
        return 0;
    }
}

void rysujPlansze(char plansza[3][3]){
    printf("   1 2 3\n");
    printf("  -------\n");
    printf("1 |%c|%c|%c|\n",plansza[0][0],plansza[0][1],plansza[0][2]);
    printf("  -------\n");
    printf("2 |%c|%c|%c|\n",plansza[1][0],plansza[1][1],plansza[1][2]);
    printf("  -------\n");
    printf("3 |%c|%c|%c|\n",plansza[2][0],plansza[2][1],plansza[2][2]);
    printf("  -------\n");
}

/* TODO: rozpoznanie kt�ry znak wygra� oraz rozpatrzenie potencjalnego remisu */
void wygrana(plansza[3][3]){


}
