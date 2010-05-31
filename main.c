#include "core/sueca.h"

int main(void){
    int i, numero_jogadores, opcao;
    jogadores *jogador;
    cartas baralho[NUMERO_DE_CARTAS];
    
    iniciar_baralho(baralho);
    embaralhar_cartas(baralho);

    printf("\nBem vindo ao jogo de 'sueca'. Entre com o número de jogadores:\n");
    scanf("%d", &numero_jogadores);

    jogador = malloc(numero_jogadores * sizeof(jogadores));

    preencher_dados_jogador(jogador, numero_jogadores);

    printf("\nEntre com uma das opções à seguir:");
    printf("\n1- Jogar:");
    printf("\n2- Sair:\n");
    scanf("%d", &opcao);
    
    for(i = 0 ;  ; i++){
        if(i % NUMERO_DE_CARTAS == 0 && i != 0){
            printf("\nFim das cartas...reembaralhando....\n");
            embaralhar_cartas(baralho);
        }
        switch(opcao){
            case 1:
                jogar_sueca(&jogador[i % numero_jogadores], baralho + (i % NUMERO_DE_CARTAS));
                break;
            default:
                exit(EXIT_SUCCESS);
                break;
        }
        printf("\nEntre com uma das opções à seguir:");
        printf("\n1- Jogar:");
        printf("\n2- Sair:");
        scanf("%d", &opcao);
    }


    /* ROTINA DE TESTES
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
    */
    exit(EXIT_SUCCESS);
}
