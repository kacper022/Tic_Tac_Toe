#include <stdio.h>
#include <stdlib.h>

#include "warunkiWygranej.h"

void wynik(char plansza[3][3], char gracz, char *result){
    int i,j;
    int wynik=0;
    while(wynik==0){
        for(i=0;i<3;i++){
            if(gracz == 'x' && plansza[i][0]!=' ' && plansza[i][1]!=' ' && plansza[i][2]!=' '){
                *result='x';
                wynik=1;
                break;
            }
        }
        if(wynik!='0'){
            for(i=0;i<3;i++){
                if(gracz == 'x' && plansza[0][i]!=' ' && plansza[1][i]!=' ' && plansza[2][i]!=' '){
                    *result='x';
                    wynik=1;
                    break;
                }
            }
        }
    }
}
