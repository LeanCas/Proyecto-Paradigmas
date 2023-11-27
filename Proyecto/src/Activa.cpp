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

Activa::Activa(): Estado(), tipo("Activa") {}

void Activa::agregarRespuesta(Respuesta* respuesta, Pregunta* pregunta) {
	vector<Respuesta*>& respuestas = pregunta->getRespuestas();
	respuestas.push_back(respuesta);
	pregunta->notificarUsuario(respuesta);
}
