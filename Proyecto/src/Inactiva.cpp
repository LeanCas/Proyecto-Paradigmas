/*
 * Inactiva.cpp
 *
 *  Created on: 27 nov. 2023
 *      Author: Bruno Casavalle
 */

#include "Inactiva.h"
#include "Pregunta.h"

Inactiva::Inactiva(): Estado(){
	tipo = "Inactiva";
}

string Inactiva :: getTipo(){
	return "Inactiva";
}

Estado* Inactiva::clonar() const {
    return new Inactiva(*this);
}


void Inactiva::agregarRespuesta(Respuesta* respuesta, Pregunta* pregunta){

	pregunta->cambiarEstado(pregunta->estadoActiva);

	 pregunta->agregarRespuesta(respuesta);

 }
