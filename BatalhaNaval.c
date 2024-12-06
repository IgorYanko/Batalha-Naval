#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO_CAMPO 5
#define MAX_BARCO 8  // Número de barcos no total (4 para os dois jogadores)
#define PORTAAVIOES 4 // Nome e valor do barco 1
#define DESTROYER 3 // Nome e valor do barco 2
#define FRAGATA 2 // Nome e valor do barco 3
#define SUBMARINO 1  // Nome e valor do barco 4


//Função que posiciona os barcos de acordo com a posição X e Y do campo
void posicionarBarcos(int tipo_barco, int campo[TAMANHO_CAMPO][TAMANHO_CAMPO]){
    int x, y; //Variáveis que determinam a pocição do barco em relação ao campo
    // Verifica e solicita até que a posição seja válida
    while (1) { // Loop infinito para garantir repetição até inserir uma posição válida
        printf("Selecione a posicao X: ");
        scanf("%d", &x);
        printf("Selecione a posicao Y: ");
        scanf("%d", &y);

        // Verifica se a posição está dentro dos limites do campo
        if (x >= 0 && x < TAMANHO_CAMPO && y >= 0 && y < TAMANHO_CAMPO) {
            campo[x][y] = tipo_barco; // Insere o barco no campo
            printf("Barco %d posicionado em (%d , %d).\n", tipo_barco, x, y);
            printf("=================================================================\n");
            break; // Sai do loop quando a posição for válida
        } else {
            printf("Posicao invalida! Tente novamente.\n");
        }
    }

}

//Igor
int RealizarJogada(int campo[TAMANHO_CAMPO][TAMANHO_CAMPO], bool VezJogadorUm) { //Campo e de quem é a vez de jogar como parâmetros
    int x, y, Pontuacao = 0;
    
    //Bloco pra escolher a coordenada de ataque
    printf("X:");
    scanf("%d", &x);
    printf(" Y:");
    scanf("%d", &y);
    
    if(x >= 0 && x < TAMANHO_CAMPO && y >= 0 && y < TAMANHO_CAMPO) { //Garantir que seja uma jogada válida
        if(campo[x][y] != 0) { //Se a coordenada escolhida não estiver vazia, verifica quanto vale o barco acertado
            int pontuacaoBarco = campo[x][y];
            campo[x][y] = 0; //Zera a posicao, "retirando" o barco da coordenada
            
            switch (pontuacaoBarco){ //Estrutura pra verificar a Pontuacao da jogada
                case SUBMARINO:
                    Pontuacao += SUBMARINO;
                    printf("Você acertou um Submarino! +%d ponto.\n", SUBMARINO);
                    break;
                case FRAGATA:
                    Pontuacao += FRAGATA;
                    printf("Você acertou uma Fragata! +%d pontos.\n", FRAGATA);
                    break;
                case DESTROYER:
                    Pontuacao += DESTROYER;
                    printf("Você acertou um Destroyer! +%d pontos.\n", DESTROYER);
                    break;
                case PORTAAVIOES:
                    Pontuacao += PORTAAVIOES;
                    printf("Você acertou um Porta-Aviões! +%d pontos.\n", PORTAAVIOES);
                    break;
            }
        } else {
            printf("\nChuaaa, Nada!");
        }    
    } else {
        printf("Posição inválida! As coordenadas devem estar entre 0 e %d.\n", TAMANHO_CAMPO);
    }
}

int main() {
    char jogador1[30], jogador2[30];  // Vetores para armazenar os nomes dos jogadores
    int campo_a[TAMANHO_CAMPO][TAMANHO_CAMPO];
    int campo_b[TAMANHO_CAMPO][TAMANHO_CAMPO];
    bool VezJogadorUm = true; // Variavel booleana pra definir quem joga na rodada - Igor
    int Pontuacao1 = 0, Pontuacao2 = 0;


    // Leitura dos nomes dos jogadores
    printf("Digite o nome do Jogador 1: ");
    scanf("%s", jogador1);  // Lê o nome do jogador 1

    printf("Digite o nome do Jogador 2: ");
    scanf("%s", jogador2);  // Lê o nome do jogador 2

    // Exibe os nomes informados
    printf("Jogador 1: %s\n", jogador1);
    printf("Jogador 2: %s\n", jogador2);

 
    printf("=================================================================\n");

    printf("%s posicione o Submarino com valor de 1 ponto:\n", jogador1);
    posicionarBarcos(SUBMARINO, campo_a);

    printf("%s posicione a Fragata com valor de 2 pontos:\n", jogador1);
    posicionarBarcos(FRAGATA, campo_a);

    printf("%s posicione o Destroyer com valor de 3 pontos:\n", jogador1);
    posicionarBarcos(DESTROYER, campo_a);

    printf("%s posicione o Porta Avioes com valor de 4 pontos:\n", jogador1);
    posicionarBarcos(PORTAAVIOES, campo_a);

    printf("Vez do Jogador %s:\n", jogador2);

    printf("%s posicione o Submarino com valor de 1 ponto:\n", jogador2);
    posicionarBarcos(SUBMARINO, campo_b);

    printf("%s posicione a Fragata com valor de 2 pontos:\n", jogador2);
    posicionarBarcos(FRAGATA, campo_b);

    printf("%s posicione o Destroyer com valor de 3 pontos:\n", jogador2);
    posicionarBarcos(DESTROYER, campo_b);

    printf("%s posicione o Porta Avioes com valor de 4 pontos:\n", jogador2);
    posicionarBarcos(PORTAAVIOES, campo_b);
    
    printf("Hora de atacar! 5 tentativas para cada jogador.\n");
    
    for(int i = 0; i < 5; i++){ //Loop pra permitir a jogada de cada jogador 5 vezes - Igor
        printf("\n%s sua vez de jogar!", jogador1);
        Pontuacao1 += RealizarJogada(campo_a, VezJogadorUm);
        printf("\n%s sua vez de jogar!", jogador2);
        Pontuacao2  += RealizarJogada(campo_a, !VezJogadorUm);
    }
    
    if(Pontuacao1 > Pontuacao2) {
       printf("\n%s ganhou!!!", jogador1); 
    } else {
       printf("\n%s ganhou!!!", jogador2); 
    }
}
