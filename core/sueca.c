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

void preencher_dados_jogador(jogadores *jogador, int n){
    int sexo_jogador;
    int i;
    
    for(i = 0 ; i < n ; i++){
        printf("\nEntre com o nome do jogador %d:\n", (i + 1));
        scanf("%s", jogador[i].nome);
        //gets(jogador[i].nome);
        printf("\nEntre com o sexo do jogador %d: (1 = Masculino, 2 = Feminino)\n", (i + 1));
        scanf("%d", &sexo_jogador);
        if(sexo_jogador == 1)
            jogador[i].jogador_sexo = masculino;
        else if(sexo_jogador == 2)
            jogador[i].jogador_sexo = feminino;
    }
}

void jogar_sueca(jogadores *jogador, cartas *baralho){
    jogador->ultima_carta = *baralho;
    if(jogador->jogador_sexo == masculino){
        printf("\n\nO jogador %s tirou a carta: %s%d%s", jogador->nome, get_naipe(jogador->ultima_carta), jogador->ultima_carta.numero, get_naipe(jogador->ultima_carta));
        printf("\nEle deve...\n\n");
    }else{
        printf("\n\nA jogadora %s tirou a carta: %s%d%s", jogador->nome, get_naipe(jogador->ultima_carta), jogador->ultima_carta.numero, get_naipe(jogador->ultima_carta));
        printf("\nEla deve...\n\n");
    }
    switch(jogador->ultima_carta.numero){
        case 1:
            break;
        case 2:
            break;
        default:
            break;
    }
}


