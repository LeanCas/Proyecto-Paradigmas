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
	Respuesta(string imagen="", Fecha fecha=Fecha(), Usuario *usuario=nullptr, string contenido="", int meGusta=0, bool aceptada=false);
	Respuesta(const Respuesta& r);
	// Constructor que acepta una Publicacion
	Respuesta(const Publicacion& publicacion);
	~Respuesta();
	void darMG();
	int contarMeGusta();
	void listarInformacion() override;
	bool esAceptada();
	void aceptarSolucion();
};

#endif /* RESPUESTA_H_ */
