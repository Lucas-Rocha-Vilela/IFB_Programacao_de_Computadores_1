#include <stdio.h>
#include <stdlib.h>
#include "tratamento_erro.h"
#include "entrada.h"
#include "processamento.h"

int main(int argc, char *argv[]){

    //testa os arquivos
    testa_parametros(argc);
    FILE *arquivo_entrada = fopen(argv[1], "r"), *arquivo_saida = fopen(argv[2], "w");
    testa_abertura(arquivo_entrada, argv[1], "r");

    //recebe o jogo da velha inicial
    char jogo_da_velha[3][4];
    leitura(arquivo_entrada, jogo_da_velha);

    /* processa todos os jogos e imprime os jogos em que "O" ganha
    parametro = 1, pois em todos os casos o "O" é o primeiro a fazer alguma ação */
    testa_inicio(arquivo_saida, jogo_da_velha);

    //fecha os arquivos
    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    return 0;
}