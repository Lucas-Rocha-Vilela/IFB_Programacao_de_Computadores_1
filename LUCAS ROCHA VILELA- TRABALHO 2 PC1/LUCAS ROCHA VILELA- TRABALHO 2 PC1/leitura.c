#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "leitura.h"

//função que lê a qtd de times e os nomes do times no inicio do arquivo
void le_times(FILE *conteudo,int n, times vetor_times[]){
    
    //escaneia o nome de cada time
    for(int i=0; i<n; i++){
        fscanf(conteudo, "%s", vetor_times[i].nome);
    }

    //escaneia o primeiro --- para os outros serem escaneados após as rodadas
    fscanf(conteudo, "%*s");
}

/* função que lê cada rodada e vai entrar em um loop na main para 
os dados serem processados antes de serem substituídos na leitura da rodada seguinte*/
void le_rodadas(FILE *conteudo, int n, times vetor_aux_times[]){

    //escaneia a rodada, salvando no vetor auxiliar os dados de cada partida
    for(int i=0, j=0; i<n/2; i++, j+=2){
        fscanf(conteudo, "%s %d %*s %d %s", vetor_aux_times[j].nome, &vetor_aux_times[j].gol_favor, &vetor_aux_times[j+1].gol_favor, vetor_aux_times[j+1].nome);
    }

    //escaneia o --- após a rodada
    fscanf(conteudo, "%*s");
}