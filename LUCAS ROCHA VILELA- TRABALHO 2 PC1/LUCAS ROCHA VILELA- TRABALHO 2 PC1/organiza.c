#include <stdio.h>
#include <string.h>
#include "tipos.h"
#include "organiza.h"

void troca(times vetor_times[], int j){
    times aux;
    aux = vetor_times[j];
    vetor_times[j] = vetor_times[j+1];
    vetor_times[j+1] = aux;
}


void organiza(int n, times vetor_times[]){
    for(int i=n-1; i > 0; i--){

        for(int j=0; j < i; j++){

            //compara os pontos dos times e os organiza, se forem iguais vai pro próximo critério
            if(vetor_times[j].pontos == vetor_times[j+1].pontos){

                //compara as vitórias dos times e os organiza, se forem iguais vai pro próximo critério
                if (vetor_times[j].vitorias == vetor_times[j+1].vitorias){
                    
                    //compara os saldos dos times e os organiza, se forem iguais vai pro próximo critério
                    if(vetor_times[j].saldos == vetor_times[j+1].saldos){

                        //compara os gols a favor dos times e os organiza, se forem iguais vai pro próximo critério
                        if(vetor_times[j].gol_favor < vetor_times[j+1].gol_favor){
                            troca(vetor_times, j);
                        }
                    }

                    else if(vetor_times[j].saldos < vetor_times[j+1].saldos){
                        troca(vetor_times, j);
                    }
                }

                else if(vetor_times[j].vitorias < vetor_times[j+1].vitorias){
                    troca(vetor_times, j);
                }
            }

            else if(vetor_times[j].pontos < vetor_times[j+1].pontos){
                troca(vetor_times, j);
            }
        }
    }
}