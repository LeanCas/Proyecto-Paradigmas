/*
 * Sistema.cpp
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */

#include "Sistema.h"


void Sistema :: crearUsuario(string nombre, string apellido, string paisOrigen, string email, string contrasenia){
	Usuario* nuevoUsuario = new Usuario(nombre, apellido, paisOrigen, email, contrasenia);
	this->usuarios.push_back(nuevoUsuario);
}


