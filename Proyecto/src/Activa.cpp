/*
 * Activa.cpp
 *
 *  Created on: 27 nov. 2023
 *      Author: Bruno Casavalle
 */

#include "Activa.h"
#include "Pregunta.h"
#include "Respuesta.h"

Activa::Activa(): Estado() {
	tipo = "Activa";
}

Activa::~Activa() {}

void Activa::agregarRespuesta(Respuesta* respuesta, Pregunta* pregunta){
	 pregunta->agregarRespuesta(respuesta);
	 pregunta->notificarUsuario(respuesta);
}
