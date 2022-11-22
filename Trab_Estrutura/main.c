#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

void main(){
	
	Produto p;
	
	Produto *head = NULL;
	int x, desconto, codProduto, qntdProduto, opcao, qntdCadastro;
	int menu = 1;
	
	while(menu){
		system("cls");
		printf(" 1 - Cadastrar produto \n 2 - Inserir desconto produto \n 3 - Comprar \n 4 - Imprimir lista produtos \n 0 - Finalizar \n");
		printf("\n Opicao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1: 
				system("cls");
				printf("Quantos produtos pretende cadastrar: ");
				scanf("%d", &qntdCadastro);
				for(x = 0; x <qntdCadastro; x++){
					p = cadastrar();
					Inserir_Lista(&head, p);
				}
			break;
			case 2:
				system("cls");
				printf("\nDigite a porcentagem de desconto: ");
				scanf("%d", &desconto);
	
				Desconto(&head, desconto);
			break;
			case 3:
				system("cls");
				printf("Digite o codigo do produto que deseja comprar: ");
				scanf("%d", codProduto);
				printf("Digite a quantidade do produto que deseja comprar: ");
				scanf("%d", qntdProduto);
				
				Compra(&head, qntdProduto, codProduto);
			break;
			case 4:
				system("cls");
				Imprimir_Lista(head);
				system("pause");
			break;
			default:
				system("cls");
				menu = 0;
				printf("Finalizando o sistema");
			break;
		}
	}
	
}

