/*
 * Publicacion.h
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */

#ifndef PUBLICACION_H_
#define PUBLICACION_H_
#include <iostream>
#include "Fecha.h"

using namespace std;

class Usuario;

class Publicacion {
	static int autonumerico;

protected:
	int id;
	int tipo;
	string imagen;
	Fecha fecha;
	Usuario *usuario;

public:
	Publicacion();
	Publicacion(int tipo, string imagen, Fecha fecha, Usuario *usuario);
	Publicacion(const Publicacion& p);
	virtual ~Publicacion();
	Fecha getFecha();
	int getTipo();
	virtual void listarInformacion() = 0;
	int getId();
	Usuario* getUsuario();
};

#endif /* PUBLICACION_H_ */
