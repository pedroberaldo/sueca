#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_DE_CARTAS 52

enum naipe_carta { ouros, espadas, copas, paus } ;
typedef enum naipe_carta naipe_carta;

enum sexo { feminino, masculino } ;
typedef enum sexo sexo;

struct cartas{
    int numero;
    naipe_carta naipe;
    };
typedef struct cartas cartas;

struct jogadores{
    char nome[100];
	int qnt_doses = 0;
    sexo jogador_sexo;
    cartas ultima_carta;
    };
typedef struct jogadores jogadores;

void iniciar_baralho(cartas *baralho);
void embaralhar_cartas(cartas *baralho);
char * get_naipe(cartas carta);

void preencher_dados_jogador(jogadores *jogador, int n);

void jogar_sueca(jogadores *jogador, cartas *baralho);
