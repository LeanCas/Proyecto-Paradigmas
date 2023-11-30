/*
 * Solucionada.cpp
 *
 *  Created on: 27 nov. 2023
 *      Author: Bruno Casavalle
 */

#include "Solucionada.h"
#include "Pregunta.h"

Solucionada::Solucionada(): Estado(){
	tipo = "Solucionada";
}


Estado* Solucionada::clonar() const {
    return new Solucionada(*this);
}

void Solucionada::agregarRespuesta(Respuesta* respuesta, Pregunta* pregunta){
	pregunta->agregarRespuesta(respuesta);
}




