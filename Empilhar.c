#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[50];
    Data data;
}Pessoa;

typedef struct no{
    Pessoa p;
    struct no*proximo;
}No;
        
Pessoa ler_pessoa(){
       Pessoa p;
       printf("\nDigite um nome: \n");
       scanf("%49[^\n]",p.nome);
       printf("Digite a data de nascimento (dd,mm,aaaa): \n");
       scanf("%d%d%d",&p.data.dia,&p.data.mes,&p.data.ano);
       return p;
}

void imprimir_pessoa(Pessoa p){
     printf("Nome: %s\nData: %2d/%2d/%4d\n",p.nome,p.data.dia,p.data.mes,p.data.ano);
}

No *empilhar(No *topo){
    No *novo = malloc(sizeof(No));
    
    if(novo){
      novo->p = ler_pessoa();
      novo->proximo = topo;
      return novo;
    }else
      printf("\nErro ao alocar memoria...\n");
    return NULL;
}

void imprimir_pilha(No *topo){
     printf("\n--------Pilha--------\n");
     while(topo){
         imprimir_pessoa(topo->p);
         topo = topo->proximo;
     }
     printf("\n--------Fim Pilha--------\n");
}

int main(void){
    No *topo=NULL;
    int opcao;
    
    do{
        printf("\n0 - Sair\n1 - Empilhar\n2 - Imprimir\n");
        scanf("%d",&opcao);
        getchar();
        
        switch(opcao){
              case 1:
                   topo = empilhar(topo);
                   break;
              case 2:
                   imprimir_pilha(topo);
                   break;
              default:
                   if(opcao!=0)
                      printf("\nOpcao invalida!\n");
        }
    }while (opcao != 0);
    return 0 ;
    
}   
    
           



       
