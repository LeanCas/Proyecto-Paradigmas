/*
 * Suspendida.cpp
 *
 *  Created on: 27 nov. 2023
 *      Author: Bruno Casavalle
 */

#include "Suspendida.h"
#include "Pregunta.h"
#include "Respuesta.h"

Suspendida::Suspendida(): Estado() {
	tipo = "Suspendida";
}

Suspendida::~Suspendida() {}

void Suspendida::agregarRespuesta(Respuesta* respuesta, Pregunta* pregunta) {
	pregunta->agregarRespuesta(respuesta);
	respuesta->agregarRespuestaUsuario();
}
