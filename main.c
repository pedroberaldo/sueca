#include "core/sueca.h"

int main(void){
    int i;
    cartas baralho[NUMERO_DE_CARTAS];
    
    iniciar_baralho(baralho);
    
    for(i = 0 ; i < NUMERO_DE_CARTAS ; i++){
        printf("\n%s%d%s\n", get_naipe(baralho[i]), baralho[i].numero, get_naipe(baralho[i]));
    }
    
    embaralhar_cartas(baralho);
    printf("\n\nApós embaralhar:\n\n");
    
    for(i = 0 ; i < NUMERO_DE_CARTAS ; i++){
        printf("\n%s%d%s\n", get_naipe(baralho[i]), baralho[i].numero, get_naipe(baralho[i]));
    }
    
    exit(EXIT_SUCCESS);
}
