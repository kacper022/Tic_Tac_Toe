#include <stdio.h>
#include <stdlib.h>

#include "tictactoe.h"

char plansza[3][3];

int main(void)
{
    int x,y;
    char gracz;

    zapelnij(plansza);
    printf("Wybierz znak ktorym chcesz zaczac (x lub o): ");
    scanf("%c", &gracz);

    do{
        rysujPlansze(plansza);
        printf("Podaj kolumne: ");
        scanf("%d",&x);
        printf("Podaj linie: ");
        scanf("%d",&y);
        aktualizujPlansze(x-1, y-1, plansza, gracz);
        system("CLS");
        rysujPlansze(plansza);
        aktualnyGracz(&gracz);
        system("CLS");
        if(sprawdzWolnePola(plansza)!=1){
            break;
        }
    }while(1);
    rysujPlansze(plansza);
    return 0;
}
