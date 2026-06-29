#ifndef PROCESSAMENTO_H
#define PROCESSAMENTO_H

int compara_nomes(int n, times vetor_times[], times vetor_aux_times[], int h);
void zera(int n, times vetor_aux_times[]);
int condicao(int a, int b);
int vitoria(int a);
void solve(int n, times vetor_aux_times[], times vetor_times[]);
void saldo(int n, times vetor_times[]);

#endif