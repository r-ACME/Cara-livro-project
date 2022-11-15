#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "caralivropattern.h"

int main()
{

    time_t t;
    srand((unsigned)time(&t));

    int opcao = -1, indice = 0, item = 0;

    while (opcao != 0){
        clearscreen();
        header();

        printf("\n1 - Entrar");
        printf("\n2 - Cadastrar");
        printf("\n\n0 - Sair");
        printf("\n---> ");

        scanf("%i", &opcao);
        getchar();

        switch(opcao){
            case 1:
                signin();
                break;
            case 2:
                mainpage();
                break;
            default:
                printf("Opção invalida!!");
                break;
        }
    }
    return SUCESSO;
}
