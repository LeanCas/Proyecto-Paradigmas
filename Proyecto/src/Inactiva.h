/*
 * Inactiva.h
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */

#ifndef INACTIVA_H_
#define INACTIVA_H_
#include "Estado.h"

class Inactiva : public Estado {
public:
	Inactiva();
	string getTipo();
	Estado* clonar() const override;
	void agregarRespuesta(Respuesta* respuesta, Pregunta* pregunta);

};

#endif /* INACTIVA_H_ */
