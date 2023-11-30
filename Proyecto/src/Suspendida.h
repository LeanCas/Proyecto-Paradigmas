/*
 * Suspendida.h
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */

#ifndef SUSPENDIDA_H_
#define SUSPENDIDA_H_
#include "Estado.h"

class Suspendida : public Estado {
public:
	Suspendida();
	~Suspendida();
	void agregarRespuesta(Respuesta* respuesta, Pregunta* pregunta);
};

#endif /* SUSPENDIDA_H_ */
