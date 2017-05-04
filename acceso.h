#ifndef RAFA_ACCESO_H
#define RAFA_ACCESO_H
#include "tipos.h"
#include "menu.h"
#include "profesor.h"
#include "administrador.h"
/*Funcion que verfica que el usuario introducido se encuentra en usuarios.txt
 si este se encuentra en la lista verifca la contraseña y si el usuario es administrador o profesor
 llama a las respectivas funciones para mostrar las respectivas opciones del usuario*/
void acceso(int,usuarios *);
#endif //RAFA_ACCESO_H
