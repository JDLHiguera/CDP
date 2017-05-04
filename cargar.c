#include "cargar.h"

//funcion privada para cargar usuarios.txt en memoria
static usuarios        *fichero_user( int * );

//funcion privada para cargar alumnos.txt en memoria
static alumnos         *fichero_alum( int * );

//funcion privada para cargar umaterias.txt en memoria
static materias        *fichero_mate( int * );

//funcion privada para cargar calificaciones.txt en memoria
static calificaciones  *fichero_cali( int * );

//funcion privada para cargar faltas.txt en memoria
static faltas          *fichero_falt( int * );

//funcion privada para cargar horarios.txt en memoria
static horarios        *fichero_hora( int * );

//funcion privada para cargar matriculas.txt en memoria
static matriculas      *fichero_matr( int * );

void cargar(){
    al_user = fichero_user( &num_user );
    al_alum = fichero_alum( &num_alum );
    al_mate = fichero_mate( &num_mate );
    al_cali = fichero_cali( &num_cali );
    al_falt = fichero_falt( &num_falt );
    al_hora = fichero_hora( &num_hora );
    al_matr = fichero_matr( &num_matr );
}

void flush_in() {
    int ch;

    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

usuarios *fichero_user( int *num ) {
    usuarios *alm=NULL;
    (*num)=0;
    char *id, *nom, *per,*user,*pass;

    FILE *fich;
    fich = fopen("usuarios.txt", "r");
    if (fich==NULL) exit(1);

    while ( !feof(fich) ) {
        id=(char *) malloc( TAM_ID+1*sizeof(char) );
        nom=(char *) malloc( TAM_NOM+1*sizeof(char) );
        per=(char *) malloc( TAM_PER+1*sizeof(char) );
        user=(char *) malloc( TAM_USER+1*sizeof(char) );
        pass=(char *) malloc( TAM_PASS+1*sizeof(char) );


        fscanf(fich, "%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", id, nom, per, user ,pass);

        if (! *num) alm = (usuarios *) malloc( (*num+1) * sizeof(usuarios) );
        else alm = (usuarios *) realloc( alm, (*num+1) * sizeof(usuarios) );
        alm[*num].id_usuario = id;
        alm[*num].nom_usuario = nom;
        alm[*num].perfil_usuario = per;
        alm[*num].usuario = user;
        alm[*num].pass = pass;

        (*num)++;
    }

    fclose(fich);
    return alm;
}

alumnos *fichero_alum( int *num ) {
    alumnos *alm=NULL;
    (*num)=0;
    char *id, *nom, *dir,*la,*cs,*gp;

    FILE *fich;
    fich = fopen("alumnos.txt", "r");
    if (fich==NULL) exit(1);

    while ( !feof(fich) ) {
        id=(char *) malloc( TAM_IA+1*sizeof(char) );
        nom=(char *) malloc( TAM_NOMA+1*sizeof(char) );
        dir=(char *) malloc( TAM_DIREC+1*sizeof(char) );
        la=(char *) malloc( TAM_LA+1*sizeof(char) );
        cs=(char *) malloc( TAM_CS+1*sizeof(char) );
        gp=(char *) malloc( TAM_GP+1*sizeof(char) );



        fscanf(fich, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", id, nom,dir,la,cs,gp);

        if (! *num) alm = (alumnos *) malloc( (*num+1) * sizeof(alumnos) );
        else alm = (alumnos *) realloc( alm, (*num+1) * sizeof(alumnos) );
        alm[*num].id_alum = id;
        alm[*num].nombre_alum = nom;
        alm[*num].direc_alum = dir;
        alm[*num].local_alum = la;
        alm[*num].curso = cs;
        alm[*num].grupo = gp;

        (*num)++;
    }

    fclose(fich);
    return alm;
}

materias  *fichero_mate( int *num ){
    materias *alm=NULL;
    (*num)=0;
    char *id, *nom, *abr;

    FILE *fich;
    fich = fopen("materias.txt", "r");
    if (fich==NULL) exit(1);

    while ( !feof(fich) ) {
        id=(char *) malloc( TAM_IM+1*sizeof(char) );
        nom=(char *) malloc( TAM_NOMM+1*sizeof(char) );
        abr=(char *) malloc( TAM_ABR+1*sizeof(char) );




        fscanf(fich, "%[^-]-%[^-]-%[^\n]\n", id, nom, abr); // formato para que admita espacios

        if (! *num) alm = (materias *) malloc( (*num+1) * sizeof(materias) );
        else alm = (materias *) realloc( alm, (*num+1) * sizeof(materias) );

        alm[*num].id_materia = id;
        alm[*num].nombre_materia = nom;
        alm[*num].abrev_materia = abr;


        (*num)++;
    }

    fclose(fich);
    return alm;
}

calificaciones  *fichero_cali( int *num ){
    calificaciones *alm=NULL;
    (*num)=0;
    char *fecha, *descr, *nota,*id,*idm;

    FILE *fich;
    fich = fopen("calificaciones.txt", "r");
    if (fich==NULL) exit(1);

    while ( !feof(fich) ) {
        fecha=(char *) malloc( TAM_FC+1*sizeof(char) );
        descr=(char *) malloc( TAM_DC+1*sizeof(char) );
        nota=(char *) malloc( TAM_VC+1*sizeof(char) );
        id=(char *) malloc( TAM_IA+1*sizeof(char) );
        idm=(char *) malloc( TAM_IM+1*sizeof(char) );




        fscanf(fich, "%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", fecha, descr, idm, id, nota); // formato para que admita espacios

        if (! *num) alm = (calificaciones *) malloc( (*num+1) * sizeof(calificaciones) );
        else alm = (calificaciones *) realloc( alm, (*num+1) * sizeof(calificaciones) );

        alm[*num].fecha_calif = fecha;
        alm[*num].descrip_calif = descr;
        alm[*num].id_materia = idm;
        alm[*num].id_alum = id;
        alm[*num].valor_calif = atoi(nota);

        (*num)++;
    }

    fclose(fich);
    return alm;
}

faltas  *fichero_falt( int *num ){
    faltas *alm=NULL;
    (*num)=0;
    char *fechf, *hf,*df,*ef,*ida;

    FILE *fich;
    fich = fopen("faltas.txt", "r");
    if (fich==NULL) exit(1);

    while ( !feof(fich) ) {
        fechf=(char *) malloc( TAM_FF+1*sizeof(char) );
        hf=(char *) malloc( TAM_HF+1*sizeof(char) );
        df=(char *) malloc( TAM_DF+1*sizeof(char) );
        ef=(char *) malloc( TAM_EF+1*sizeof(char) );
        ida=(char *) malloc( TAM_IA+1*sizeof(char) );


        fscanf(fich, "%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", fechf,hf,df,ef,ida); // formato para que admita espacios

        if (! *num) alm = (faltas *) malloc( (*num+1) * sizeof(faltas) );
        else alm = (faltas *) realloc( alm, (*num+1) * sizeof(faltas) );

        alm[*num].fecha_falta = fechf;
        alm[*num].hora_falta = hf;
        alm[*num].descrip_falta = df;
        alm[*num].estado_falta = ef;
        alm[*num].id_alum = ida;




        (*num)++;
    }

    fclose(fich);
    return alm;
}

horarios  *fichero_hora( int *num ){
    horarios *alm=NULL;
    (*num)=0;
    char *dia, *hora, *gru,*idp,*idm;

    FILE *fich;
    fich = fopen("horarios.txt", "r");
    if (fich==NULL) exit(1);

    while ( !feof(fich) ) {
        dia=(char *) malloc( TAM_DCL+1*sizeof(char) );
        hora=(char *) malloc( TAM_HC+1*sizeof(char) );
        gru=(char *) malloc( TAM_HG+1*sizeof(char) );
        idp=(char *) malloc( TAM_ID+1*sizeof(char) );
        idm=(char *) malloc( TAM_IM+1*sizeof(char) );

        fscanf(fich, "%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", idp,dia, hora,idm, gru); // formato para que admita espacios

        if (! *num) alm = (horarios *) malloc( (*num+1) * sizeof(horarios) );
        else alm = (horarios *) realloc( alm, (*num+1) * sizeof(horarios) );

        alm[*num].dia_clase = dia;
        alm[*num].hora_clase = hora;
        alm[*num].grupo = gru;
        alm[*num].id_profesor = idp;
        alm[*num].id_materia = idm;

        (*num)++;
    }

    fclose(fich);
    return alm;
}

matriculas  *fichero_matr( int *num ){
    matriculas *alm=NULL;
    (*num)=0;
    char *idm,*ida;

    FILE *fich;
    fich = fopen("matriculas.txt", "r");
    if (fich==NULL) exit(1);

    while ( !feof(fich) ) {
        idm=(char *) malloc( TAM_IM+1*sizeof(char) );
        ida=(char *) malloc( TAM_IA+1*sizeof(char) );





        fscanf(fich, "%[^-]-%[^\n]\n", idm,ida); // formato para que admita espacios

        if (! *num) alm = (matriculas *) malloc( (*num+1) * sizeof(matriculas) );
        else alm = (matriculas *) realloc( alm, (*num+1) * sizeof(matriculas) );

        alm[*num].id_materia = idm;
        alm[*num].id_alum = ida;



        (*num)++;
    }

    fclose(fich);
    return alm;
}
