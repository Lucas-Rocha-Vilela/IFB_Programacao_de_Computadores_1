#include <stdio.h>
#include<string.h>
#include "processamento.h"

void organiza(int tampal , int qtd, char cacapal[][81], char palavras[][81], int lugares[][2][81]){
    int aumlinha, aumcoluna;
    for(int i=0; i<qtd;i++){//analisa as palavras uma a uma
        int tamstr = strlen(palavras[i]);
        int teste=0;
        for(int j=0; j<=7 ; j++ ){//analisa os casos em que as palavras se encontram
            switch (j)
            {
            case 0:
            //analisa coluna normal
                aumlinha = 1;
                aumcoluna = 0;
                break;
            
            case 1:
            //analisa coluna invertido
                aumlinha = -1;
                aumcoluna = 0;
                break;

            case 2:
            //analisa horizontal normal
                aumlinha = 0;
                aumcoluna = 1;
                break;

            case 3:
            //analisa horizontal invertido
                aumlinha = 0;
                aumcoluna = -1;
                break;

            case 4:
            //analisa diagonal principal normal
                aumlinha = 1;
                aumcoluna = 1;
                break;

            case 5:
            //analisa diagonal principal invertida
                aumlinha = -1;
                aumcoluna = -1;
                break;

            case 6:
            //analisa diagonal secundaria normal
                aumlinha = -1;
                aumcoluna = 1;
                break;

            case 7:
            //analisa diagonal secundaria invertida
                aumlinha = 1;
                aumcoluna = -1;
                break;
            }
                for(int linha=0; linha<tampal; linha++){
                    for(int coluna=0; coluna<tampal; coluna++){
                        //analisa todos os termos do caça-palavras usando os casos do switch case
                        int auxlinha = linha, auxcoluna = coluna;//utiliza-se auxiliares para manipular os valores das linhas e colunas sem modifica-los diretamente
                        int soma=0;
                        if(palavras[i][0] == cacapal[linha][coluna]){
                            for(int aux=0; aux<tamstr; aux++){
                                lugares[i][0][aux] = auxlinha; //salva as posições das linhas
                                lugares[i][1][aux] = auxcoluna; // salva as posições das colunas
                                auxlinha += aumlinha;
                                auxcoluna += aumcoluna;
                            }
                            for(int aux=0; aux<tamstr; aux++){
                                if(palavras[i][aux] == cacapal[lugares[i][0][aux]][lugares[i][1][aux]]){//verifica se a palavra realmente foi encontrada
                                    soma++;//salva a quantidade de vezes que as letras foram equivalentes para testar depois
                                }
                            }
                            if(soma == tamstr){
                                //salva num operador pra poder testar mais facilmente e dar break nos próximo for caso tenha se encontrado as palavras
                                teste=1;
                                //salva um termo pra saber se imprime corretamente ou invertido
                                break;}
                        }
                    }
                if(teste)break;
                }
            if(teste)break;
        }
    }

}