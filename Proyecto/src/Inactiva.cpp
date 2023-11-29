/*
 * Inactiva.cpp
 *
 *  Created on: 27 nov. 2023
 *      Author: Bruno Casavalle
 */

#include "Inactiva.h"
#include "Pregunta.h"

string Inactiva :: getTipo(){
	return "Inactiva";
}




void Inactiva::agregarRespuesta(Respuesta* respuesta, Pregunta* pregunta){

	pregunta->cambiarEstado(pregunta->estadoActiva);

	 pregunta->agregarRespuesta(respuesta);

 }
