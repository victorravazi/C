#include <stdio.h>
#include "biblio.h"

/*Crie uma biblioteca com um struct operador e os atributos numéricos
A, B e resultado. Implemente funções de soma, subtração,
multiplicação e divisão que receba como parâmetro e retorne o
operador.

Sugestão: Para o projeto final, crie uma biblioteca para a struct de seu
projeto e as funções de ler do arquivo e escrever no arquivo.*/

int main(){
    int sair = -1;
    int opcao = 0;
    int x = 0;
    int y = 0;
    int resultado = 0;
    float resultadoDivisao = 0;
    while (sair != 5)
    {
        printf("Digite qual operacao voce deseja\n");
        printf("1 - Soma\n");
        printf("2 - Subtracao\n");
        printf("3 - Multiplicacao\n");
        printf("4 - Divisao\n");
        printf("5 - Fechar programa\n");
        scanf("%d", &opcao);


        switch (opcao)
        {
        case 1:
            printf("Digite o primeiro valor\n");
            scanf("%d", &x);

            printf("Digite o segundo valor\n");
            scanf("%d", &y);

            resultado = soma(x,y);
            printf("Resultado da soma: %d\n", resultado);
            break;
        case 2:
            printf("Digite o primeiro valor\n");
            scanf("%d", &x);

            printf("Digite o segundo valor\n");
            scanf("%d", &y);

            resultado = subtracao(x,y);   
            printf("Resultado da subtracao: %d\n", resultado);

            break;
        case 3:
            printf("Digite o primeiro valor\n");
            scanf("%d", &x);

            printf("Digite o segundo valor\n");
            scanf("%d", &y);

            resultado = multiplicacao(x,y);
            printf("Resultado da multiplicacao: %d\n", resultado);
            break;         
        case 4:
            printf("Digite o primeiro valor\n");
            scanf("%d", &x);

            printf("Digite o segundo valor\n");
            scanf("%d", &y);

            resultadoDivisao = divisao(x,y);
            printf("Resultado da divisao: %.2f\n", resultadoDivisao);
            break;
        case 5:
            sair = 5;
            printf("Fechando programa\n");
            break;
        default:
            printf("Valor invalido\n");
            break;
        }
    }

    

    return 0;
}
