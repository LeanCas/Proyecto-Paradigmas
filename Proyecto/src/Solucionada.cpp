/*
 * Solucionada.cpp
 *
 *  Created on: 27 nov. 2023
 *      Author: Bruno Casavalle
 */

#include "Solucionada.h"
#include "Pregunta.h"
#include "Respuesta.h"

Solucionada::Solucionada(): Estado() {
	tipo = "Solucionada";
}

Solucionada::~Solucionada() {}

void Solucionada::agregarRespuesta(Respuesta* respuesta, Pregunta* pregunta) {
	cout << "La pregunta está solucionada, no admite más respuestas" << endl;
}
