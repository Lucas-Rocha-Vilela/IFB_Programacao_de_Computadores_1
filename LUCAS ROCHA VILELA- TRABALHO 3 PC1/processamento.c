#include "processamento.h"

//função que analisa as condições de vitória
int vitoria(char jogo_da_velha[][4]){

    //se "O" vence retorna 1, se "X" vence retorna -1, importante para saber quem imprimir depois
    for(int i=0; i<3; i++){

            //analisa as linhas do jogo em que "O" ganha
            if(jogo_da_velha[i][0] == 'O' && jogo_da_velha[i][1] == 'O' && jogo_da_velha[i][2] == 'O')
            return 1;

            //analisa as colunas do jogo em que "O" ganha
            else if(jogo_da_velha[0][i] == 'O' && jogo_da_velha[1][i] == 'O' && jogo_da_velha[2][i] == 'O')
            return 1;
            
            //analisa as linhas do jogo em que "X" ganha
            else if(jogo_da_velha[0][i] == 'X' && jogo_da_velha[1][i] == 'X' && jogo_da_velha[2][i] == 'X')
            return -1;

            //analisa as linhas do jogo em que "X" ganha
            else if(jogo_da_velha[i][0] == 'X' && jogo_da_velha[i][1] == 'X' && jogo_da_velha[i][2] == 'X')
            return -1;
    }

    //analisa a diagonal principal do jogo em que "O" ganha
    if(jogo_da_velha[0][0] == 'O' && jogo_da_velha[1][1] == 'O' && jogo_da_velha[2][2] == 'O')
    return 1;

    //analisa a diagonal secundária do jogo em que "O" ganha
    else if(jogo_da_velha[2][0] == 'O' && jogo_da_velha[1][1] == 'O' && jogo_da_velha[0][2] == 'O')
    return 1;

    //analisa a diagonal principal do jogo em que "X" ganha
    else if(jogo_da_velha[0][0] == 'X' && jogo_da_velha[1][1] == 'X' && jogo_da_velha[2][2] == 'X')
    return -1;

    //analisa a diagonal secundária do jogo em que "X" ganha
    else if(jogo_da_velha[2][0] == 'X' && jogo_da_velha[1][1] == 'X' && jogo_da_velha[0][2] == 'X')
    return -1;

    //retorna 0 se nenhum dos 2 ganha
    return 0;
}

//fução que processa toda a partida e resolve o programa
void processa(FILE *arquivo_saida, char jogo_da_velha[][4], int parametro){

    //laços que analisam todo o "tabuleiro" do jogo
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){

            /*se o espaço estiver em branco ele será ocupado
            parametro = 1, vez do "O"
            parametro = -1, vez do "X"
            */

            if(jogo_da_velha[i][j] == 'B' && parametro == 1){
                
                //substitui o espaço em branco pelo "O"
                jogo_da_velha[i][j] = 'O';

                //troca o parametro, ou seja, passa a vez
                parametro = -1;

                //analisa se o jogo foi ganho pelo "O"
                if(vitoria(jogo_da_velha) == 1)
                    imprime(arquivo_saida, jogo_da_velha);
                
                //se ninguem vence a função é chamada novamente
                if(!vitoria(jogo_da_velha))
                    processa(arquivo_saida, jogo_da_velha, parametro);

                /*depois de analisar todos os casos de teste para uma posição, ela volta a ficar em branco
                e o parametro é resetado, dessa forma analisa todas as possibilidades de cada posição em formato
                de "árvore"
                */
                jogo_da_velha[i][j] = 'B';
                parametro = 1;

                }

            else if(jogo_da_velha[i][j] == 'B' && parametro == -1){
                
                //substitui o espaço em branco pelo "X"
                jogo_da_velha[i][j] = 'X';

                //troca o parametro, ou seja, passa a vez
                parametro = 1;

                //se ninguem vence a função é chamada novamente
                if(!vitoria(jogo_da_velha))
                    processa(arquivo_saida, jogo_da_velha, parametro);

                /*depois de analisar todos os casos de teste para uma posição, ela volta a ficar em branco
                e o parametro é resetado, dessa forma analisa todas as possibilidades de cada posição em formato
                de "árvore"
                */
                jogo_da_velha[i][j] = 'B';
                parametro = -1;
            }

            
        }
    }
}

//função que testa se a partida já veio ganha
void testa_inicio(FILE *arquivo_saida, char jogo_da_velha[][4]){

    //se "O", já tiver ganho, só imprime o tabuleiro
    if(vitoria(jogo_da_velha) == 1)
        imprime(arquivo_saida, jogo_da_velha);
    
    //se ninguém tiver ganho ainda processa o programa normalmente
    else if(!vitoria(jogo_da_velha)){
        int parametro = 1;
        processa(arquivo_saida, jogo_da_velha, parametro);    
    }

    //se "X" já tiver ganho não imprime nada
}