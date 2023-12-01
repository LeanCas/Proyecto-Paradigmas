/*
 * Inactiva.cpp
 *
 *  Created on: 27 nov. 2023
 *      Author: Bruno Casavalle
 */

#include "Inactiva.h"
#include "Pregunta.h"
#include "Respuesta.h"

Inactiva::Inactiva(): Estado() {
	tipo = "Inactiva";
}

Inactiva::~Inactiva() {}

void Inactiva::agregarRespuesta(Respuesta* respuesta, Pregunta* pregunta){
	pregunta->cambiarEstado(pregunta->estadoActiva);
	pregunta->agregarRespuesta(respuesta);
	pregunta->notificarUsuario(respuesta);
	respuesta->agregarRespuestaUsuario();
}
