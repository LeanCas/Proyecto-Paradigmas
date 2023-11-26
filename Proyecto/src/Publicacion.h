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
	Fecha fecha;
	Usuario *usuario;
public:
	Publicacion();
	virtual ~Publicacion();
	Fecha getFecha();
	string getTipo();
	virtual void listarInformacion() = 0;
	//
	int getId();
};

#endif /* PUBLICACION_H_ */
