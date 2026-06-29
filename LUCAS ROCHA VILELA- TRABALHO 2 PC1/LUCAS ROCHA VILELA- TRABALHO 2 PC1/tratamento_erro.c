#include <stdio.h>
#include <stdlib.h>
#include "tratamento_erro.h"

void testa_parametros(int argc) {
    //verifica se tem os 3 arquivos a serem analisados: o programa, arquivo de entrada, arquivo de saída
    if (argc != 3) {
        printf("Uso: ./executavel <arquivo_entrada.txt> <arquivo_saida.txt>");
        exit(0);
    }
}

void testa_abertura(FILE *conteudo, const char *arquivo, const char *modo){
    //verifica se o arquivo existe na memória do usuário
    if (conteudo == NULL) {
        printf("Falha em abrir o arquivo %s com o modo %s\n", arquivo, modo);
        exit(0);
    }
}