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

char przeciwnik(char znak){
    if(znak=='x'){
        return 'o';
    }else if (znak=='o'){
        return 'x';
    }
}
                        /*  FUNKCJE ODPOWIADAJĄCE ZA BLOKOWANIE WYGRANYCH RUCHÓW GRACZA */

int blokPoziom(char plansza[3][3], char znak_AI){
    /*  DOAWARTEGO PONI¯EJ BLOKOWANIA DODAÆ PÊTLE SPRAWDZAJ¥C¥ MO¯LIWE KOMBINACJE ZAMIAST TYLU WARUNKÓW IF!!!   */
    /*  BLOKOWANIE W PIERWSZEJ LINII    */
    if(plansza[0][0]==przeciwnik(znak_AI)&&plansza[0][1]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza, 0, 2)!=1){
            aktualizujPlansze(0, 2, plansza,znak_AI);
            return 1;
        }
    } else if (plansza[0][0]==przeciwnik(znak_AI)&&plansza[0][2]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza,0,1)!=1){
            aktualizujPlansze(0,1,plansza,znak_AI);
            return 1;
        }
    } else if(plansza[0][1]==przeciwnik(znak_AI)&&plansza[0][2]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza,0,0)!=1){
            aktualizujPlansze(0,0,plansza,znak_AI);
            return 1;
        }
    }else if(plansza[1][0]==przeciwnik(znak_AI)&&plansza[1][1]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza, 1, 2)!=1){
            aktualizujPlansze(1, 2, plansza,znak_AI);
            return 1;
        }
    } else if (plansza[1][0]==przeciwnik(znak_AI)&&plansza[1][2]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza,1,1)!=1){
            aktualizujPlansze(1,1,plansza,znak_AI);
            return 1;
        }
    } else if(plansza[1][1]==przeciwnik(znak_AI)&&plansza[1][2]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza,1,0)!=1){
            aktualizujPlansze(1,0,plansza,znak_AI);
            return 1;
        }
    }else if(plansza[2][0]==przeciwnik(znak_AI)&&plansza[2][1]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza, 2, 2)!=1){
            aktualizujPlansze(2, 2, plansza,znak_AI);
            return 1;
        }
    } else if (plansza[2][0]==przeciwnik(znak_AI)&&plansza[2][2]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza,2,1)!=1){
            aktualizujPlansze(2,1,plansza,znak_AI);
            return 1;
        }
    } else if(plansza[2][1]==przeciwnik(znak_AI)&&plansza[2][2]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza,2,0)!=1){
            aktualizujPlansze(2,0,plansza,znak_AI);
            return 1;
        }
    }
    return 0;
}

int blokPion(char plansza[3][3], char znak_AI){
    if(plansza[0][0]==przeciwnik(znak_AI)&&plansza[2][0]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza,1,0)!=1){
            aktualizujPlansze(1,0,plansza,znak_AI);
            return 1;
        }
    } else if(plansza[1][0]==przeciwnik(znak_AI)&&plansza[2][0]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza,0,0)!=1){
            aktualizujPlansze(0,0,plansza,znak_AI);
            return 1;
        }
    }else if(plansza[0][0]==przeciwnik(znak_AI)&&plansza[1][0]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza,2,0)!=1){
            aktualizujPlansze(2,0,plansza,znak_AI);
            return 1;
        }
    }else if(plansza[0][1]==przeciwnik(znak_AI)&&plansza[1][1]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza,2,1)!=1){
            aktualizujPlansze(2,1,plansza,znak_AI);
            return 1;
        }
    } else if(plansza[0][1]==przeciwnik(znak_AI)&&plansza[2][1]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza,1,1)!=1){
            aktualizujPlansze(1,1,plansza,znak_AI);
            return 1;
        }
    }else if(plansza[1][1]==przeciwnik(znak_AI)&&plansza[2][1]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza,0,1)!=1){
            aktualizujPlansze(0,1,plansza,znak_AI);
            return 1;
        }
    }else if(plansza[0][2]==przeciwnik(znak_AI)&&plansza[1][2]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza,2,2)!=1){
            aktualizujPlansze(2,2,plansza,znak_AI);
            return 1;
        }
    } else if(plansza[1][2]==przeciwnik(znak_AI)&&plansza[2][2]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza,0,2)!=1){
            aktualizujPlansze(0,2,plansza,znak_AI);
            return 1;
        }
    }else if(plansza[0][2]==przeciwnik(znak_AI)&&plansza[2][2]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza,1,2)!=1){
            aktualizujPlansze(1,2,plansza,znak_AI);
            return 1;
        }
    }
    return 0;
}

int blokSkosy(char plansza[3][3], char znak_AI){
    if(plansza[0][0]==przeciwnik(znak_AI)&&plansza[1][1]==przeciwnik(znak_AI)){
        if(zajetoscPola(plansza,2,2)!=1){
            aktualizujPlansze(2,2,plansza,znak_AI);
            return 1;
        } else if (plansza[1][1]==przeciwnik(znak_AI)&&plansza[2][2]==przeciwnik(znak_AI)){
            if(zajetoscPola(plansza,0,0)!=1){
                aktualizujPlansze(0,0,plansza,znak_AI);
                return 1;
            }
        } else if(plansza[0][0]==przeciwnik(znak_AI)&&plansza[2][2]==przeciwnik(znak_AI)){
            if(zajetoscPola(plansza,1,1)!=1){
                aktualizujPlansze(1,1,plansza,znak_AI);
                return 1;
            }
        } else if(plansza[0][2]==przeciwnik(znak_AI)&&plansza[1][1]==przeciwnik(znak_AI)){
            if(zajetoscPola(plansza,2,0)!=1){
                aktualizujPlansze(2,0,plansza,znak_AI);
                return 1;
            }
        } else if(plansza[1][1]==przeciwnik(znak_AI)&&plansza[2][0]==przeciwnik(znak_AI)){
            if(zajetoscPola(plansza,0,2)!=1){
                aktualizujPlansze(0,2,plansza,znak_AI);
            }
        } else if(plansza[0][2]==przeciwnik(znak_AI)&&plansza[2][0]==przeciwnik(znak_AI)){
            if(zajetoscPola(plansza,1,1)){
                aktualizujPlansze(1,1,plansza,znak_AI);
            }
        }
    }
    return 0;
}
                        /*  FUNKCJE ODPOWIADAJACE ZA PRÓBĘ WYGRANYCH RUCHÓW AI */

int szukajPar(char plansza[3][3], char znak_AI){
    if(plansza[0][0]==znak_AI&&plansza[0][1]==znak_AI){
        if(zajetoscPola(plansza,0,2)!=1){
            aktualizujPlansze(0,2,plansza,znak_AI);
            return 1;
        }
    } else if(plansza[0][0]==znak_AI&&plansza[0][2]==znak_AI){
        if(zajetoscPola(plansza,0,1)!=1){
            aktualizujPlansze(0,1,plansza,znak_AI);
            return 1;
        }
    } else if(plansza[0][1]==znak_AI&&plansza[0][2]==znak_AI){
        if(zajetoscPola(plansza,0,0)!=1){
            aktualizujPlansze(0,0,plansza,znak_AI);
            return 1;
        }
    } else if(plansza[1][0]==znak_AI&&plansza[1][1]==znak_AI){
        if(zajetoscPola(plansza,1,2)!=1){
            aktualizujPlansze(1,2,plansza,znak_AI);
            return 1;
        }
    } else if(plansza[1][1]==znak_AI&&plansza[1][2]==znak_AI){
        if(zajetoscPola(plansza,1,0)!=1){
            aktualizujPlansze(1,0,plansza,znak_AI);
            return 1;
        }
    } else if(plansza[1][0]==znak_AI&&plansza[1][2]==znak_AI){
        if(zajetoscPola(plansza, 1,1)!=1){
            aktualizujPlansze(1,1,plansza,znak_AI);
            return 1;
        }
    } else if(plansza[2][0]==znak_AI&&plansza[2][1]==znak_AI){
        if(zajetoscPola(plansza,2,2)!=1){
            aktualizujPlansze(2,2,plansza,znak_AI);
            return 1;
        }
    } else if(plansza[2][1]==znak_AI&&plansza[2][2]==znak_AI){
        if(zajetoscPola(plansza,2,0)!=1){
            aktualizujPlansze(2,0,plansza,znak_AI);
            return 1;
        }
    } else if(plansza[2][0]==znak_AI&&plansza[2][2]==znak_AI){
        if(zajetoscPola(plansza,2,1)!=1){
            aktualizujPlansze(2,1,plansza,znak_AI);
            return 1;
        }
    }
    return 0;
}


