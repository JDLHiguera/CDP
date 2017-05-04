#include "profesor.h"
//funcion que recibie una cadena y en la misma devuelve el dia de hoy
static void fdia(char [TAM_DCL+1]);
//funcion para elegir el grupo con el cual el profesor desea trabajar
static void seleccion_grupo(int ,int [] ,int [],int *);
//funcion que muestra las clases que tiene el profesor hoy
static int horario(int temp[],int temp2[],int ip,char hoy[]);
//funcion para mostar un menu
static void menu_grupo(int *);
//Funcion para listar todos los alumnos de la clase
static int listar(int ,int []);
//funcion para seleccionar un alumnos listado
static void seleccion_alum(int ,int[],int *);
//funcion para el submenu alumno
static int menu_alumno();
//funcion para mostras editar o elminar la ficha del alumno
static void ficha(int);
//funcion para mostras editar o elminar calificaciones de alumno
static void notas(int);
//Funcion para mostar editar o moficar las faltas de alumno
static void asistencia(int );

void fdia(char buffer[TAM_DCL+1]){

    setlocale(LC_TIME, "es_ES");
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer,TAM_DCL+1,"%u",timeinfo);

}

int horario(int temp[],int temp2[],int ip,char hoy[]){
    int i,j,k=1;
    printf("\n");
    for(i=0;i<num_hora;i++){
        if (strcmp(al_hora[i].id_profesor, al_user[ip].id_usuario) == 0 && strcmp(al_hora[i].dia_clase, hoy) == 0){
            for(j=0;j<num_mate;j++){
                if(strcmp(al_mate[j].id_materia,al_hora[i].id_materia)==0){
                    temp[k]=i;
                    temp2[k]=j;
                    printf("%i: Imparte %s en %s  a %s hora\n",k,al_mate[j].nombre_materia,al_hora[i].grupo,al_hora[i].hora_clase);
                    k++;
                }
            }
        }
    }
    return k;
}

void seleccion_grupo(int k,int vec[],int vec2[],int *gru){
    int opc=0,i,aux=0,aux2=0;
        printf("Seleccione una opcion : ");
    flush_in();
        scanf("%d",&opc);
    for(i=1;i<k;i++){
        if(opc==i){
            aux=vec[i];
            aux2=vec2[i];
        }
    }
    (*gru)=aux;
printf("%s %s %s\n",al_hora[aux].grupo,al_mate[aux2].nombre_materia,al_mate[aux2].abrev_materia);

}

void menu_grupo(int *opc){
    puts("* * * * * * * * * * * * * * * * * *");
    puts("*   1. Lista de Alumnos           *");
    puts("*   2. Cambiar de Grupo           *");
    puts("* * * * * * * * * * * * * * * * * *");
    printf("Seleccione una opcion : ");
    flush_in();
    scanf("%d",opc);
}

int listar(int gru,int clase[]){
int i,j=1;
    for(i=0;i<num_alum;i++){
        if(strcmp(al_alum[i].grupo,al_hora[gru].grupo)==0){
            printf("%d: %s\n",j,al_alum[i].nombre_alum);
            clase[j]=i;
            j++;
        }
    }
    return j;
}

void seleccion_alum(int j,int clase[],int *slc){
    int opc=0,i,aux=0;
    printf("Seleccione una opcion : ");
    flush_in();
    scanf("%d",&opc);
    for(i=1;i<j;i++){
        if(opc==i){
            aux=clase[i];

        }
    }
    (*slc)=aux;
    printf("%s %s\n",al_alum[aux].nombre_alum,al_alum[aux].grupo);
}

int menu_alumno(){
    int alumno=0;
    puts("* * * * * * * * * * * * * * * * * *");
    puts("*   1. Ficha del Alumno           *");
    puts("*   2. Calificaciones             *");
    puts("*   3. Faltas de Asistencia       *");
    puts("*   4. Volver                     *");
    puts("* * * * * * * * * * * * * * * * * *");
    printf("Seleccione una opcion : ");
    flush_in();
    scanf("%d",&alumno);
    return alumno;
}

void ficha(int slc){
    char resp=' ';
    int opc;
    printf("%s %s %s %s %s %s\n",
    al_alum[slc].id_alum,
    al_alum[slc].nombre_alum,
           al_alum[slc].direc_alum,
           al_alum[slc].local_alum,
           al_alum[slc].curso,
           al_alum[slc].grupo);

    printf("DESEA MODIFICAR LOS DATOS S/N\n");
    printf("SELECCIONE UNA OPCION : ");
    flush_in();
    scanf("%c",&resp);

    if(resp=='s'||resp=='S') {
        printf("QUE DESEA CAMBIAR\n");
        printf(" 1. ID\n");
        printf(" 2. NOMBRE\n");
        printf(" 3. DIRECCION\n");
        printf(" 4. LOCALIDAD\n");
        printf(" 5. CURSO\n");
        printf(" 6. GRUPO\n");
        printf(" 7. TODO\n");
        printf("SELECCIONE UNA OPCION : ");
        flush_in();
        scanf("%d",&opc);
        switch (opc){
            case 1:
                printf("INGRESE NUEVO ID :");
                flush_in();
                scanf("%6[^\n]",al_alum[slc].id_alum);
                break;
            case 2:
                printf("INGRESE NUEVO NOMBRE :");
                flush_in();
                scanf("%20[^\n]",al_alum[slc].nombre_alum);
                break;
            case 3:
                printf("INGRESE NUEVA DIRECCION :");
                flush_in();
                scanf("%30[^\n]",al_alum[slc].direc_alum);
                break;
            case 4:
                printf("INGRESE NUEVA LOCALIDAD :");
                flush_in();
                scanf("%30[^\n]",al_alum[slc].local_alum);
                break;
            case 5:
                printf("INGRESE NUEVO CURSO :");
                flush_in();
                scanf("%50[^\n]",al_alum[slc].curso);
                break;
            case 6:
                printf("INGRESE NUEVO GRUPO :");
                flush_in();
                scanf("%10[^\n]",al_alum[slc].grupo);
                break;
            case 7:
                printf("INGRESE NUEVO ID :");
                flush_in();
                scanf("%6[^\n]",al_alum[slc].id_alum);

                printf("INGRESE NUEVO NOMBRE :");
                flush_in();
                scanf("%20[^\n]",al_alum[slc].nombre_alum);

                printf("INGRESE NUEVA DIRECCION :");
                flush_in();
                scanf("%30[^\n]",al_alum[slc].direc_alum);

                printf("INGRESE NUEVA LOCALIDAD :");
                flush_in();
                scanf("%30[^\n]",al_alum[slc].local_alum);

                printf("INGRESE NUEVO CURSO :");
                flush_in();
                scanf("%50[^\n]",al_alum[slc].curso);

                printf("INGRESE NUEVO GRUPO :");
                flush_in();
                scanf("%10[^\n]",al_alum[slc].grupo);
                break;
            default:
                break;
        }
    }
    if(resp=='n'||resp=='N') {
        printf("Los datos no se han modificado\n");
    }
}

void notas(int elg){
int i,j,k=1,l,temp[2*num_cali],opc=0,aux=0,auy=0,opcf=0,m=0;
    char resp;
    char *fecha, *descr, *nota,*id,*idm;
    for(i=0;i<num_cali;i++){
        if(strcmp(al_cali[i].id_alum,al_alum[elg].id_alum)==0){
            for(j=0;j<num_mate;j++){
                if(strcmp(al_cali[i].id_materia,al_mate[j].id_materia)==0){
                    printf("%d: %s %d\n",k,al_mate[j].nombre_materia,al_cali[i].valor_calif);
                    temp[2*k]=i;
                    temp[(2*k)+1]=j;
                    k++;
                }
            }
        }
    }
    printf("Seleccione una opcion : ");
    flush_in();
    scanf("%d",&opc);
    for(l=1;l<k;l++){
        if(opc==l){
            aux=temp[2*l];
            auy=temp[(2*l)+1];
        }
    }
    //system("clear");
    printf("%s %d\n",al_mate[auy].nombre_materia,al_cali[aux].valor_calif);

    puts("* * * * * * * * * * * * * * * * * *");
    puts("*   1. Modificar                  *");
    puts("*   2. Eliminar                   *");
    puts("*   3. Añadir                     *");
    puts("* * * * * * * * * * * * * * * * * *");

    printf("Seleccione una opcion : ");
    flush_in();
    scanf("%d",&opcf);
    switch (opcf) {
        case 1:
            printf("INTRODUZCA NUEVA CALIFICAION: ");
            flush_in();
            scanf("%d",&al_cali[aux].valor_calif);
            break;
        case 2:
            printf("Se van a a eliminar los siguientes datos: %s-%s-%s-%s-%d\n",
                   al_cali[aux].id_alum,
                   al_cali[aux].id_materia,
                   al_cali[aux].fecha_calif,
                   al_cali[aux].descrip_calif,
                   al_cali[aux].valor_calif);
            printf("Esta seguro de eliminar los datos\n");
            flush_in();
            scanf("%c",&resp);
            if(resp=='s'||resp=='S'){

                for(m=aux;m+1<num_cali;m++){

                    strcpy(al_cali[m].id_alum,al_cali[m+1].id_alum);
                    strcpy(al_cali[m].id_materia,al_cali[m+1].id_materia);
                    strcpy(al_cali[m].fecha_calif,al_cali[m+1].fecha_calif);
                    strcpy(al_cali[m].descrip_calif,al_cali[m+1].descrip_calif);
                    al_cali[m].valor_calif=al_cali[m+1].valor_calif;
                }

                num_cali--;

                al_cali = (calificaciones *) realloc( al_cali, (num_cali+1) * sizeof(calificaciones) );

            }else{

                printf("Los datos no se ha eliminado\n");

            }

            break;
        case 3:
            fecha=(char *) malloc( TAM_FC+1*sizeof(char) );
            descr=(char *) malloc( TAM_DC+1*sizeof(char) );
            nota=(char *) malloc( TAM_VC+1*sizeof(char) );
            id=(char *) malloc( TAM_IA+1*sizeof(char) );
            idm=(char *) malloc( TAM_IM+1*sizeof(char) );

            al_cali = (calificaciones *) realloc( al_cali, (num_cali+1) * sizeof(calificaciones) );


            id = al_cali[aux].id_alum;
            al_cali[num_cali].id_alum = id;


            printf("INGRESE ID MATERIA: ");
            flush_in();
            scanf("%4[^\n]",idm);
            al_cali[num_cali].id_materia=idm;


            printf("INGRESE FECHA: ");
            flush_in();
            scanf("%10[^\n]",fecha);
            al_cali[num_cali].fecha_calif=fecha;

            printf("INGRESE DESCRIPCION: ");
            flush_in();
            scanf("%30[^\n]",descr);
            al_cali[num_cali].descrip_calif = descr;

            printf("INGRESE CALIFICACION :");
            flush_in();
            scanf("%2[^\n]",nota);
            al_cali[num_cali].valor_calif=atoi(nota);

            num_cali++;


            break;
        default:
            break;

    }
}

void asistencia(int elg){
int x=1,temp[num_falt];
char resp=' ';
int opc,aux=0,opcf;
    char *fechf, *hf,*df,*ef,*ida;
    for(int i=0;i<num_falt;i++){
        if(strcmp(al_falt[i].id_alum,al_alum[elg].id_alum)==0){
            for(int j=0;j<num_hora;j++){
                if(strcmp(al_falt[i].hora_falta,al_hora[j].hora_clase)==0 && strcmp(al_alum[elg].grupo,al_hora[j].grupo)==0 ){
                    for(int k=0;k<num_mate;k++){
                        if(strcmp(al_hora[j].id_materia,al_mate[k].id_materia)==0){
                            printf("%d: %s %s %s %s\n",x,al_mate[k].nombre_materia,al_falt[i].fecha_falta,al_falt[i].descrip_falta,al_falt[i].estado_falta);
                            temp[x]=i;
                            x++;
                        }
                    }

                }
            }
        }
    }


    printf("Seleccione una opcion : ");
    flush_in();
    scanf("%d",&opc);
    for(int l=1;l<x;l++){
        if(opc==l){
            aux=temp[l];
        }
    }
    printf("%s %s %s\n",al_falt[aux].fecha_falta,al_falt[aux].descrip_falta,al_falt[aux].estado_falta);

    puts("* * * * * * * * * * * * * * * * * *");
    puts("*   1. Modificar                  *");
    puts("*   2. Eliminar                   *");
    puts("*   3. Añadir                     *");
    puts("* * * * * * * * * * * * * * * * * *");

    printf("Seleccione una opcion : ");
    flush_in();
    scanf("%d",&opcf);

    switch (opcf) {
        case 1:
            printf("Se modificaran las faltas de %s\n",al_alum[elg].nombre_alum);

            printf("INGRESE NUEVA FECHA :");
            flush_in();
            scanf("%10[^\n]",al_falt[aux].fecha_falta);

            printf("INGRESE NUEVA HORA :");
            flush_in();
            scanf("%1[^\n]",al_falt[aux].hora_falta);

            printf("INGRESE NUEVA DESCRPCION :");
            flush_in();
            scanf("%30[^\n]",al_falt[aux].descrip_falta);

            printf("INGRESE NUEVO ESTADO:");
            flush_in();
            scanf("%13[^\n]",al_falt[aux].estado_falta);

            break;
        case 2:
            printf("Se van a a eliminar los siguientes datos: %s-%s-%s-%s-%s\n",
                   al_falt[aux].id_alum,
                   al_falt[aux].fecha_falta,
                   al_falt[aux].estado_falta,
                   al_falt[aux].descrip_falta,
                   al_falt[aux].hora_falta);
            printf("Esta seguro de eliminar los datos\n");
            printf("s/n : ");
            flush_in();
            scanf("%c",&resp);
            if(resp=='s'||resp=='S'){

                for(int m=aux;m+1<num_falt;m++){

                    strcpy(al_falt[m].id_alum,al_falt[m+1].id_alum);
                    strcpy(al_falt[m].fecha_falta,al_falt[m+1].fecha_falta);
                    strcpy(al_falt[m].estado_falta,al_falt[m+1].estado_falta);
                    strcpy(al_falt[m].descrip_falta,al_falt[m+1].descrip_falta);
                    strcpy(al_falt[m].hora_falta,al_falt[m+1].hora_falta);
                }

                num_falt--;

                al_falt = (faltas *) realloc( al_falt, (num_falt+1) * sizeof(faltas) );

            }else{

                printf("Los datos no se ha eliminado\n");

            }

            break;
        case 3:

            fechf=(char *) malloc( TAM_FF+1*sizeof(char) );
            hf=(char *) malloc( TAM_HF+1*sizeof(char) );
            df=(char *) malloc( TAM_DF+1*sizeof(char) );
            ef=(char *) malloc( TAM_EF+1*sizeof(char) );
            ida=(char *) malloc( TAM_IA+1*sizeof(char) );

            al_falt = (faltas *) realloc( al_falt, (num_falt+1) * sizeof(faltas) );

            ida = al_falt[aux].id_alum;
            al_falt[num_falt].id_alum = ida;

            printf("INGRESE FECHA: ");
            flush_in();
            scanf("%10[^\n]",fechf);
            al_falt[num_falt].fecha_falta=fechf;

            printf("INGRESE DESCRIPCION: ");
            flush_in();
            scanf("%30[^\n]",df);
            al_falt[num_falt].descrip_falta = df;

            printf("INGRESE ESTADO: ");
            flush_in();
            scanf("%13[^\n]",ef);
            al_falt[num_falt].estado_falta=ef;

            printf("INGRESE HORA: ");
            flush_in();
            scanf("%1[^\n]",hf);
            al_falt[num_falt].hora_falta=hf;

            num_falt++;
            break;
        default:
            break;
    }
}

void profesor(int ip){

    char hoy[TAM_DCL];
    int temp[num_hora];
    int temp2[num_mate];
    int clase[num_alum];
    int cont,opc=0,grupo=0,alumselec=0,slc=0;

    fdia(hoy);
    cont=horario(temp,temp2,ip,hoy);

    if(cont!=1){

        seleccion_grupo(cont,temp,temp2,&grupo);

        menu_grupo(&opc);

        do{
            switch(opc){

                case 1:
                alumnado:
                    alumselec=listar(grupo,clase);
                    seleccion_alum(alumselec,clase,&slc);
                    switch (menu_alumno()){
                        case 1:
                            ficha(slc);
                            break;
                        case 2:
                            notas(slc);
                            break;
                        case 3:
                            asistencia(slc);
                            break;
                        case 4:
                            goto alumnado;
                        default:
                            break;
                    }
                    break;
                case 2:
                    cont=horario(temp,temp2,ip,hoy);
                    seleccion_grupo(cont,temp,temp2,&grupo);
                    menu_grupo(&opc);
                    break;
                default:
                    break;
            }
        }while(opc!=1);
    }else printf("Hoy no tiene ninguna clase\n");

}