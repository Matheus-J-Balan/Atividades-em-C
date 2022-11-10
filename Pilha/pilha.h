#ifndef PILHA_H
#define PILHA_H
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

#endif
