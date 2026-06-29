#include <stdio.h>
#include <string.h>
#include "entrada.h"

void leincio(int *tampal, int *qtd){ //tampal==tamanho do caça-palavra; qtd==num de palavras a serem buscadas
    scanf("%d %d", tampal, qtd);
}

void leprograma(int qtd, int tampal, char palavras[][81], char cacapal[][81]){
    for(int i=0; i<qtd; i++){
        //recebe as palavras a serem procuradas
        scanf("%s", palavras[i]);
    }

    for(int i=0; i<tampal; i++){
        //recebe o caça-palavras
        scanf("%s", cacapal[i]);
    }
}