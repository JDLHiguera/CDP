#ifndef RAFA_CARGAR_H
#define RAFA_CARGAR_H
#include "tipos.h"
//numero de elementos contenidos en cada uno de los ficheros
int num_user;
int num_alum;
int num_mate;
int num_cali;
int num_falt;
int num_hora;
int num_matr;
//Vectores de estructuras globales
usuarios        *al_user;
alumnos         *al_alum;
materias        *al_mate;
calificaciones  *al_cali;
faltas          *al_falt;
horarios        *al_hora;
matriculas      *al_matr;
//funcion para cargar los ficheros en las estructuras
void cargar();
//funcion para eliminar la basura de teclado
void flush_in();
#endif //RAFA_CARGAR_H
