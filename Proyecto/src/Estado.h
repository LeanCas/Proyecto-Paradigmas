/*
 * Estado.h
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */

#ifndef ESTADO_H_
#define ESTADO_H_
#include <iostream>

using namespace std;

class Pregunta;
class Respuesta;

class Estado {
	static int autonumerico;

protected:
	int id;
	string tipo;

public:
	Estado();
	virtual ~Estado();
	virtual string getTipo();
	virtual void agregarRespuesta(Respuesta* respuesta, Pregunta* pregunta) = 0;	// Este método es el que cambia según el estado del contexto (Pregunta)
};




#endif /* ESTADO_H_ */
