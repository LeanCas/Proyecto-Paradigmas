/*
 * Suspendida.cpp
 *
 *  Created on: 27 nov. 2023
 *      Author: Bruno Casavalle
 */

#include "Suspendida.h"
#include "Pregunta.h"

Suspendida::Suspendida(): Estado(){
	tipo = "Suspendida";
}


Estado* Suspendida :: clonar() const {
	return nullptr;
}

void Suspendida::agregarRespuesta(Respuesta* respuesta, Pregunta* pregunta){
	pregunta->agregarRespuesta(respuesta);
}


