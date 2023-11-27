/*
 * Respuesta.cpp
 *
 *  Created on: 26 nov. 2023
 *      Author: chavi
 */

#include "Respuesta.h"

// Constructor predeterminado
Respuesta::Respuesta(): Publicacion(), contenido(""), meGusta(0), aceptada(false) {
	this->tipo= 2;
}

// Constructor sobrecargado
Respuesta::Respuesta(string imagen, Fecha fecha, Usuario *usuario, string contenido, int meGusta, bool aceptada): Publicacion(2, imagen, fecha, usuario), contenido(contenido), meGusta(meGusta), aceptada(aceptada) {}

// Constructor copia
Respuesta::Respuesta(const Respuesta& r): Publicacion(r), contenido(r.contenido), meGusta(r.meGusta), aceptada(r.aceptada) {}

Respuesta::Respuesta(const Publicacion& publicacion) : Publicacion(publicacion), meGusta(0), aceptada(false) {}

// Destructor
Respuesta::~Respuesta() {
	Publicacion::~Publicacion();		// Llama al destructor virtual de la clase base. Esto garantiza que se realice la limpieza adecuada en la jerarquía de clases.
}

void Respuesta::listarInformacion() {
	cout << "Contenido: " << this->contenido << endl;
	cout << "Me gusta: " << this->meGusta << endl;
	cout << "Fecha: " << this->fecha << endl;
}

void Respuesta::darMG() {
	this->meGusta++;
}
