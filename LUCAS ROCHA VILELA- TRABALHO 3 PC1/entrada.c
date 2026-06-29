#include "entrada.h"

//função que le o arquivo com o jogo da velha
void leitura(FILE *arquivo_entrada, char jogo_da_velha[][4]){
    for(int i=0; i<3; i++){
        fscanf(arquivo_entrada, "%s", jogo_da_velha[i]);
    }
}