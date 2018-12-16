#include <stdio.h>
#include <stdlib.h>

#include "tictactoe.h"
#include "warunkiWygranej.h"

char plansza[3][3];

int main(void)
{
    int x,y;
    char gracz;
    char w;

    zapelnij(plansza);
    printf("Wybierz znak ktorym chcesz zaczac (x lub o): ");
    scanf("%c", &gracz);
    while(gracz!='x' && gracz!='o'){
        system("CLS");
        gracz=' ';
        printf("Podano zly znak! Wybierz symbol ponownie: ");
        scanf("%c", &gracz);
    }

    system("CLS");

    do{
        rysujPlansze(plansza);
        printf("Aktualny znak: %c\n",gracz);
        printf("Podaj kolumne: ");
        scanf("%d",&x);
        while(x>=4 || x<=0){
            printf("Podano zla wartosc! Wprowadz numer kolumny ponownie: ");
            scanf("%d", &x);
        }
        printf("Podaj linie: ");
        scanf("%d",&y);
        while(y>=4 || y<=0){
            printf("Podano zla wartosc! Wprowadz numer linii ponownie: ");
            scanf("%d", &y);
        }

        while(zajetoscPola(plansza,x-1,y-1==1)){
            break;
        }

        aktualizujPlansze(x-1, y-1, plansza, gracz);
        system("CLS");
        rysujPlansze(plansza);
        system("CLS");

        wynik(plansza,gracz,&w);
        if(w=='x'){
            printf("Wygrywa %c",gracz);
            break;
        }

        if(sprawdzWolnePola(plansza)!=1){
            break;
        }
        aktualnyGracz(&gracz);

    }while(1);
    rysujPlansze(plansza);

    return 0;
}
