#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "saida.h"

void imprime(FILE *conteudo_saida, int n, times vetor_times[]){
    for(int i=0; i < n; i++){
        fprintf(conteudo_saida, "%d %s %d %d %d %d %d %d\n", i+1, vetor_times[i].nome, vetor_times[i].pontos, 2*(n-1), vetor_times[i].vitorias, vetor_times[i].saldos, vetor_times[i].gol_favor, vetor_times[i].gol_contra);
    }
}