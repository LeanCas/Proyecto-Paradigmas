/*
 * Respuesta.h
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */

#ifndef RESPUESTA_H_
#define RESPUESTA_H_
#include <iostream>
#include <vector>
#include "Publicacion.h"

using namespace std;

class Respuesta : public Publicacion {
	string contenido;
	int meGusta;
	bool aceptada;
public:
	Respuesta();
	~Respuesta();
	int contarMeGusta();
	void listarInformacion();
	bool esAceptada();
};





#endif /* RESPUESTA_H_ */
