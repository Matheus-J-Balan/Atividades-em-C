#include <stdio.h>
#include <stdlib.h>

typedef struct no{
        int valor;
        struct no *proximo;
}No;

typedef struct{
        No *inicio;
        int tam;
}Lista;

void criar_lista(Lista *lista);
void inserir_inicio(Lista *lista, int num);
void inserir_meio(Lista *lista, int num, int ant);
void imprimir(Lista lista);
void inserir_fim(Lista *lista, int num);
No* remover(Lista *lista, int num);
No* buscar(Lista *lista, int num);
void inserir_ordenado(Lista *lista, int num);

//------------------------------------------------
void criar_lista(Lista *lista){
     lista->inicio = NULL;
     lista->tam = 0;
}
//------------------------------------------------
void inserir_inicio(Lista *lista, int num){
     No *novo = malloc(sizeof(No));
     
     if(novo){
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
        }else
           printf("\nErro ao alocar a memoria\n");
}
//------------------------------------------------------------------
void inserir_fim(Lista *lista, int num){
     No *aux, *novo = malloc(sizeof(No));
     
     if(novo){
        novo->valor = num;
        novo->proximo = NULL;
        
        if(lista->inicio == NULL)
           lista->inicio = novo;
        else{
           aux = lista->inicio;
           while(aux->proximo)
             aux = aux->proximo;  
           aux->proximo = novo;
        }
        lista->tam++;
     }else
         printf("\nErro ao alocar a memoria\n");
}   
//-------------------------------------------------------
void inserir_meio(Lista *lista, int num, int ant){
     No *aux, *novo = malloc(sizeof(No));
     
     if(novo){
        novo->valor = num;
        
        
        if(lista->inicio == NULL){
           novo->proximo = NULL;
           lista->inicio = novo;
        }else{
           aux = lista->inicio;
           while(aux->valor != ant && aux->proximo)
              aux = aux->proximo;
           novo->proximo = aux->proximo;
           aux->proximo = novo;
        }
        lista->tam++;
     }else
        printf("\nErro ao alocar a memoria\n");   
}
//----------------------------------------------------------------
void inserir_ordenado(Lista *lista, int num){
     No *aux, *novo = malloc(sizeof(No));
     
     if(novo){
        novo->valor = num;
        if(lista->inicio == NULL){
           novo->proximo = NULL;
           lista->inicio = novo;
        }
        else if(novo->valor < lista->inicio->valor){
             novo->proximo = lista->inicio;
             lista->inicio = novo;
        }
        else{
           aux = lista->inicio;
           while(aux->proximo && novo->valor > aux->proximo->valor)
                 aux = aux->proximo;
           novo->proximo = aux->proximo;
           aux->proximo = novo;
        }
        lista->tam++;
     }else
          printf("Erro ao alocar memoria!/n");
}
        
//----------------------------------------------------------------
No* remover(Lista *lista, int num){
    No *aux, *remover = NULL;
    
    if(lista->inicio){
       if(lista->inicio->valor == num){
          remover = lista->valor;
          lista->inicio = remover->proximo;
          lista->tam++;
       }
       else{
          aux = lista->inicio;
          while(aux->proximo && aux->proximo->valor != num)
              aux = aux->proximo;
          if(aux->proximo) 
              remover = aux->proximo;
              aux->proximo = remover->proximo;
              lista->tam--;
          }
       }
    }
    return remover;
}
//--------------------------------------------------------------------
No* buscar(Lista *lista, int num){
    No *aux, *no = NULL;
    
    aux = lista->inicio;
    while(aux && aux->valor != num)
         aux = aux->proximo;
    if(aux)
       no = aux;
    return no;
}

//------------------------------------------------------------------     
void imprimir(Lista lista){
     No *no = lista.inicio;
     printf("\nTamanho da Lista: %d -> Lista: ", lista.tam);
     while(no){
       printf("%d ", no->valor);
       no = no->proximo;
     }
     printf("\n\n");
}
//---------------------------------------------------------------
int main(void){
    int opcao, valor, anterior;
    Lista lista;
    No *removido, *encontrado;
    
    criar_lista(&lista);
    
    do{
      printf("\n0 - Sair\n1 - Inserir no inicio\n2 - Inserir no fim"
             "\n3 - Inserir no meio\n4 - Inserir ordenado\n5 - Remover\n6 - Imprimir"
             "\n7 - Buscar\n");
      scanf("%d", &opcao);
      
      switch(opcao){
            case 1: 
                 printf("\nValor: ");
                 scanf("%d",&valor);
                 inserir_inicio(&lista, valor);
                 break;
            case 2:
                 printf("\nValor: ");
                 scanf("%d",&valor);
                 inserir_fim(&lista, valor); 
                 break;
            case 3:
                 printf("\nValor(Valor depois o anterior): ");
                 scanf("%d%d",&valor, &anterior);
                 inserir_meio(&lista, valor, anterior); 
                 break;    
            case 4:
                 printf("\nValor: ");
                 scanf("%d",&valor);
                 inserir_ordenado(&lista, valor);
                 break;
            case 5:
                 printf("\nValor: ");
                 scanf("%d", &valor);
                 removido = remover(&lista, valor);
                 if(removido){
                    printf("Elemento a ser removido: %d\n", removido->valor);
                    free(remove);
                    }
                    else{
                       printf("Elemento nao encontrado!\n");  
                    }
                 break;
                 
            case 6:
                 imprimir(lista);
                 break;
            case 7:
                 printf("\nValor: ");
                 scanf("%d", &valor);
                 encontrado = buscar(&lista, valor);
                 if(encontrado){
                    printf("Elemento encontrado: %d\n", encontrado->valor);
                    }
                    else{
                       printf("Elemento nao encontrado!\n");  
                    }
                 break;
            default:
                 if(opcao != 0)
                   printf("Opcao invalida\n");
      }
    }while(opcao != 0);
}









