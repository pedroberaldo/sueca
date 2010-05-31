#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_DE_CARTAS 52

enum naipe_carta { ouros, espadas, copas, paus } ;
typedef enum naipe_carta naipe_carta;

struct cartas{
    int numero;
    naipe_carta naipe;
    };
typedef struct cartas cartas;

void iniciar_baralho(cartas *baralho);
void embaralhar_cartas(cartas *baralho);
char * get_naipe(cartas carta);
