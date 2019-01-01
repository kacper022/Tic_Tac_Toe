#include <stdio.h>
#include <stdlib.h>

#include "tictactoe.h"
#include "warunkiWygranej.h"
#include "AI.h"

char plansza[3][3];

int main(void)
{
    int x,y;
    char gracz;
    char winner;
    char rozpoczecie;
    int tryb;
    int ktory_ruch=0;

    zapelnij(plansza);
    printf("Wybierz znak ktorym chcesz zaczac (x lub o): ");
    scanf("%c", &gracz);
    fflush(stdin);

    printf("Czy chcesz zaczac gre jako pierwszy? (t lub n): ");
    scanf("%c", &rozpoczecie);
    fflush(stdin);

    printf("Wybierz tryb gry\n1. 1-VS-1 \n2. 1-VS-AI\n");
    scanf("%d", &tryb);
    fflush(stdin);

    /*   WARUNKI SPRAWDZAJACE POPRAWNOSC WPISANYCH DANYCH   */
    while(gracz!='x' && gracz!='o'){
        system("CLS");
        gracz=' ';
        printf("Podano zly znak! Wybierz symbol ponownie: ");
        scanf("%c", &gracz);
    }

    while(rozpoczecie!='t' && rozpoczecie!='n'){
        rozpoczecie=' ';
        printf("Wpisano zly znak wyboru rozpoczecia kolejki! Wybierz ponownie: ");
        scanf("%c", &rozpoczecie);
    }

    while(tryb !=1 && tryb !=2 && tryb != 3){
        tryb=0;
        printf("Wpisano zly znak wyboru trybu! Wybierz ponownie: ");
        scanf("%d", &tryb);
    }

    if(rozpoczecie == 'n' && tryb == 2){
        aktualnyGracz(&gracz);
        pierwszyRuch(plansza, gracz);
        aktualnyGracz(&gracz);
    }

    system("CLS");
    blokPoziom(plansza, gracz);
    /*  FUNKCJA URUCHAMIAJACA GRE   */
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
        if(tryb != 3){
            while(zajetoscPola(plansza,x-1,y-1)==1){
                system("CLS");
                rysujPlansze(plansza);
                printf("Podane pole jest zajete, wprowadz dane ponownie!\n\n");
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
            }
        }

        aktualizujPlansze(x-1, y-1, plansza, gracz);
        system("CLS");
        rysujPlansze(plansza);
        system("CLS");

        wynik(plansza, gracz, &winner);
        if(winner=='x' || winner=='o'){
            printf("Wygrywa %c",gracz);
            break;
        }

        if(sprawdzWolnePola(plansza)!=1){
            printf("Brak pustych miejsc, zaden znak nie wygrywa.");
            break;
        }

        if(tryb==2 || tryb==3){
            aktualnyGracz(&gracz);

            if(ktory_ruch==0){
                wykonajRuch(plansza, gracz);
                ktory_ruch++;
            }else {
                if(szukajPar(plansza,gracz)==0){
                    if(blokPoziom(plansza,gracz)==0 && blokPion(plansza,gracz)==0 && blokSkosy(plansza,gracz)==0){
                        wykonajRuch(plansza,gracz);
                    }
                }
            }
            wynik(plansza, gracz, &winner);
            if(winner=='x' || winner=='o'){
                printf("Wygrywa %c",gracz);
                break;
            }
            if(sprawdzWolnePola(plansza)!=1){
                printf("Brak pustych miejsc, zaden znak nie wygrywa.");
                break;
            }
        }

        aktualnyGracz(&gracz);

    }while(1);
    rysujPlansze(plansza);

    return 0;
}
