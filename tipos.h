#ifndef RAFA_TIPOS_H
#define RAFA_TIPOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_ID 3
#define TAM_NOM 20
#define TAM_PER 13
#define TAM_PASS 8
#define TAM_USER 5

typedef struct{
    char *id_usuario;
    char *nom_usuario;
    char *perfil_usuario;   //Deberá ser: administrador ;profesor
    char *usuario;     // Nombre de usuario
    char *pass;
}usuarios;

#define TAM_IA 6
#define TAM_NOMA 20
#define TAM_DIREC 30
#define TAM_LA 30
#define TAM_CS 50
#define TAM_GP 10

typedef struct{     //Estructura de alumnos.txt
    char *id_alum;
    char *nombre_alum;
    char *direc_alum;
    char *local_alum;
    char *curso;
    char *grupo;
}alumnos;

#define TAM_IM 4
#define TAM_NOMM 50
#define TAM_ABR 3

typedef struct{   //Estructura de materias.txt
    char *id_materia;
    char *nombre_materia;
    char *abrev_materia;
}materias;

#define TAM_FC 10
#define TAM_DC 30
#define TAM_VC 2


typedef struct{   //Estructura de calificaciones.txt
    char *id_alum;
    char *id_materia;
    char *fecha_calif;  //Formato fecha -> XX/XX/XXXX (10 caracteres)
    char *descrip_calif;
    int  valor_calif;  //Valor obtenido entre 0 (00) y 10 (10)
}calificaciones;

#define TAM_FF 10
#define TAM_HF 1
#define TAM_DF 30
#define TAM_EF 13

typedef struct{   //Estructura de faltas.txt
    char *id_alum;
    char *fecha_falta;  //Formato fecha -> XX/XX/XXXX (10 caracteres)
    char *hora_falta;
    char *descrip_falta;
    char *estado_falta;  //Injustificada(13), Justificada(11) o Retraso(7)
}faltas;

#define TAM_DCL 15
#define TAM_HC 5
#define TAM_HG 20

typedef struct{
    char *dia_clase;
    char *hora_clase;
    char *grupo;
    char *id_profesor;
    char *id_materia;

}horarios;

typedef struct{
    char *id_materia;
    char *id_alum;
}matriculas;



#endif //RAFA_TIPOS_H

