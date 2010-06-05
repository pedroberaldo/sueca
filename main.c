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

    for(i = 0 ; i < numero_jogadores ; i++){
        preencher_dados_jogador(&jogador[i], (i + 1));
    }

    print_opcoes(&opcao);
    
    for(i = 0 ;  ; i++){
        if(i % NUMERO_DE_CARTAS == 0 && i != 0){
            printf("\nFim das cartas...reembaralhando....\n");
            embaralhar_cartas(baralho);
        }
        switch(opcao){
            case 1:
                jogar_sueca(&jogador[i % numero_jogadores], baralho + (i % NUMERO_DE_CARTAS));
                break;
            case 2:
                inserir_jogador(jogador, &numero_jogadores);
                break;
            case 3:
            default:
                exit(EXIT_SUCCESS);
                break;
        }
        print_opcoes(&opcao);
    }

    exit(EXIT_SUCCESS);
}
