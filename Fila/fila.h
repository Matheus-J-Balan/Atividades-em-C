#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tamanho 5

struct tfila{
       int dados[tamanho];
       int ini;
       int fim;
};

struct tfila fila;
int op; 

void fila_entrar();
void fila_sair();
void fila_mostrar();
void menu_mostrar();

#endif

