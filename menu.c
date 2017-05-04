#include "menu.h"
void inicio(){

    int opc=0;

    while(opc!=2){

        puts("* * * * * * * * * * * * * * * * * *");
        puts("* Bienvenido a su libreta digital *");
        puts("* * * * * * * * * * * * * * * * * *");
        printf("\n");
        puts("* * * * * * * * * * * * * * * * * *");
        puts("*   1. Iniciar Sesion             *");
        puts("*   2. Guardar Cambios y Salir    *");
        puts("* * * * * * * * * * * * * * * * * *");
        printf("Seleccione una opcion : ");
        fflush(stdin);
        scanf("%d",&opc);
        //system("clear");

        switch(opc){

            case 1:
                acceso(num_user,al_user);
                break;
            default:
                //cerrar programa
                break;

        }

    }

}
