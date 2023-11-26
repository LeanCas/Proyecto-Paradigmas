/*
 * Usuario.cpp
 *
 *  Created on: 26 nov. 2023
 *      Author: sofia
 */

using namespace std;
#include "Usuario.h"

int Usuario::autonumerico = 0;

Usuario::Usuario(string nombre, string apellido, string paisOrigen, string email, string contrasenia): id(++autonumerico), nombre(nombre), apellido(apellido), paisOrigen(paisOrigen),email(email), contrasenia(contrasenia){}

string Usuario::getNombre(){return nombre;}
int Usuario::getId(){return id;}
