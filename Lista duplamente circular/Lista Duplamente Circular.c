#include <stdlib.h>
#include <stdio.h>

typedef struct no{
        int valor;
        struct no *proximo;
        struct no *anterior;
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
void imprimir(No *no);
No* ultimo(Lista *lista);
void imprimirInverso(No *no);
void inserir_meio(Lista *lista, int num, int ant);

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
        novo->anterior = NULL;
        lista->inicio = novo;
        if(lista->fim == NULL)
            lista->fim = novo;
        lista->fim->proximo = lista->inicio;
        lista->tam++;
     }else
        printf("\nErro ao alocar mem�ria.\n");
}
//-------------------------------------------------------------
void inserir_meio(Lista *lista, int num, int ant){
     No *aux, *novo = malloc(sizeof(No));
     
     if(novo){
        novo->valor = num;
        
        if(lista->inicio == NULL){
            novo->proximo = NULL;
            novo->anterior = NULL;
            lista->inicio = novo;
        }else{
            aux = lista->inicio;
            while(aux->valor != ant && aux->proximo)
               aux = aux->proximo;
            novo->proximo = aux->proximo;
            if(aux->proximo)
               aux->proximo->anterior = novo;
            novo->anterior = aux;
            aux->proximo = novo;
        }
        lista->tam++;
     }else
        printf("\nErro ao alocar mem�ria.\n");  
} 
//-------------------------------------------------------------
void inserir_fim(Lista *lista, int num){
     No *novo, *aux = malloc(sizeof(No));
     
     if(novo){
         novo->valor = num;
         novo->proximo = NULL;
         
         if(lista->inicio == NULL){
            novo->anterior = NULL;
            lista->inicio = novo;
            lista->fim = novo;
            lista->fim->proximo = lista->inicio;
         }else{
            aux = lista->inicio;
            if(aux->proximo)
               aux= aux->proximo;               
            aux->proximo = novo;
            novo->anterior = aux;
            lista->fim->proximo = novo;
            lista->fim = novo;
            novo->proximo = lista->inicio;
         }
         lista->tam++;
     }else
         printf("\nErro ao alocar mem�ria.\n");
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
            while(aux->proximo && aux->proximo != lista->inicio && novo->valor > aux->proximo->valor){
                  aux = aux->proximo;
            if(aux->proximo == lista->inicio)
                inserir_fim(lista, num);
            else{
                if(aux->proximo)
                   aux->proximo->anterior = novo;
                novo->anterior = aux;
                novo->proximo = aux->proximo;
                aux->proximo = novo;
                lista->tam++;
            }
         }
     }
     }else
         printf("\nErro ao alocar mem�ria.\n"); 
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
          while(aux->proximo && aux->proximo != lista->inicio && aux->proximo->valor != num){
            aux = aux->proximo;
          if(aux->proximo->valor == num){
             if(lista->fim == aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                lista->fim = aux;
                if(aux->proximo)
                  aux->proximo->anterior = aux;
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
void imprimir(No *no){
    printf("\nLista: ");
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");        
}
//-------------------------------------------------------------
No* ultimo(Lista *lista){
    No *aux = lista->inicio;
    while(aux->proximo)
        aux = aux->proximo;
    return aux;
}
//-------------------------------------------------------------
void imprimirInverso(No *no){
printf("\nLista: ");
    while(no){
        printf("%d ", no->valor);
        no = no->anterior;
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
             "\n3 - Inserir ordenador\n4 - Remover\n5 - Imprimir\n6 - Buscar\n"
             "7 - Inserir no meio\n\n");
      scanf("%d", &opcao);
      
      switch(opcao){
          case 1:
              printf("\nValor: ");
              scanf("%d", &valor);
              inserir_inicio(&lista, valor);
          case 2:
              printf("\nValor: ");
              scanf("%d", &valor);
              inserir_fim(&lista, valor); 
          case 3:
              printf("\nValor: ");
              scanf("%d", &valor);
              inserir_ordenado(&lista, valor);
          case 4:
              printf("\nValor: ");
              scanf("%d", &valor);
              no = remover(&lista, valor);
              if(no){
                 printf("Elemento a ser removido: %d\n", no->valor);
                 free(no);
              }else
                   printf("Elemento n�o exista.\n");
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
          case 7:
               printf("\nValor: ");
               scanf("%d%d", &valor);
               inserir_fim(&lista, valor); 
               break;
          case 8:
               imprimirInverso(ultimo(&lista));
               break;
          default:
              if(opcao != 0)
                 printf("Opcao Invalida\n");
      }
    }while(opcao != 0);
}
}

