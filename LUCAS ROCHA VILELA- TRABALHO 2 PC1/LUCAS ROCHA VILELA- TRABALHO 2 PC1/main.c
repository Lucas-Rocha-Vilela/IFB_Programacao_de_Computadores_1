#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "tratamento_erro.h"
#include "leitura.h"
#include "processamento.h"
#include "organiza.h"
#include "saida.h"


int main(int argc,char *argv[]){

    //testa se o arquivo tá adequado
    testa_parametros(argc);
    FILE *conteudo_entrada = fopen(argv[1], "r"), *conteudo_saida = fopen(argv[2], "w");
    testa_abertura(conteudo_entrada, argv[1], "r");

    //escaneia a qtd de times que vai ter
    int n;
    fscanf(conteudo_entrada, "%d", &n);

    //le todos os times antes de analisar os jogos
    times vetor_times[n], vetor_aux_times[n];
    le_times(conteudo_entrada, n, vetor_times);

    zera(n, vetor_times);

    //laço que analisa rodada por rodada
    for(int k=0; k < 2*(n-1); k++){
        le_rodadas(conteudo_entrada, n, vetor_aux_times);
        solve(n, vetor_aux_times, vetor_times);
    }

    //salva o saldo de gols
    saldo(n, vetor_times);

    //organiza os times
    organiza(n, vetor_times);

    //imprime os resultados
    imprime(conteudo_saida, n, vetor_times);

    //fecha os arquivos
    fclose(conteudo_entrada);
    fclose(conteudo_saida);

    return 0;

}