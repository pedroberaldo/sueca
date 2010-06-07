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

/* Esta função recebe um array do tipo 'cartas', que é um 'baralho'
 * e atribui o valor de cada carta, de 'As' à 'K', nos 4 naipes
 */
void iniciar_baralho(cartas *);

/* Esta função recebe um array do tipo 'cartas' que é um 'baralho'
 * e embaralha as mesmas
 */
void embaralhar_cartas(cartas *);

/* Esta função recebe uma variável do tipo 'cartas' e retorna o seu nipe
 * como uma string para que a mesma possa ser imprimida
 */
char * get_naipe(cartas );

/* Esta função recebe um ponteiro para uma variável do tipo 'jogadores'
 * e o # do jogador e então preenche os seus dados
 */
void preencher_dados_jogador(jogadores *, int );

/* Esta função imprime as opções do jogo */
void print_opcoes(int *);

/* Está função recebe um ponteiro para uma variável do tipo 'jogadores'
 * e um array de do tipo 'cartas', que é um 'baralho' e então executa
 * a lógica principal do jogo e imprime a 'tarefa' do jogador de acordo
 * com a carta retirada
 */
void jogar_sueca(jogadores *, cartas *);

/* Esta função recebe um array do tipo 'jogadores' e o número de jogadores atuais
 * e então execuuta a função 'preencher_dados_jogador()' para inserir um
 * jogador a mais durante o jogo
 */
void inserir_jogador(jogadores *, int *);