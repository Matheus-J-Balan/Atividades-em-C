#include <stdlib.h>
#include <stdio.h>

typedef struct no{
        int valor;
        struct no *proximo;
}No;

void inserir_inicio(No **lista, int num);
void inserir_fim(No **lista, int num);
void inserir_meio(No **lista, int num, int ant);
void imprimir(No *no);
void inserir_ordenado(No **lista, int num);
No* remover(No **lista, int num);
No* buscar(No **lista, int num);


void inserir_inicio(No **lista, int num){
     No *novo = malloc(sizeof(No));
     
     if(novo){
         novo->valor = num;
         novo->proximo =*lista;
         *lista = novo;
     }else
           printf("\nErro ao alocar memoria.\n");
     
}

void inserir_fim (No **lista, int num){
     No *aux, *novo = malloc(sizeof(No));
     
     if(novo){
         novo->valor = num;
         novo->proximo = NULL;
         
         if(*lista == NULL)
             *lista = novo;
         else{
           aux = *lista;
           while(aux->proximo)
               aux = aux->proximo;
           aux->proximo = novo;
         }
     }else
         printf("\nErro ao alocar memoria\n");
}


void inserir_meio (No **lista, int num, int ant){
     No *aux, *novo = malloc(sizeof(No));
     
     if(novo){
        novo->valor = num;
        
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }else{
              aux = *lista;
              while(aux->valor != ant && aux->proximo)
                   aux = aux->proximo;
              novo->proximo = aux->proximo;
              aux->proximo = novo;
        }
     }else
        printf("\nErro ao alocar a memoria\n");
}

void inserir_ordenado(No **lista, int num){
     No *aux, *novo = malloc(sizeof(No));
     
     if(novo){
        novo->valor = num;
        if(*lista == NULL){
           novo->proximo = NULL;
           *lista = novo;
        }
        else if(novo->valor < (*lista)->valor){
             novo->proximo = *lista;
             *lista = novo;
        }
        else{
           aux = *lista;
           while(aux->proximo && novo->valor > aux->proximo->valor)
                 aux = aux->proximo;
           novo->proximo = aux->proximo;
           aux->proximo = novo;
        }
     }else
          printf("Erro ao alocar memoria!/n");
}
    
No* remover(No **lista, int num){
    No *aux, *remover = NULL;
    
    if(*lista){
       if((*lista)->valor == num){
          remover = *lista;
          *lista = remover->proximo;
       }else{
             aux = *lista;
             while(num != aux->proximo->valor && aux->proximo)
                aux = aux->proximo;
             if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
             }
       }
    }
    return remover;
}

No* buscar(No **lista, int num){
    No *aux, *no = NULL;
    
    aux = *lista;
    while(aux && aux->valor != num)
         aux = aux->proximo;
    if(aux)
       no = aux;
    return no;
}

void imprimir (No *no){
     printf("\nLista: ");
     while(no){
         printf("%d ", no->valor);
         no = no->proximo;
     }
     printf("\n\n");
}


int main(void){
    int opcao, valor, anterior;
    No *remove, *lista = NULL;
    
    do{
       printf("\n0 - Sair\n1 - Inserir no inicio\n2 - Inserir no fim"
         "\n3 - Inserir no meio\n4 - Imprimir\n5 - Inserir ordenado\n6 - Remover"
         "\n7 - Buscar\n");
       scanf("%d", &opcao);
       
       
        switch(opcao){
            case 1:
                 printf("\nValor: ");
                 scanf("%d", &valor);
                 inserir_inicio(&lista, valor);
                 break;
            case 2:
                 printf("\nValor: ");
                 scanf("%d", &valor);
                 inserir_fim(&lista, valor);
                 break;
            case 3:
                 printf("\nValor: ");
                 scanf("%d%d", &valor, &anterior);
                 inserir_meio(&lista, valor, anterior);
                 break;
            case 4:
                 imprimir(lista);
                 break;
            case 5:
                 printf("\nValor: ");
                 scanf("%d", &valor);
                 inserir_ordenado(&lista, valor);
                 break;
            case 6:
                 printf("\nValor: ");
                 scanf("%d", &valor);
                 remove = remover(&lista, valor);
                 if(remove){
                    printf("Elemento a ser removido: %d\n", remove->valor);
                    free(remove);
                    }
                 break;
            case 7:
                 printf("\nValor: ");
                 scanf("%d", &valor);
                 remove = buscar(&lista, valor);
                 if(remove){
                    printf("Elemento buscado: %d\n", remove->valor);
                    }else{
                       printf("Elemento nao encontrado!\n");  
                    }
                 break;
            default:
                 if (opcao != 0)
                    printf("Opcao invalida\n");
        }   
    }while(opcao != 0);
}
                 

