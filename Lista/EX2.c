#include <stdio.h>
#include <stdlib.h>

int* criarVetor(int n){
    int *vet = malloc(n * sizeof(int));
    return vet;
}

void mostrarVetor(int* vet, int n){
    int i;

    for(i = 0 ; i < n ; i++){
        printf("-%d-", *(vet + i));
    }

}

void liberarVetor(int* vet){

    free(vet);

}




main(){
    int *vet = criarVetor(10);
    int i;

    for(i = 0 ; i < 10 ; i++){
        printf("Digite um numero: ");
        scanf("%d", vet + i);
    }

    mostrarVetor(vet,10);

    liberarVetor(vet);

}
