#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "AI.h"

void pierwszyRuch(char plansza[3][3], char znak){
    int x,y;
    time_t tt;
    int odniesienie = time(&tt);
    srand(odniesienie);

    x=rand()%3;
    y=rand()%3;
    plansza[x][y];
}
