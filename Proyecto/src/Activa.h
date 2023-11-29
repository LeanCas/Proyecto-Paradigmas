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
	Estado* clonar() const override;
	void agregarRespuesta(Respuesta* respuesta, Pregunta* pregunta) ;
};

#endif /* ACTIVA_H_ */
