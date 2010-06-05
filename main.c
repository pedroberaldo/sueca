#include "core/sueca.h"

int main(void){
    int i, numero_jogadores, opcao, opcao_final_cartas;
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
        if(i % NUMERO_DE_CARTAS == 0 && i != 0){
            printf("\nO baralho chegou ao fim..Deseja reembaralhar as cartas e continuar jogando? (1 = Sim, 2 = Não)\n");
            scanf("%d", &opcao_final_cartas);
            switch(opcao_final_cartas){
                case 1:
                    embaralhar_cartas(baralho);
                    printf("\nO cartas foram embaralhadas novamente!!\n");
                    break;
                case 2:
                default:
                    exit(EXIT_SUCCESS);
                    break;
            }
        }
        print_opcoes(&opcao);
    }

    exit(EXIT_SUCCESS);
}
