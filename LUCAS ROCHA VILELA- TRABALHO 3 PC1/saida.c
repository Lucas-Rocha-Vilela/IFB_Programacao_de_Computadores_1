#include <stdio.h>
#include <stdlib.h>
#include "saida.h"

//função que imprime o jogo ganho e dá uma quebra de linha para os 
void imprime(FILE *arquivo_saida, char jogo_da_velha[][4]){
    for(int i=0; i<3; i++){
        fprintf(arquivo_saida, "%s\n", jogo_da_velha[i]);
    }
    fprintf(arquivo_saida, "\n");
}