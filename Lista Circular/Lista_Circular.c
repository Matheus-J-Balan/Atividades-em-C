#include <stdlib.h>
#include <stdio.h>

typedef struct no{
        int valor;
        struct no *proximo;
}No;

typedef struct{
        No *inicio;
        No *fim;
        int tam;
}Lista;

void criar_lista(Lista *lista);
void inserir_inicio(Lista *lista, int num);
void inserir_fim(Lista *lista, int num);
void inserir_ordenado(Lista *lista, int num);
No* remover (Lista *lista, int num);
No* buscar(Lista *lista, int num);
void imprimir(Lista lista);

//-------------------------------------------------------------
void criar_lista(Lista *lista){
     lista->inicio = NULL;
     lista->fim = NULL;
     lista->tam = 0;
}
//-------------------------------------------------------------
void inserir_inicio(Lista *lista, int num){
     No *novo = malloc(sizeof(No));
     
     if(novo){
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        if(lista->fim == NULL)
            lista->fim = novo;
        lista->fim->proximo = lista->inicio;
        lista->tam++;
     }else
        printf("\nErro ao alocar memória.\n");
}
//-------------------------------------------------------------
void inserir_fim(Lista *lista, int num){
     No*aux, *novo = malloc(sizeof(No));
     
     if(novo){
         novo->valor = num;
         
         if(lista->inicio == NULL){
            lista->inicio = novo;
            lista->fim = novo;
            lista->fim->proximo = lista->inicio;
         }else{
            lista->fim->proximo = novo;
            lista->fim = novo;
            novo->proximo = lista->inicio;
         }
         lista->tam++;
     }else
         printf("\nErro ao alocar memória.\n");
}
//-------------------------------------------------------------
void inserir_ordenado(Lista *lista, int num){
     No *aux, *novo = malloc(sizeof(No));
     
     if(novo){
         novo->valor = num;
         if(lista->inicio == NULL){
             inserir_inicio(lista, num);
         }else if(novo->valor < lista->inicio->valor){
             inserir_inicio(lista, num);
         }else{
            aux = lista->inicio;
            while(aux->proximo != lista->inicio && novo->valor > aux->proximo->valor){
                  aux = aux->proximo;
            if(aux->proximo == lista->inicio)
                inserir_fim(lista, num);
            else{
                novo->proximo = aux->proximo;
                aux->proximo = novo;
                lista->tam++;
            }
            }
         }
     }else
         printf("\nErro ao alocar memória.\n"); 
}
//-------------------------------------------------------------
No* remover (Lista *lista, int num){
    No *aux, *remover = NULL;
    
    if(lista->inicio){
      if(lista->inicio == lista->fim && lista->inicio->valor == num){
          remover = lista->inicio;
          lista->inicio = NULL;
          lista->fim = NULL;
          lista->tam--;
      }else{
          aux = lista->inicio;
          while(aux->proximo != lista->inicio && aux->proximo->valor != num){
            aux = aux->proximo;
          if(aux->proximo->valor == num){
             if(lista->fim == aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                lista->fim = aux;
             }else{
                remover = aux->proximo;
                aux->proximo = remover->proximo;
             }
             lista->tam--;
          }
      }
    }
    return remover;
}
//-------------------------------------------------------------
No* buscar(Lista *lista, int num){
    No *aux = lista->inicio;
    
    if(aux){
       do{
         if(aux->valor == num)
             return aux;
         aux = aux->proximo;
       }while(aux != lista->inicio);
    }
    return NULL;
}
//-------------------------------------------------------------
void imprimir(Lista lista){
     No *no = lista.inicio;
     printf("\nTamanho da Lista: %d -> Lista: ", lista.tam);
     if(no){
        do{
          printf("%d ",no->valor);
          no = no->proximo;
        }while(no != lista.inicio);
        printf("\nInicio: %d\n", no->valor);
     }
     printf("\n\n");
}
//-------------------------------------------------------------         
int main(void){
    int opcao, valor, anterior;
    Lista lista;
    No *no;
    
    criar_lista(&lista);
    
    do{
      printf("\n0 - Sair\n1 - Inserir no inicio\n2 - Inserir no fim"
             "\n3 - Inserir ordenador\n4 - Remover\n5 - Imprimir\n6 - Buscar\n\n");
      scanf("%d", &opcao);
      
      switch(opcao){
          case 1:
              printf("\nValor: ");
              scanf("%d", &opcao);
              inserir_inicio(&lista, valor);
          case 2:
              printf("\nValor: ");
              scanf("%d", &opcao);
              inserir_fim(&lista, valor); 
          case 3:
              printf("\nValor: ");
              scanf("%d", &opcao);
              inserir_ordenado(&lista, valor);
          case 4:
              printf("\nValor: ");
              scanf("%d", &opcao);
              no = remover(&lista, valor);
              if(no){
                 printf("Elemento a ser removido: %d\n", no->valor);
                 free(no);
              }else
                   printf("Elemento não exista.\n");
                 break;
          case 5:
               imprimir(lista);
               break;
          case 6:
               printf("Valor busca: ");
               scanf("%d", &valor);
               no = buscar(&lista, valor);
               if(no)
                 printf("Valor encontrado: %d\n", no->valor);
               else
                 printf("Valor nao encontrado.\n");
                break;
          default:
              if(opcao != 0)
                 printf("Opcao Invalida\n");
      }
    }while(opcao != 0);
}

