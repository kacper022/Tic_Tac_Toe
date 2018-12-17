#include <stdio.h>
#include <stdlib.h>

#include "warunkiWygranej.h"

/*

[
[00][01][02]
[10][11][12]
[20][21][22]
]
*/

void wynik(char plansza[3][3], char gracz, char *result){
    int i,j;
    int wynik=0;

    while(wynik==0){
        for(i=0;i<3;i++){
            if(plansza[i][0]==gracz && plansza[i][1]==gracz && plansza[i][2]==gracz){
                *result=gracz;
                wynik=1;
                break;
            }
        }
        if(wynik==0){
            for(i=0;i<3;i++){
                if(plansza[0][i]==gracz && plansza[1][i]==gracz && plansza[2][i]==gracz){
                    *result=gracz;
                    wynik=1;
                    break;
                }
            }
        }
        if(wynik==0 && plansza[0][0]==gracz && plansza[1][1]==gracz && plansza[2][2]==gracz){
            wynik=1;
            *result=gracz;
            break;
        } else if(wynik==0 && plansza[0][2]==gracz && plansza[1][1]==gracz && plansza[2][0]==gracz){
            wynik=1;
            *result=gracz;
            break;
        } else{
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){

                }
            }
        }
    }
}
