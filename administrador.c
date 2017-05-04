
#include"administrador.h"
#include "menu.h"
//Usuario
static void menuadminusuario();
static void listarUsuarios();
static void modificarUsuarios();
static void anadirUsuario();
//void anadirUsuario();//El tercer parametro sera 0 si accedemos como participante o 1 si accedemos como administrador
static void eliminarUsuario();
//Alumno
static void menuadminalumno();
static void listarAlumnos();
static void modificarAlumnos();
static void anadirAlumno();
static void eliminarAlumno();
static void seleccionado(int );
static void listarMateriaAlumno(int);
static void cambiarMatriculaAlumno(int);
static void eliminarMatriculaAlumno(int);
static void anadirMatriculaAlumno(int);
//Materia
static void menuadminmateria();
static void listarMaterias();
static void modificarMaterias();
static void anadirMateria();
static void eliminarMateria();
//Horario
static void menuadminhorario();
static void anadirHorario();
static void eliminarHorario();
static void modificarHorario();
static void listarHorario();
static void listarProfesor(int []);
static int listarHorarioP(int ,int []);
//Menu usuarios  TERMINADO

void menuadminusuario(){
    int opc=0;
    while(opc!=5){
        puts("* * * * * * * * * * * * * * * * * *");
        puts("*       1. Alta usuario           *");
        puts("*       2. Baja usuario           *");
        puts("*       3. Modificar usuario      *");
        puts("*       4. Listar usuarios        *");
        puts("*       5. Salir                  *");
        puts("* * * * * * * * * * * * * * * * * *");
        printf("Seleccione una opcion : ");
        flush_in();
        scanf("%d",&opc);

        system("clear");

        switch(opc){

            case 1:
                anadirUsuario();

                break;


            case 2:
                eliminarUsuario();

                break;

            case 3:
                modificarUsuarios();
                break;

            case 4:
                listarUsuarios();

                break;

            default:
                break;

        }
    }

}

void listarUsuarios() {

    int i;

    puts("\n-----------------USUARIOS-----------------\n");
    puts("ID-NOMBRE-PERFIL-LOGIN-PASS\n");

    for(i=0;i<num_user;i++){
        printf("%s-%s-%s-%s-%s\n",
               al_user[i].id_usuario,
               al_user[i].nom_usuario,
               al_user[i].perfil_usuario,
               al_user[i].usuario,
               al_user[i].pass);
    }

    puts("------------------------------------------\n");

}

void modificarUsuarios(){

    int i;
    int u=-1;
    char resp=' ';
    char id[3];

    int nModUsuario=0;

    usuarios *modUsuario;

    modUsuario=malloc(sizeof(usuarios));

    puts("MODIFICAR USUARIO");
    puts("-----------------");

    while(u == -1){

        printf("Introduzca el id del usuario que desea modificar: ");
        scanf("%3[^\n]",id);
        printf("\n");

        for(i=0;i<num_user;i++){

            if(strcmp((al_user)[i].id_usuario,id)==0){

                u=i;

            }

        }

        if(u == -1){

            puts("ERROR: El usuario seleccionado no esta registrado");

        }else{

            printf("Informacion actual del usuario seleccionado: %s-%s-%s-%s-%s\n\n",
                   (al_user)[u].id_usuario,
                   (al_user)[u].nom_usuario,
                   (al_user)[u].perfil_usuario,
                   (al_user)[u].usuario,
                   (al_user)[u].pass);

            printf("Introduzca la nueva informacion del usuario respetando el formato establecido(ID-NOMBRE-PERFIL-LOGIN-PASS)\n\n");

            anadirUsuario();

            while(resp!='s' && resp!='n'){

                printf("Confirmar modificar usuario? (s/n)\n");
                flush_in();
                scanf("%c",&resp);

            }

            if(resp=='s'){

                (al_user)[u]=modUsuario[0];

            }else{

                printf("Se ha cancelado la modificacion del usuario\n");

            }

        }

    }


}

void anadirUsuario(){

    char *id, *nom, *per, *user, *pass;
    int n;

    id=(char *) malloc( TAM_ID+1*sizeof(char) );
    nom=(char *) malloc( TAM_NOM+1*sizeof(char) );
    per=(char *) malloc( TAM_PER+1*sizeof(char) );
    user=(char *) malloc( TAM_USER+1*sizeof(char) );
    pass=(char *) malloc( TAM_PASS+1*sizeof(char) );

    al_user = (usuarios *) realloc( al_user, (num_user+1) * sizeof(usuarios) );



    puts("Introduzca el id del usuario (3 cifras maximo):");
    flush_in();
    scanf("%3[^\n]",id);
    (al_user)[num_user].id_usuario=id;

    puts("Introduzca el nombre completo del usuario (20 caracteres maximo):");
    flush_in();
    scanf("%20[^\n]",nom);
    (al_user)[num_user].nom_usuario=nom;


    do{


        puts("Seleccione el perfil del usuario:");
        puts("1) Administrador");
        puts("2) Profesor");
        flush_in();
        scanf("%d",&n);




    }while(n<1 || n>2);

    switch(n){

        case 1:
            per="administrador";
            (al_user)[num_user].perfil_usuario=per;

            break;

        case 2:
            per="profesor";
            (al_user)[num_user].perfil_usuario=per;
            break;


        default:
            puts("ERROR: La opcion introducida no es valida");

    }

    puts("Introduzca el login del usuario (5 caracteres maximo):");
    flush_in();
    scanf("%5[^\n]",user);
    (al_user)[num_user].usuario=user;

    puts("Introduzca la pass del usuario (8 caracteres maximo):");
    flush_in();
    scanf("%8[^\n]",pass);
    (al_user)[num_user].pass=pass;

    (num_user)++;

}

void eliminarUsuario(){

    int i;
    int u=0;
    char resp=' ';
    char id[3];

    puts("ELIMINAR USUARIO");
    puts("----------------");

    printf("Introduzca el id del usuario a eliminar: ");
    scanf("%3[^\n]",id);

    for(i=0;i<(num_user);i++){

        if(strcmp((al_user)[i].id_usuario,id)==0){

            u=i;

        }

    }



    printf("Se va a eliminar el siguiente usuario: %s-%s-%s-%s-%s\n",
           (al_user)[u].id_usuario,
           (al_user)[u].nom_usuario,
           (al_user)[u].perfil_usuario,
           (al_user)[u].usuario,
           (al_user)[u].pass);
    printf("Confirmar eliminar usuario? (s/n)\n");
    flush_in();
    scanf("%c",&resp);



    if(resp=='S' || resp=='s'){

        for(i=u;i+1<(num_user);i++){

            strcpy((al_user)[i].id_usuario,(al_user)[i+1].id_usuario);
            strcpy((al_user)[i].nom_usuario,(al_user)[i+1].nom_usuario);
            strcpy((al_user)[i].perfil_usuario,(al_user)[i+1].perfil_usuario);
            strcpy((al_user)[i].usuario,(al_user)[i+1].usuario);
            strcpy((al_user)[i].pass,(al_user)[i+1].pass);

        }

        (num_user)--;

        al_user=realloc((usuarios *)(al_user),(num_user)*sizeof(usuarios));

    }else{

        printf("Se ha cancelado la eliminacion del usuario\n");

    }

}

//Menu Alumnos (POR TERMINAR)

void menuadminalumno(){

    int opc=0;
    while(opc!=5){
        puts("* * * * * * * * * * * * * * * * * *");
        puts("*       1. Alta alumno            *");
        puts("*       2. Baja alumno            *");
        puts("*       3. Modificar alumno       *");
        puts("*       4. Listar alumnos         *");
        puts("*       5. Salir                  *");
        puts("* * * * * * * * * * * * * * * * * *");
        printf("Seleccione una opcion : ");
        flush_in();
        scanf("%d",&opc);

        system("clear");

        switch(opc){

            case 1:
                anadirAlumno();
                break;


            case 2:
                eliminarAlumno();
                break;

            case 3:
                modificarAlumnos();
                break;

            case 4:
                listarAlumnos();
                break;
            default:
                break;

        }
    }

}

void listarAlumnos() {
    int i, temp[num_alum],opc=0;
    char par=' ';

    puts("\n-----------------ALUMNOS-----------------\n");
    puts("ID-NOMBRE-DIRECCION-LOCALIDAD-CURSO-GRUPO\n");

    for (i = 0; i < num_alum; i++) {
        printf("%d: %s-%s-%s-%s-%s-%s\n",i+1,
               al_alum[i].id_alum,
               al_alum[i].nombre_alum,
               al_alum[i].direc_alum,
               al_alum[i].local_alum,
               al_alum[i].curso,
               al_alum[i].grupo);
        temp[i]=i;
    }

    printf("\n");
    puts("Desea cambiar los parametros de algun alumno? (s/n)");
    flush_in();
    scanf("%c",&par);
    if(par=='S' || par=='s'){


        puts("------------------------------------------\n");
        puts("Que alumno desea seleccionar?");
        scanf("%d",&opc);
        for(int k=0;k<num_alum;k++){
            if((opc-1)==temp[k]){
                seleccionado(temp[k]);
            }
        }

    }
}

void modificarAlumnos() {

    int i;
    int u = -1;
    char id[6];
    int opc;

    puts("MODIFICAR ALUMNO");
    puts("-----------------");

    while (u == -1) {

        printf("Introduzca el id del alumno que desea modificar: ");
        scanf("%6[^\n]", id);
        printf("\n");

        for (i = 0; i < num_alum; i++) {

            if (strcmp((al_alum)[i].id_alum, id) == 0) {

                u = i;

            }

        }

        if (u == -1) {

            puts("ERROR: El alumno seleccionado no esta registrado");

        } else {

            printf("Informacion actual del usuario seleccionado: %s-%s-%s-%s-%s-%s\n\n",
                   (al_alum)[u].id_alum,
                   (al_alum)[u].nombre_alum,
                   (al_alum)[u].direc_alum,
                   (al_alum)[u].local_alum,
                   (al_alum)[u].curso,
                   (al_alum)[u].grupo);



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
                    scanf("%6[^\n]",al_alum[u].id_alum);
                    break;
                case 2:
                    printf("INGRESE NUEVO NOMBRE :");
                    flush_in();
                    scanf("%20[^\n]",al_alum[u].nombre_alum);
                    break;
                case 3:
                    printf("INGRESE NUEVA DIRECCION :");
                    flush_in();
                    scanf("%30[^\n]",al_alum[u].direc_alum);
                    break;
                case 4:
                    printf("INGRESE NUEVA LOCALIDAD :");
                    flush_in();
                    scanf("%30[^\n]",al_alum[u].local_alum);
                    break;
                case 5:
                    printf("INGRESE NUEVO CURSO :");
                    flush_in();
                    scanf("%50[^\n]",al_alum[u].curso);
                    break;
                case 6:
                    printf("INGRESE NUEVO GRUPO :");
                    flush_in();
                    scanf("%10[^\n]",al_alum[u].grupo);
                    break;
                case 7:
                    printf("INGRESE NUEVO ID :");
                    flush_in();
                    scanf("%6[^\n]",al_alum[u].id_alum);

                    printf("INGRESE NUEVO NOMBRE :");
                    flush_in();
                    scanf("%20[^\n]",al_alum[u].nombre_alum);

                    printf("INGRESE NUEVA DIRECCION :");
                    flush_in();
                    scanf("%30[^\n]",al_alum[u].direc_alum);

                    printf("INGRESE NUEVA LOCALIDAD :");
                    flush_in();
                    scanf("%30[^\n]",al_alum[u].local_alum);

                    printf("INGRESE NUEVO CURSO :");
                    flush_in();
                    scanf("%50[^\n]",al_alum[u].curso);

                    printf("INGRESE NUEVO GRUPO :");
                    flush_in();
                    scanf("%10[^\n]",al_alum[u].grupo);
                    break;
                default:
                    break;
            }
        }



    }


}

void seleccionado(int slc) {

    int opc=0;
    while(opc!=5){
        puts("* * * * * * * * * * * * * * * * * *");
        puts("*     1. Lista de materias        *");
        puts("*     2. Cambio de matricula      *");
        puts("*     3. Nueva matricula          *");
        puts("*     4. Eliminar matricula       *");
        puts("*     5. Salir                    *");
        puts("* * * * * * * * * * * * * * * * * *");
        printf("Seleccione una opcion : ");
        flush_in();
        scanf("%d",&opc);

        system("clear");

        switch(opc){

            case 1:

                listarMateriaAlumno(slc);
                break;


            case 2:
                cambiarMatriculaAlumno(slc);
                break;

            case 3:
                anadirMatriculaAlumno(slc);
                break;

            case 4:
                eliminarMatriculaAlumno(slc);
                break;
            default:
                break;

        }
    }



}

void anadirAlumno(){
    char *id, *nom, *dir,*la,*cs,*gp;

    id=(char *) malloc( TAM_IA+1*sizeof(char) );
    nom=(char *) malloc( TAM_NOMA+1*sizeof(char) );
    dir=(char *) malloc( TAM_DIREC+1*sizeof(char) );
    la=(char *) malloc( TAM_LA+1*sizeof(char) );
    cs=(char *) malloc( TAM_CS+1*sizeof(char) );
    gp=(char *) malloc( TAM_GP+1*sizeof(char) );

    al_alum = (alumnos *) realloc( al_alum, (num_alum+1) * sizeof(alumnos) );


    puts("Introduzca el id del alumno (6 cifras maximo):");
    flush_in();
    scanf("%6[^\n]",id);
    (al_alum)[num_alum].id_alum=id;

    puts("Introduzca el nombre de alumno (20 caracteres maximo):");
    flush_in();
    scanf("%20[^\n]",nom);
    (al_alum)[num_alum].nombre_alum=nom;

    puts("Introduzca la direccion del alumno (30 caracteres maximo):");
    flush_in();
    scanf("%30[^\n]",dir);
    (al_alum)[num_alum].direc_alum=dir;

    puts("Introduzca la localidad del alumno (30 caracteres maximo):");
    flush_in();
    scanf("%30[^\n]",la);
    (al_alum)[num_alum].local_alum=la;

    puts("Introduzca el curso del alumno (50 caracteres maximo):");
    flush_in();
    scanf("%50[^\n]",cs);
    (al_alum)[num_alum].curso=cs;

    puts("Introduzca el grupo del alumno (10 caracteres maximo):");
    flush_in();
    scanf("%10[^\n]",gp);
    (al_alum)[num_alum].grupo=gp;

    (num_alum)++;

}

void eliminarAlumno(){

    int i;
    int u;
    char resp=' ';
    char id[3];

    puts("ELIMINAR ALUMNO");
    puts("----------------");

    printf("Introduzca el id del alumno a eliminar: ");
    scanf("%6s",id);

    for(i=0;i<(num_alum);i++){

        if(strcmp((al_alum)[i].id_alum,id)==0){

            u=i;

        }

    }

    //while(resp!='s' && resp!='n'){

    printf("Se va a eliminar el siguiente alumno: %s-%s-%s-%s-%s-%s\n",
           (al_alum)[u].id_alum,
           (al_alum)[u].nombre_alum,
           (al_alum)[u].direc_alum,
           (al_alum)[u].local_alum,
           (al_alum)[u].curso,
           (al_alum)[u].grupo);



    printf("Confirmar eliminar alumno? (s/n)\n");
    flush_in();
    scanf("%c",&resp);

    //}

    if(resp=='s' || resp=='S'){

        for(i=u;i+1<(num_alum);i++){

            strcpy((al_alum)[i].id_alum,(al_alum)[i+1].id_alum);
            strcpy((al_alum)[i].nombre_alum,(al_alum)[i+1].nombre_alum);
            strcpy((al_alum)[i].direc_alum,(al_alum)[i+1].direc_alum);
            strcpy((al_alum)[i].local_alum,(al_alum)[i+1].local_alum);
            strcpy((al_alum)[i].curso,(al_alum)[i+1].curso);
            strcpy((al_alum)[i].grupo,(al_alum)[i+1].grupo);

        }

        (num_alum)--;

        al_alum= (alumnos *) realloc((al_alum),(num_alum)*sizeof(alumnos));

    }else{

        printf("Se ha cancelado la eliminacion del alumno\n");

    }

}

void listarMateriaAlumno(int slc){
    for(int i=0;i<num_matr;i++){
        if(strcmp(al_alum[slc].id_alum,al_matr[i].id_alum)==0){
            for(int j=0;j<num_mate;j++){
                if(strcmp(al_matr[i].id_materia,al_mate[j].id_materia)==0){
                    printf("%s cursa %s\n",al_alum[slc].nombre_alum,al_mate[j].nombre_materia);
                }
            }
        }
    }

}

void cambiarMatriculaAlumno(int slc){
    int aux=0;
    for(int i=0;i<num_matr;i++) {
        if (strcmp(al_alum[slc].id_alum, al_matr[i].id_alum) == 0) {
            aux=i;
        }
    }
    printf("INGRESE NUEVA MATERIA :");
    flush_in();
    scanf("%4[^\n]",al_matr[aux].id_materia);


}

void eliminarMatriculaAlumno(int slc){
    int aux=0;
    char resp=' ';
    for(int i=0;i<num_matr;i++) {
        if (strcmp(al_alum[slc].id_alum, al_matr[i].id_alum) == 0) {
            aux=i;
        }
    }
    printf("Se van a a eliminar los siguientes datos: %s-%s\n",
           al_matr[aux].id_materia,
           al_matr[aux].id_alum);
    printf("Esta seguro de eliminar los datos\n");
    printf("SI 's' NO 'n'\n");
    flush_in();
    scanf("%c",&resp);
    if(resp=='s'||resp=='S'){

        for(int m=aux;m+1<num_matr;m++){

            strcpy(al_matr[m].id_alum,al_matr[m+1].id_alum);
            strcpy(al_matr[m].id_materia,al_matr[m+1].id_materia);

        }

        num_matr--;

        al_matr = (matriculas *) realloc( al_matr, (num_matr+1) * sizeof(matriculas) );

    }else{

        printf("Los datos no se ha eliminado\n");

    }

}

void anadirMatriculaAlumno(int slc){
    int aux=0;
    char *idm,*ida;
    for(int i=0;i<num_matr;i++) {
        if (strcmp(al_alum[slc].id_alum, al_matr[i].id_alum) == 0) {
            aux=i;
        }
    }
    idm=(char *) malloc( TAM_IM+1*sizeof(char) );
    ida=(char *) malloc( TAM_IA+1*sizeof(char) );
    al_matr = (matriculas *) realloc( al_matr, (num_matr+1) * sizeof(matriculas) );

    ida=al_matr[aux].id_alum;
    al_matr[num_matr].id_alum=ida;

    printf("Introdusca id materia: ");
    flush_in();
    scanf("%4[^\n]",idm);
    al_matr[num_matr].id_materia=idm;
    num_matr++;
}

//Menu Materias   TERMINADO

void menuadminmateria(){
    int opc=0;
    while(opc!=5){
        puts("* * * * * * * * * * * * * * * * * *");
        puts("*       1. Alta materia           *");
        puts("*       2. Baja materia           *");
        puts("*       3. Modificar materia      *");
        puts("*       4. Listar materias        *");
        puts("*       5. Salir                  *");
        puts("* * * * * * * * * * * * * * * * * *");
        printf("Seleccione una opcion : ");
        flush_in();
        scanf("%d",&opc);

        system("clear");

        switch(opc){

            case 1:
                anadirMateria();
                system("pause");
                break;


            case 2:
                eliminarMateria();
                system("pause");
                break;

            case 3:
                modificarMaterias();
                break;

            case 4:
                listarMaterias();
                system("pause");
                break;

            case 5:
                break;

        }
    }
}

void listarMaterias(){
    int i;

    puts("\n-----------------MATERIAS-----------------\n");
    puts("ID-NOMBRE-ABREVIATURA\n");

    for(i=0;i<num_mate;i++){
        printf("%s-%s-%s\n",
               al_mate[i].id_materia,
               al_mate[i].nombre_materia,
               al_mate[i].abrev_materia);

    }

    puts("------------------------------------------\n");



}

void modificarMaterias(){

    int i;
    int u=-1;
    char id[3];
    int opc;


    puts("MODIFICAR MATERIA");
    puts("-----------------");

    while(u == -1){

        printf("Introduzca el id de la materia que desea modificar: ");
        scanf("%4[^\n]",id);
        printf("\n");

        for(i=0;i<num_mate;i++){

            if(strcmp((al_mate)[i].id_materia,id)==0){

                u=i;

            }

        }

        if(u == -1){

            puts("ERROR: La materia seleccionada no esta registrada");

        }else{

            printf("Informacion actual de la usuario materia: %s-%s-%s\n\n",
                   (al_mate)[u].id_materia,
                   (al_mate)[u].nombre_materia,
                   (al_mate)[u].abrev_materia);

            printf("QUE DESEA CAMBIAR\n");
            printf(" 1. ID\n");
            printf(" 2. NOMBRE\n");
            printf(" 3. ABREVIATURA\n");
            printf(" 4. TODO\n");
            printf("SELECCIONE UNA OPCION : ");
            flush_in();
            scanf("%d",&opc);
            switch (opc){
                case 1:
                    printf("INGRESE NUEVO ID :");
                    flush_in();
                    scanf("%4[^\n]",al_mate[u].id_materia);
                    break;
                case 2:
                    printf("INGRESE NUEVO NOMBRE :");
                    flush_in();
                    scanf("%50[^\n]",al_mate[u].nombre_materia);
                    break;
                case 3:
                    printf("INGRESE NUEVA ABREVIATURA :");
                    flush_in();
                    scanf("%3[^\n]",al_mate[u].abrev_materia);
                    break;
                case 4:
                    printf("INGRESE NUEVO ID :");
                    flush_in();
                    scanf("%4[^\n]",al_mate[u].id_materia);

                    printf("INGRESE NUEVO NOMBRE :");
                    flush_in();
                    scanf("%50[^\n]",al_mate[u].nombre_materia);

                    printf("INGRESE NUEVA ABREVIATURA :");
                    flush_in();
                    scanf("%3[^\n]",al_mate[u].abrev_materia);

            }
        }


    }

}

void anadirMateria(){
    char *id, *nom, *abr;
    id=(char *) malloc( TAM_IM+1*sizeof(char) );
    nom=(char *) malloc( TAM_NOMM+1*sizeof(char) );
    abr=(char *) malloc( TAM_ABR+1*sizeof(char) );

    al_mate=(materias *) realloc((al_mate),((num_mate)+1)*sizeof(materias));

    puts("Introduzca el id de la materia (4 cifras maximo):");

    flush_in();
    scanf("%4[^\n]",id);
    (al_mate)[num_mate].id_materia=id;



    puts("Introduzca el nombre completo de la materia (50 caracteres maximo):");
    flush_in();
    scanf("%50[^\n]",nom);
    (al_mate)[num_mate].nombre_materia=nom;



    puts("Introduzca la abreviacion de la materia (3 caracteres maximo):");
    flush_in();
    scanf("%3[^\n]",abr);
    (al_mate)[num_mate].abrev_materia=abr;


    (num_mate)++;

}

void eliminarMateria(){


    int i;
    int u;
    char resp=' ';
    char id[3];

    puts("ELIMINAR MATERIA");
    puts("----------------");

    printf("Introduzca el id de la materia a eliminar: ");
    scanf("%4[^\n]",id);

    for(i=0;i<(num_mate);i++){

        if(strcmp((al_mate)[i].id_materia,id)==0){

            u=i;

        }

    }

    while(resp!='s' && resp!='n'){

        printf("Se va a eliminar el siguiente usuario: %s-%s-%s\n",
               (al_mate)[u].id_materia,
               (al_mate)[u].nombre_materia,
               (al_mate)[u].abrev_materia);

        printf("Confirmar eliminar materia? (s/n)\n");
        flush_in();
        scanf("%c",&resp);

    }

    if(resp=='s'){

        for(i=u;i+1<(num_mate);i++){

            strcpy((al_mate)[i].id_materia,(al_mate)[i+1].id_materia);
            strcpy((al_mate)[i].nombre_materia,(al_mate)[i+1].nombre_materia);
            strcpy((al_mate)[i].abrev_materia,(al_mate)[i+1].abrev_materia);

        }

        (num_mate)--;

        al_mate=(materias *) realloc ((al_mate),(num_mate+1)*sizeof(materias));

    }else{

        printf("Se ha cancelado la eliminacion de la materia\n");

    }

}

//Menu Horarios   TERMINADO

void menuadminhorario(){

    int opc=0;
    while(opc!=5){
        puts("* * * * * * * * * * * * * * * * * *");
        puts("*      1. Añadir horario          *");
        puts("*      2. Eliminar horario        *");
        puts("*      3. Modificar horario       *");
        puts("*      4. Listar horarios         *");
        puts("*      5. Salir                   *");
        puts("* * * * * * * * * * * * * * * * * *");
        printf("Seleccione una opcion : ");
        flush_in();
        scanf("%d",&opc);

        system("clear");

        switch(opc){

            case 1:
                anadirHorario();
                break;


            case 2:
                eliminarHorario();
                break;

            case 3:
                modificarHorario();
                break;

            case 4:
                listarHorario();
                break;
            default:
                break;

        }
    }



}

void listarProfesor(int temp[]) {

    int j=1;

    printf("-----------------PROFESORES-----------------\n");

    for(int i=0;i<num_user;i++){
        if(strcmp(al_user[i].perfil_usuario,"profesor")==0){
        printf("%d : %s\n",j, al_user[i].nom_usuario);
            temp[j]=i;
            j++;
        }
    }

    printf("------------------------------------------\n");

}

int listarHorarioP(int elg,int temp[]){
    int i,j,k=1;
    printf("\n");
    for(i=0;i<num_hora;i++){
        if (strcmp(al_hora[i].id_profesor, al_user[elg].id_usuario) == 0){
            for(j=0;j<num_mate;j++){
                if(strcmp(al_mate[j].id_materia,al_hora[i].id_materia)==0){
                    temp[2*k]=i;
                    temp[(2*k)+1]=j;
                    printf("%i: Imparte %s en %s  a %s hora\n",k,al_mate[j].nombre_materia,al_hora[i].grupo,al_hora[i].hora_clase);
                    k++;
                }
            }
        }
    }
    return k;

}

void listarHorario(){
    int temp[num_user],hoa[2*num_user];
    int opc,aux=0;
    listarProfesor(temp);
    printf("Selecione un profesor: ");
    flush_in();
    scanf("%d",&opc);
    for(int i=1;i<num_user;i++){
        if(opc==i){
            aux=temp[i];
        }
    }
    listarHorarioP(aux,hoa);

}

void modificarHorario(){
    int temp[num_user],hoa[2*num_user];
    int opc,aux=0,auy=0,dlt,opcs;
    listarProfesor(temp);
    printf("Selecione un profesor : ");
    flush_in();
    scanf("%d",&opc);
    for(int i=1;i<num_user;i++){
        if(opc==i){
            aux=temp[i];
        }
    }
    dlt=listarHorarioP(aux,hoa);
    printf("Que Horario Desea Modificar : ");
    flush_in();
    scanf("%d",&opc);
    for(int i=1;i<dlt;i++){
        if(opc==i){
            auy=hoa[2*i];
            //auz=hoa[(2*i)+1];
        }
    }
    puts("* * * * * * * * * * * * * * * * * *");
    puts("*      1. ID PROFESOR             *");
    puts("*      2. ID MATERIA              *");
    puts("*      3. DIA CLASE               *");
    puts("*      4. HORA CLASE              *");
    puts("*      5. GRUPO                   *");
    puts("* * * * * * * * * * * * * * * * * *");
    printf("Seleccione una opcion : ");
    flush_in();
    scanf("%d",&opcs);
    switch (opcs){
        case 1:
            printf("INGRESE NUEVO ID :");
            flush_in();
            scanf("%3[^\n]",al_hora[auy].id_profesor);

            break;
        case 2:
            printf("INGRESE NUEVO ID :");
            flush_in();
            scanf("%4[^\n]",al_hora[auy].id_materia);
            break;
        case 3:
            printf("INGRESE NUEVO DIA :");
            flush_in();
            scanf("%1[^\n]",al_hora[auy].dia_clase);
            break;
        case 4:
            printf("INGRESE NUEVA HORA:");
            flush_in();
            scanf("%1[^\n]",al_hora[auy].hora_clase);
            break;
        case 5:
            printf("INGRESE NUEVO GRUPO :");
            flush_in();
            scanf("%20[^\n]",al_alum[auy].grupo);
            break;
        default:
            break;
    }




}

void anadirHorario(){
    int temp[num_user];
    int opc,aux=0;
    char *dia, *hora, *gru,*idp,*idm;
    listarProfesor(temp);
    printf("Selecione un profesor : ");
    flush_in();
    scanf("%d",&opc);
    for(int i=1;i<num_user;i++){
        if(opc==i){
            aux=temp[i];
        }
    }
    al_hora = (horarios *) realloc( al_hora, (num_hora+1) * sizeof(horarios) );

    dia=(char *) malloc( TAM_DCL+1*sizeof(char) );
    hora=(char *) malloc( TAM_HC+1*sizeof(char) );
    gru=(char *) malloc( TAM_HG+1*sizeof(char) );
    idp=(char *) malloc( TAM_ID+1*sizeof(char) );
    idm=(char *) malloc( TAM_IM+1*sizeof(char) );

    idp=al_user[aux].id_usuario;
    al_hora[num_hora].id_profesor=idp;

    printf("Introdusca dia en numeros: ");
    flush_in();
    scanf("%1[^\n]",dia);
    al_hora[num_hora].dia_clase=dia;

    printf("Introdusca hora de clase: ");
    flush_in();
    scanf("%5[^\n]",hora);
    al_hora[num_hora].hora_clase=hora;

    printf("Introdusca grupo: ");
    flush_in();
    scanf("%10[^\n]",gru);
    al_hora[num_hora].grupo=gru;

    printf("Introdusca id materia: ");
    flush_in();
    scanf("%4[^\n]",idm);
    al_hora[num_hora].id_materia=idm;
    al_hora++;

}

void eliminarHorario(){

    int temp[num_user],hoa[2*num_user];
    int opc,aux=0,auy=0,dlt;
    char resp=' ';
    listarProfesor(temp);
    printf("Selecione un profesor : ");
    flush_in();
    scanf("%d",&opc);
    for(int i=1;i<num_user;i++){
        if(opc==i){
            aux=temp[i];
        }
    }
    dlt=listarHorarioP(aux,hoa);
    printf("Que Horario Desea Eliminar : ");
    flush_in();
    scanf("%d",&opc);
    for(int i=1;i<dlt;i++){
        if(opc==i){
            auy=hoa[2*i];
            //auz=hoa[(2*i)+1];
        }
    }
    printf("Se van a a eliminar los siguientes datos: %s-%s-%s-%s-%s\n",
           al_hora[auy].id_profesor,
           al_hora[auy].id_materia,
           al_hora[auy].dia_clase,
           al_hora[auy].hora_clase,
           al_hora[auy].grupo);
    printf("Esta seguro de eliminar los datos\n");
    printf("SI 's' NO 'n'\n");
    flush_in();
    scanf("%c",&resp);
    if(resp=='s'||resp=='S'){

        for(int m=auy;m+1<num_hora;m++){

            strcpy(al_hora[m].id_profesor,al_hora[m+1].id_profesor);
            strcpy(al_hora[m].id_materia,al_hora[m+1].id_materia);
            strcpy(al_hora[m].dia_clase,al_hora[m+1].dia_clase);
            strcpy(al_hora[m].hora_clase,al_hora[m+1].hora_clase);
            strcpy(al_hora[m].grupo,al_hora[m+1].grupo);
        }

        num_hora--;

        al_hora = (horarios *) realloc( al_hora, (num_hora+1) * sizeof(horarios) );

    }else{

        printf("Los datos no se ha eliminado\n");

    }


}

void administrador(){
    int opc=0;
    while(opc!=5){
        puts("* * * * * * * * * * * * * * * * * *");
        puts("*         1. Usuarios             *");
        puts("*         2. Alumnos              *");
        puts("*         3. Materias             *");
        puts("*         4. Horarios             *");
        puts("*         5. Salir                *");
        puts("* * * * * * * * * * * * * * * * * *");
        printf("Seleccione una opcion : ");
        flush_in();
        scanf("%d",&opc);

        system("clear");

        switch(opc){

            case 1:
                menuadminusuario();
                break;


            case 2:
                menuadminalumno();
                break;

            case 3:
                menuadminmateria();
                break;

            case 4:
                menuadminhorario();
                break;

            default:
                break;



        }
    }


}