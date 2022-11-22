#ifndef TRAB_H
#define TRAB_H
#include <stdlib.h>
#include <stdio.h>

typedef struct produto Produto;

struct produto{
	
	int codigo;
	char nome[50];
	char descricao[100];
	float preco;
	int quantidade;
	Produto* prox;
	
};

int lista_vazia(Produto *head);

Produto cadastrar ();

void Inserir_Lista(Produto **head, Produto p);

void Imprimir_Lista(Produto *head);

void Desconto(Produto **head, int desconto);

void Compra(Produto **head, int qntdcompra, int codProduto);

#endif
