#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "AI.h"
#include "tictactoe.h"

void pierwszyRuch(char plansza[3][3], char znak){
    int x,y;
    time_t tt;
    int odniesienie = time(&tt);
    srand(odniesienie);

    x=rand()%3;
    y=rand()%3;
    plansza[x][y] = znak;
}

void wykonajRuch(char plansza[3][3], char znak){
    int x,y;
    x=rand()%3;
    y=rand()%3;

    while(zajetoscPola(plansza, x, y) == 1){
        x = rand()%3;
        y = rand()%3;
    }

    aktualizujPlansze(x,y,plansza,znak);
}
