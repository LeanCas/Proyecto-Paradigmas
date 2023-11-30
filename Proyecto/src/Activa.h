/*
 * Activa.h
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */

#ifndef ACTIVA_H_
#define ACTIVA_H_
#include "Estado.h"

class Activa : public Estado {
public:
	Activa();
	~Activa();
	void agregarRespuesta(Respuesta* respuesta, Pregunta* pregunta);
};

#endif /* ACTIVA_H_ */
