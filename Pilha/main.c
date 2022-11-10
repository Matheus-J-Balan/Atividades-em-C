#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

int main(){
    op=1;
    pilha.ini=0;
    pilha.fim=0;
    while(op!=0){
       system("cls");
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
    return(0);
}
