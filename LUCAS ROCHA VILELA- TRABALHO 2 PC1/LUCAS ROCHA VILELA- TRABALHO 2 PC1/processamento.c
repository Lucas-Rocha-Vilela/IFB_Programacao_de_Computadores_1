#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "processamento.h"

//compara as strings dos times para saber aonde salvar os dados
int compara_nomes(int n, times vetor_times[], times vetor_aux_times[], int h){
    int tam, j;
        //laço dos times que serão salvos
        for(int i=0; i<n; i++){
            tam = strlen(vetor_times[i].nome);
            
            //laço que compara os nomes dos times
            for(j=0; j< tam; j++){
                if(vetor_times[i].nome[j] != vetor_aux_times[h].nome[j] || tam != strlen(vetor_aux_times[h].nome))
                    break;
            }

            /*caso eu encontre o equivalente do time recém lido nos times a terem 
            os dados salvos eu retorno o endereço desse time no vetor para modificar seus dados*/
            if ( j == tam){
                return i;
            }
    }

    return 0;
}

//zera todos os elementos de inteiros os quais não são constantes
void zera(int n, times vetor_times[]){
    for(int i=0; i<n ; i++){
        vetor_times[i].pontos = 0;
        vetor_times[i].gol_contra = 0;
        vetor_times[i].gol_favor = 0;
        vetor_times[i].vitorias = 0;
    }
}

//função que retorna quantos pontos o time fez da rodada
int condicao(int a, int b){
    if (a > b)
        return 3;

    else if (a == b)
        return 1;

    else
        return 0;
}

//função que analisa se um time venceu ou não
int vitoria(int a){
    if(a == 3)
        return 1;

    else
        return 0;
}

//analisa cada rodada e faz a analise de todos os dados dos jogos
void solve(int n, times vetor_aux_times[], times vetor_times[]){
    int posicao;

    //para cada rodada será analisado cada time e seus dados serão salvos
    for(int h=0; h < n; h++){

        //recebe a posição do time na partida, ou seja, aonde ele se situa no vetor principal de times
        posicao = compara_nomes(n, vetor_times, vetor_aux_times, h);

        //salva os gols a favor que o time fez
        vetor_times[posicao].gol_favor += vetor_aux_times[h].gol_favor;

        /*analisa se o time tá na esquerda ou na direita na partida do programa para
         então definir os gols contra, quantos pontos cada um ganhou e se o time venceu ou não*/
           if(h % 2 == 0){
                vetor_times[posicao].gol_contra +=  vetor_aux_times[h+1].gol_favor;
                vetor_times[posicao].pontos += condicao(vetor_aux_times[h].gol_favor, vetor_aux_times[h+1].gol_favor);
                vetor_times[posicao].vitorias += vitoria(condicao(vetor_aux_times[h].gol_favor, vetor_aux_times[h+1].gol_favor));
        }
            else{
                vetor_times[posicao].gol_contra +=  vetor_aux_times[h-1].gol_favor;
                vetor_times[posicao].pontos += condicao(vetor_aux_times[h].gol_favor, vetor_aux_times[h-1].gol_favor);
                vetor_times[posicao].vitorias += vitoria(condicao(vetor_aux_times[h].gol_favor, vetor_aux_times[h-1].gol_favor));
        }
    }
}

//salva o saldo de gols, poderia aplicar a operação direto na impressão, mas assim fica mais organizado
void saldo(int n, times vetor_times[]){
    for(int i=0; i < n; i++){
        vetor_times[i].saldos = vetor_times[i].gol_favor - vetor_times[i].gol_contra;
    }
}

