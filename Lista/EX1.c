#include <stdio.h>
#include <stdlib.h>

int* preencherVetor(int *vet,  int n){
    int i;

    for( i = 0 ; i < n; i++){
        printf("digite um numero: ");
        scanf("%d", vet+i);
        printf("\n");
    }
}

void mostrarVetor( int *vet, int n){
    int i;

    for( i = 0 ; i < n; i++){
        printf("- %d - ", *(vet+i));
    }
}

int main(){
    int n;
    int *vet;
    
    printf("Digite um tamanho para o vetor:\n");
    scanf("%d", &n);

    vet = malloc(n * sizeof(int));

    preencherVetor(vet,n);

    mostrarVetor(vet,n);

}
