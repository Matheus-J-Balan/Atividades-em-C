#include <stdio.h>
#include <stdlib.h>
#define tamanho 5 

typedef struct{
        int dados[tamanho];
        int ini;
        int fim;
}Pilha;

Pilha pilha;
int op;

void pilha_entrar();
void pilha_sair();
void pilha_mostrar();
void menu_mostrar();

//--------------------------------------------------------------------
void pilha_entrar(){
    if(pilha.fim == tamanho){ 
     printf("\nA pilha esta cheia, impossivel empilhar!\n\n");
     system("pause");
    }else{
      printf("\nDigite o valor a ser empilhado: ");
      scanf("%d",&pilha.dados[pilha.fim]);
      pilha.fim++;
    }
}
//-----------------------------------------------------------------------
void pilha_sair(){
     if(pilha.ini=pilha.fim){
       printf("\nA pilha esta vazia, impossivel desempilhar!\n\n");
       system("pause");
     }else{
       pilha.dados[pilha.fim-1]=0;
       pilha.fim--;
     }
}
//-------------------------------------------------
void pilha_mostrar(){
     int i;
     printf("[ ");
     for(i=0;i<tamanho;i++)
        printf("%d",pilha.dados[i]);
     printf("]\n\n");
}
//-------------------------------------------------
void menu_mostrar(){
     printf("\nEscolha uma opcao:\n");
     printf("1-Empilhar\n");
     printf("2-Desenpilhar\n");
     printf("0-Sair\n");
}

//-------------------------------------------------
int main(){
    op=1;
    pilha.ini=0;
    pilha.fim=0;
    while(op!=0){
      system("clear");
      pilha_mostrar();
      menu_mostrar();
      scanf("%d",&op);
      switch(op){
          case 1:
               pilha_entrar();
               break;
          case 2:
               pilha_sair();
               break;
      }
    }
   return 0;
}  
            
