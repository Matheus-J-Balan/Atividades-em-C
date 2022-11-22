#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"


int lista_vazia(Produto *head){
	
	if(head == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

Produto cadastrar (){
	Produto P;
	
	printf("\nDigite o codigo do produto: ");
	scanf("%d", &P.codigo);
	printf("Digite o nome do produto: ");
	scanf("%s", P.nome);
	fflush(stdin);
	printf("Digite a descricao do produto: ");
	scanf("%s", P.descricao);
	fflush(stdin);
	printf("Digite o preco do produto: ");
	scanf("%f", &P.preco);
	printf("Digite a quantidade do produto: ");
	scanf("%d", &P.quantidade);
	
	return P;
}

void Inserir_Lista(Produto **head, Produto p){

	Produto *novo = malloc(sizeof(Produto));
	
	novo->codigo = p.codigo;
	*(novo->descricao) = p.descricao;
	*(novo->nome) = p.nome;
	novo->preco = p.preco;
	novo->quantidade = p.quantidade;
	
	novo->prox = NULL;
	
	if(lista_vazia(*head)){
		*head = novo;
		return;
	}
	
	Produto *temp = *head;
	
	while(temp->prox != NULL){
		temp = temp->prox;
	}	
	
	temp->prox = novo;
	
}

void Imprimir_Lista(Produto *head){
	
	int i = 1;
	
	Produto *temp = head;
	
	while(temp != NULL){
		printf("\nProduto %d: ", i);
		printf("codigo: %d Nome produto: %s Descricao produto: %s preco: %.2f quantidade: %d", temp->codigo, temp->nome, temp->descricao, temp->preco, temp->quantidade);
		printf("\n");
		temp = temp->prox;
		i++;
	}
	
}

void Desconto(Produto **head, int desconto){
	
	float DescoTotal;
	
	Produto *temp = *head;
	
	while(temp != NULL){
		DescoTotal = (temp->preco/100) * desconto;
		temp->preco = temp->preco - DescoTotal;
		temp = temp->prox;
	}
}

void Compra(Produto **head, int qntdcompra, int codProduto){
	
	Produto *temp = *head;
	
	while(temp != NULL){
		if(temp->codigo == codProduto){
			break;
		}
		temp = temp->prox;
	}
	
	if(temp->quantidade < qntdcompra){
		printf("Quantidade insuficiente! (Quantidade estoque no momento: %d)", temp->quantidade);
	}else{
		temp->quantidade = temp->quantidade - qntdcompra;
		printf("Compra realizada com sucesso!");
	}
	
}
