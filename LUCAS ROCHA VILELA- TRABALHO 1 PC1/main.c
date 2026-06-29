#include <stdio.h>
#include <string.h>
#include "entrada.h"
#include "processamento.h"
#include "impressao.h"

int main(void){
    int qtd, tampal;
    int *a, *b;
    a=&tampal;
    b=&qtd;
    leincio(a, b);
    char palavras[qtd][81], cacapal[tampal][81];
    leprograma(qtd, tampal, palavras, cacapal);
    int lugares[qtd][2][81];
    organiza( tampal , qtd, cacapal, palavras, lugares);
    imprime( qtd, tampal, palavras, lugares);

    return 0;
}