/*
 * Activa.cpp
 *
 *  Created on: 27 nov. 2023
 *      Author: Bruno Casavalle
 */

#include "Activa.h"
#include "Pregunta.h"
#include "Respuesta.h"
#include <vector>

Activa::Activa(): Estado() {
	tipo = "Activa";
}

Estado* Activa::clonar() const {
    return new Activa(*this);
}
 void Activa::agregarRespuesta(Respuesta* respuesta, Pregunta* pregunta){

	 pregunta->agregarRespuesta(respuesta);

 }
