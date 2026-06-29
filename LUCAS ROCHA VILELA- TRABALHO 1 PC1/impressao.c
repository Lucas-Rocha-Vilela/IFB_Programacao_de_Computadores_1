#include <stdio.h>
#include <string.h>
#include "impressao.h"

void imprime(int qtd, int tampal, char palavras[][81],int posicoes[][2][81]){
    for(int i=0; i<qtd; i++){
        int tamstr = strlen(palavras[i]);
        printf("%s", palavras[i]);

        //casos de impressao para caso a palavra esteja invertida
        if(posicoes[i][0][0] == posicoes[i][0][1]){//caso em que a palavra tá na horizontal
        if(posicoes[i][1][0] < posicoes[i][1][1]){//caso em que a palavra tá no formato normal
        for(int j=0; j< tamstr; j++){
            printf(" (%d,%d)", posicoes[i][0][j], posicoes[i][1][j]);
                }
            }
        else{
            for(int j=tamstr-1; j>=0; j--){//caso em que a palavra tá invertida
            printf(" (%d,%d)", posicoes[i][0][j], posicoes[i][1][j]);
        }
        }
        }
        else if(posicoes[i][0][0] < posicoes[i][0][1]){//caso em que a palavra tá na diagonal ou horizontal e tá no formato normal
        for(int j=0; j< tamstr; j++){
            printf(" (%d,%d)", posicoes[i][0][j], posicoes[i][1][j]);
        }
        }
        else{
            for(int j=tamstr-1; j>=0; j--){//caso em que a palavra tá na diagonal ou horizontal e tá no formato invertido
            printf(" (%d,%d)", posicoes[i][0][j], posicoes[i][1][j]);
        }
        }

        printf("\n");
    }
}