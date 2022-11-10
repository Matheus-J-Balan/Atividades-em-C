#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fila.h"



int main(){
    op=1;
    fila.ini=0;
    fila.fim=0;
    while(op!=0){
       system("cls");
       fila_mostrar();
       menu_mostrar();
       scanf("%d",&op);
       switch(op){
            case 1:
                 fila_entrar();
                 break;
            case 2:
                 fila_sair();
                 break;
       }
    }
    return(0);
}
