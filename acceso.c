#include "acceso.h"
void acceso(int n, usuarios *usu){

    int i,contador=0;
    int existe=0;
    char user[6];
    char pass[9];
    error:
        contador++;
    if(contador!=3){
        printf("User: ");
        flush_in();
        scanf("%5[^\n]",user);

        printf("Password: ");
        flush_in();
        scanf("%8[^\n]",pass);

        for(i=0;i<n;i++){

            if(strcmp(usu[i].usuario,user)==0) {
                existe=1;
                if(strcmp(usu[i].pass,pass)==0){
                    if(strcmp(usu[i].perfil_usuario,"profesor")==0){
                        profesor(i);
                    }
                    if(strcmp(usu[i].perfil_usuario,"administrador")==0){
                        administrador();
                    }
                }
                else{
                    puts("Usuario y/o Contraseña Incorrecta.\n");
                        goto error;
                }
            }
        }
        if(existe==0) puts("El usuario no esta registrado en el sistema.\n");
    } else printf("Limite de Intentos Superado.\n");
}

