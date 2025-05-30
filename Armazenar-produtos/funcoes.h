#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pss.h"

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    char tipo[30];
    float preco;
} Produto;

void carregarProdutos(Produto produtos[], int *quantidade) {
    FILE *arquivo = fopen("produtos.txt", "r");
    if (arquivo == NULL) {
        *quantidade = 0;
        return;
    }

    *quantidade = 0;
    while (fscanf(arquivo, "%d\n%49[^\n]\n%29[^\n]\n%f\n",
                  &produtos[*quantidade].id,
                  produtos[*quantidade].nome,
                  produtos[*quantidade].tipo,
                  &produtos[*quantidade].preco) == 4) {
        (*quantidade)++;
        if (*quantidade >= MAX_PRODUTOS) break;
    }

    fclose(arquivo);
}

void salvarProdutos(Produto produtos[], int quantidade) {
    FILE *arquivo = fopen("produtos.txt", "w");
    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "ID: %d\nNome: %s\nTipo: %s\nPreco: %.2f\n",
                produtos[i].id,
                produtos[i].nome,
                produtos[i].tipo,
                produtos[i].preco);
    }
    fclose(arquivo);
}

void inserirProduto(Produto produtos[], int *quantidade) {
    if (*quantidade >= MAX_PRODUTOS) {
        printf("Maximo de produtos atingido\n");
        return;
    }

    Produto novo;

    
    int maiorID = 0;
    for (int i = 0; i < *quantidade; i++) {
        if (produtos[i].id > maiorID) {
            maiorID = produtos[i].id;
        }
    }
    novo.id = maiorID + 1;

    printf("ID: %d\n", novo.id);
    input_s("Nome: ", novo.nome, sizeof(novo.nome));
    input_s("Tipo: ", novo.tipo, sizeof(novo.tipo));
    novo.preco = input_f("Preco: ");

    produtos[*quantidade] = novo;
    (*quantidade)++;
    printf("Produto inserido com sucesso!\n");
}

void alterarProduto(Produto produtos[], int quantidade) {
    int id = input_d("ID do produto a alterar: ");
    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].id == id) {
            input_s("Novo nome: ", produtos[i].nome, sizeof(produtos[i].nome));
            input_s("Novo tipo: ", produtos[i].tipo, sizeof(produtos[i].tipo));
            produtos[i].preco = input_f("Novo preco: ");
            printf("Produto alterado \n");
            return;
        }
    }

    printf("Produto nao encontrado\n");
}

void excluirProduto(Produto produtos[], int *quantidade) {
    int id = input_d("ID do produto a excluir: ");
    for (int i = 0; i < *quantidade; i++) {
        if (produtos[i].id == id) {
            for (int j = i; j < *quantidade - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            (*quantidade)--;
            printf("Produto excluido\n");
            return;
        }
    }

    printf("Produto nao encontrado\n");
}

void listarProdutos(Produto produtos[], int quantidade) {
    if (quantidade == 0) {
        printf("Nenhum produto cadastrado\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("\nID: %d\nNome: %s\nTipo: %s\nPreco: R$ %.2f\n", 
               produtos[i].id, produtos[i].nome, produtos[i].tipo, produtos[i].preco);
    }
}

void pesquisarPorID(Produto produtos[], int quantidade) {
    int id = input_d("ID do produto: ");
    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].id == id) {
            printf("\nID: %d\nNome: %s\nTipo: %s\nPreco: R$ %.2f\n", 
                   produtos[i].id, produtos[i].nome, produtos[i].tipo, produtos[i].preco);
            return;
        }
    }

    printf("Produto nao encontrado\n");
}

#endif
