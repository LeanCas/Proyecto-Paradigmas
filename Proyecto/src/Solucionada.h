/*
 * Solucionada.h
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */

#ifndef SOLUCIONADA_H_
#define SOLUCIONADA_H_
#include "Estado.h"

class Solucionada : public Estado {
public:
	Solucionada();
	Estado* clonar() const override;
	void agregarRespuesta(Respuesta* respuesta, Pregunta* pregunta);
};

#endif /* SOLUCIONADA_H_ */
