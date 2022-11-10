#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct Elemento_pilha{
	int num;
	struct Elemento_pilha *prox;
};
typedef struct Elemento_pilha Elemento_pilha;


struct Pilha{
    struct Elemento_pilha *topo;
};
typedef struct Pilha Pilha;

 
 Elemento_pilha *aux ;


 
struct Elemento_fila{
	int num;
	struct Elemento_fila *prox;
};
typedef struct Elemento_fila Elemento_fila;


struct Fila{
    struct Elemento_fila *inicio; 
    struct Elemento_fila *fim; 
};
typedef struct Fila Fila;

 
 Elemento_fila *aux2 ;


 Pilha* cria_pilha(){
	
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->topo= NULL;  
    }
    return pi;
}

Fila* cria_fila(){

    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
	
        fi->fim = NULL;
        fi->inicio = NULL;
    }
    return fi;
}


void insere_elemento_pilha(Pilha *pi){
	
	Elemento_pilha *novo =(Elemento_pilha*) malloc(sizeof(Elemento_pilha));
	printf("\nDigite o numero a ser inserido na pilha: ");
	scanf("%d",&novo->num);

	novo->prox = pi->topo;

	pi->topo = novo;
	printf("\nNumero inserido na pilha!\n");
	getch();
}

void insere_elemento_fila(Fila *fi){
	
	Elemento_fila *novo =(Elemento_fila*) malloc(sizeof(Elemento_fila));
	printf("\nDigite o numero a ser inserido na fila: ");
	scanf("%d",&novo->num);
	novo->prox = NULL;
	
	if(fi->inicio == NULL){
		fi->inicio = novo;
		fi->fim = novo;
	
	}else{
		fi->fim->prox = novo;
		fi->fim = novo;
	}
	printf("\nNumero inserido na fila!\n");
	getch();
}


void consulta_iguais(Pilha *pi, Fila *fi){
    int achou;
    aux = pi->topo;
   
    do{
        achou = 0;
        aux2 = fi->inicio;
         
        do{
            if(aux2->num == aux->num)
                achou ++;
            aux2 = aux2->prox;
        } while(aux2 != NULL);

        if(achou > 0)
            printf(" %d", aux->num);
        aux = aux->prox;
    } while(aux != NULL);
	getch();
}

void consulta_fila(Pilha *pi, Fila *fi){
    int achou;
    aux2 = fi->inicio;
    
    do{
        achou = 0;
        aux = pi->topo;
       
        do{
            if(aux2->num == aux->num)
                achou ++;
            aux = aux->prox;
        } while(aux != NULL);
        if(achou == 0)
            printf(" %d", aux2->num);
        aux2 = aux2->prox;
    } while(aux2 != NULL);
	getch();
}

void consulta_pilha(Pilha *pi, Fila *fi){
    int achou;
    aux = pi->topo;
    
    do{
        achou = 0;
        aux2 = fi->inicio;
        
        do{
            if(aux2->num == aux->num)
                achou ++;
            aux2 = aux2->prox;
        } while(aux2 != NULL);
        if(achou == 0)
            printf(" %d", aux->num);
        aux = aux->prox;
    } while(aux != NULL);
	getch();
}


void esvazia_pilha(Pilha *pi){
	if(pi->topo == NULL){
		printf("\nPilha Vazia!!");
	}else{
		aux = pi->topo;
		do{
			pi->topo = pi->topo->prox;
			free(aux);
			aux = pi->topo;
		}while(aux != NULL);
		printf("\nPilha Esvaziada!!");
	}
	getch();
}

void esvazia_fila(Fila *fi){
	if(fi->inicio == NULL){
		printf("\nFila Vazia!!");
	}else{
		aux2 = fi->inicio;
		do{
			fi->inicio = fi->inicio->prox;
			free(aux2);
			aux2 = fi->inicio;
		}while(aux2 != NULL);
		printf("\nFila Esvaziada!!");
	}
	getch();
}

int main(){
    int i;
	Pilha *pi = cria_pilha();
	Fila *fi = cria_fila();
	
	for(i = 1; i <= 5; i++ ){
        insere_elemento_pilha(pi);
        system("CLS");
	}
	
	for(i = 1; i <= 5; i++ ){
        insere_elemento_fila(fi);
        system("CLS");
	}
	
	printf("\nNumeros que estão nas duas estruturas\n");
	consulta_iguais(pi, fi);
	
	printf("\nNumeros que estão somente na fila\n");
	consulta_fila(pi, fi);

	printf("\nNumeros que estão somente na pilha\n");
	consulta_pilha(pi, fi);

	esvazia_fila(fi);
	esvazia_pilha(pi);
    return 0;
}
