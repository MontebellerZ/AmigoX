#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>


//funcoes

void L(){
    printf("\n\n");
}



//main

//verificacao de numero de jogadores

int main(){

    printf("Bem-vindo ao melhor programa para sorteio de Amigo X!\n");
    L();
    printf("Digite o numero de participantes da brincadeira: ");

    int X;

    scanf("%i", &X);

//verificacao de numero de jogadores incorreto

    while (X<=1){

        L();

        printf("Impossivel brincar com essa quantidade de participantes!");

        L();

        printf("Digite '1' se quiser inserir um numero de participantes valido\nOU\ninsira qualquer outro digito para encerrar o programa.\n\n");

        int verificar;

        scanf("%i", &verificar);

        if(verificar!=1){
            exit(1);
        }

        L();

        printf("Digite o numero de participantes da brincadeira: ");

        scanf("%i", &X);
    }

    L();

//onde tudo acontece

    int i, j;

    int *V_X = (int*)malloc(X * sizeof(int));

    for (i=0;i<X;i++){
        V_X[i] = -1;
    }

    srand(time(NULL));

    for (i=0;i<X;i++){

        V_X[i] = rand() % X;

        while (V_X[i] == i){
            V_X[i] = rand() % X;
        }

        for (j=0; j<i; j++){

            if (V_X[i] == V_X[j] || V_X[i] == i){

                V_X[i] = rand() % X;

                j = -1;
            }
        }
    }

//vinculo do nome do jogador ao sorteio

    char **V_N = (char**)malloc(X * sizeof(char*));

    for (i=0;i<X;i++){

        V_N[i] = (char*)malloc(50 * sizeof(char));

        printf("Digite o nome do participante numero %i: ", i+1);

        scanf(" %s", V_N[i]);
    }

    L();

    printf("Agora vou apagar a tela para mostrar os resultados de acordo com seu pedido, ok?\n\nPressione Enter para continuar.");
    getch();
    system("cls");


//print de resultados

    int Z = 0, novo = 0;

    while(Z == 0 || novo == 1){

        Z = 1;

        printf("Escolha um dos nomes da tabela a seguir para saber quem eh o seu Amigo X!\n\n");
        printf("******************************************\n");
        printf("*  Para escolher um dos nomes da tabela  *\n");
        printf("* digite o numero correspondente ao nome *\n");
        printf("******************************************\n");

        for (i=0;i<X;i++){
            printf(" %i = %s\n", i+1, V_N[i]);
        }

        L();
        printf("Digite o numero correspondente a pessoa que deseja: ");
        int escolha;
        scanf(" %i", &escolha);

        while (escolha>X || escolha<1){

            system("cls");

            L();

            printf("Voce digitou um numero que nao corresponde a nenhum nome!");

            L();

            printf("******************************************\n");
            printf("*  Para escolher um dos nomes da tabela  *\n");
            printf("* digite o numero correspondente ao nome *\n");
            printf("******************************************\n");

            for (i=0;i<X;i++){
                printf(" %i = %s\n", i+1, V_N[i]);
            }

            L();

            printf("Digite o NUMERO correspondente a pessoa que deseja: ");

            scanf(" %i", &escolha);
        }

        escolha--;

        system("cls");

        L();

        printf("A pessoa que voce escolheu eh: %s\nDeseja continuar? Tenha certeza de que apenas voce esta olhando a tela! kkkk\n", V_N[escolha]);
        printf("\nPara continuar digite '1'. Caso tenha feito a escolha errada digite qualquer outro numero.\n");
        printf("\ndigitando: ");

        int sim;

        scanf(" %i", &sim);

        L();

        if (sim == 1){
            system("cls");
            printf("O seu Amigo X eh o/a %s!!! Parabens %s e boas compras!!!\n\n", V_N[ V_X[escolha] ], V_N[escolha]);


            printf("Pressione enter para apagar a tela assim que ja tiver anotado o seu Amigo X!");
            getch();
            system("cls");

            L();

            printf("*********************************************\n");
            printf("*                  ATENCAO                  *\n");
            printf("*                                           *\n");
            printf("*  Se o programa for fechado ou finalizado  *\n");
            printf("*   antes que todos  anotem seus Amigos X   *\n");
            printf("*    o sorteio sera perdido para sempre,    *\n");
            printf("*   ocasionando na necessidade de repetir   *\n");
            printf("*     todo o processo novamente ate que     *\n");
            printf("*        todos anotem seus Amigos X.        *\n");
            printf("*********************************************\n");

            L();

            printf("Desejam ver o Amigo X de outra pessoa da tabela?\n");
            printf("Digite 1 para ver o de outra pessoa\nOU\nInsira qualquer outro numero para finalizar o programa.\n");
            printf("\n\nDigitando: ");

            scanf(" %i", &novo);

            L();

            if (novo!=1){

                printf("Tem certeza que deseja encerrar o programa?\nSe sim digite '1', se nao insira outro numero.\n\nDigitando: ");
                scanf(" %i", &novo);

                if (novo==1){
                    novo = 0;
                }

                else{
                    novo = 1;
                    system("cls");
                }
            }
            system("cls");
        }
        else{
            novo = 1;
            system("cls");
        }
    }
    system("cls");
    printf("Obrigado por utilizar nosso programa!\nAte a proxima!\n");
    L();
    L();
    printf("\n:3  :3  :3  :3  :3  :3\n\n");
    L();
    L();
    printf("By: MontebellerZ");
    L();
    L();
    L();

    return 0;
}
