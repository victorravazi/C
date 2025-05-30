#include <stdio.h>
#include "funcoes.h"
#include "pss.h"

int main() {
    Produto produtos[MAX_PRODUTOS];
    int quantidade = 0;
    int opcao;

    carregarProdutos(produtos, &quantidade);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Inserir produto\n");
        printf("2. Alterar produto\n");
        printf("3. Excluir produto\n");
        printf("4. Listar produtos\n");
        printf("5. Pesquisar por ID\n");
        printf("6. Sair\n");
        opcao = input_d("Escolha uma opção: ");

        switch(opcao) {
            case 1: inserirProduto(produtos, &quantidade); break;
            case 2: alterarProduto(produtos, quantidade); break;
            case 3: excluirProduto(produtos, &quantidade); break;
            case 4: listarProdutos(produtos, quantidade); break;
            case 5: pesquisarPorID(produtos, quantidade); break;
            case 6: salvarProdutos(produtos, quantidade); printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while(opcao != 6);

    return 0;
}
