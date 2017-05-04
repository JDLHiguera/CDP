#include "guardar.h"

static void guardarUsuario(usuarios *,int );
static void guardarAlumno (alumnos *, int );
static void guardarMateria (materias *, int );
static void guardarCalificacion (calificaciones *, int );
static void guardarFalta (faltas *, int );
static void guardarHorario (horarios * , int );
static void guardarMatriculas (matriculas *, int );

void guardarUsuario(usuarios *alm,int num) {

    FILE *fich;
    int i;

    fich=fopen("usuarios.txt","w+");

    if (fich==NULL) exit(1);

    for (i=0; i<num; i++){
        fprintf(fich,"%s-%s-%s-%s-%s\n",
               alm[i].id_usuario,
               alm[i].nom_usuario,
               alm[i].perfil_usuario,
               alm[i].usuario,
               alm[i].pass);
    }
    fclose(fich);
    puts("Usuarios guardados correctamente");
}

void guardarAlumno (alumnos *alm, int num){

    FILE *fich;
    int i;

    fich=fopen("alumnos.txt","w+");


    if (fich==NULL) exit(1);

        for (i=0; i<num;i++) {
        fprintf(fich,"%s-%s-%s-%s-%s-%s\n",
                alm[i].id_alum,
                alm[i].nombre_alum,
                alm[i].direc_alum,
                alm[i].local_alum,
                alm[i].curso,
                alm[i].grupo);
        }
    fclose(fich);
    puts("Alumnos guardados correctamente");
}

void guardarMateria (materias *alm, int num){

    FILE *fich;
    int i;

    fich=fopen("materias.txt","w+");


    if (fich==NULL) exit(1);

    for (i=0; i<num; i++) {
        fprintf(fich,"%s-%s-%s\n",
                alm[i].id_materia,
                alm[i].nombre_materia,
                alm[i].abrev_materia);

    }
    fclose(fich);
    puts("Materias guardadas correctamente");
}

void guardarCalificacion (calificaciones *alm, int num){

    FILE *fich;
    int i;

    fich=fopen("calificaciones.txt","w+");


    if (fich==NULL)exit(1);


    for (i=0; i<num; i++) {
        fprintf(fich,"%s-%s-%s-%s-%d\n",
                alm[i].fecha_calif,
                alm[i].descrip_calif,
                alm[i].id_materia,
                alm[i].id_alum,
                alm[i].valor_calif);

    }

    fclose(fich);
    puts("Calificaciones guardadas correctamente");
}

void guardarFalta (faltas *alm, int num){

    FILE *fich;
    int i;

    fich=fopen("faltas.txt","w+");


    if (fich==NULL) exit(1);


    for (i=0; i<num; i++) {
        fprintf(fich,"%s-%s-%s-%s-%s\n",
                alm[i].fecha_falta,
                alm[i].hora_falta,
                alm[i].descrip_falta,
                alm[i].estado_falta,
                alm[i].id_alum);

    }

    fclose(fich);
    puts("Faltas guardadas correctamente");

}

void guardarHorario (horarios *alm, int num){

    FILE *fich;
    int i;

    fich=fopen("horarios.txt","w+");


    if (fich==NULL)exit(1);


    for (i=0; i<num; i++) {
        fprintf(fich,"%s-%s-%s-%s-%s\n",
                alm[i].id_profesor,
                alm[i].dia_clase,
                alm[i].hora_clase,
                alm[i].id_materia,
                alm[i].grupo);
    }

    fclose(fich);

    puts("Horarios guardados correctamente");

}

void guardarMatriculas (matriculas *alm, int num){

    FILE *fich;
    int i;

    fich=fopen("matriculas.txt","w+");


    if (fich==NULL) exit(1);

    for (i=0; i<num; i++) {
        fprintf(fich,"%s-%s\n",
                alm[i].id_materia,
                alm[i].id_alum);

    }
    fclose(fich);
    puts("Matriculas guardadas correctamente");
}

void guardarSalir() {
        guardarUsuario(al_user, num_user);
        guardarAlumno(al_alum, num_alum);
        guardarMateria(al_mate, num_mate);
        guardarCalificacion(al_cali, num_cali);
        guardarFalta(al_falt, num_falt);
        guardarHorario(al_hora, num_hora);
        guardarMatriculas(al_matr,num_matr);
        exit(0);

}



