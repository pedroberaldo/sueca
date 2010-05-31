#include "sueca.h"

void iniciar_baralho(cartas *baralho){
    int i;

    for(i = 0 ; i < NUMERO_DE_CARTAS ; i++){
        
        baralho[i].numero = (i % 13) + 1;
        
        if(i < 13)
            baralho[i].naipe = ouros;
        else if(i >= 13 && i < 26)
            baralho[i].naipe = espadas;
        else if(i >= 26 && i < 39)
            baralho[i].naipe = copas;
        else
            baralho[i].naipe = paus;
    }
}

void embaralhar_cartas(cartas *baralho){
    int i, rand1, rand2;
    cartas carta_tmp;
    srand (time(NULL));

    for(i = 0 ; i < 10000 ; i++){
        rand1 = rand() % 52;
        rand2 = rand() % 52;
        carta_tmp = baralho[rand1];
        baralho[rand1] = baralho[rand2];
        baralho[rand2] = carta_tmp;
    }
}

char * get_naipe(cartas carta){
    switch(carta.naipe){
    case ouros:
        return "♦♦";
    break;
    case espadas:
        return "♠♠";
    break;
    case copas:
        return "♥♥";
    break;
    case paus:
        return "♣♣";
    break;
    default:
        return "  ";
    break;
    }
}
