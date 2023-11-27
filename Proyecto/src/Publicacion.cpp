/*
 * Publicacion.cpp
 *
 *  Created on: 26 nov. 2023
 *      Author: chavi
 */

#include "Publicacion.h"
#include "Usuario.h"

int Publicacion::autonumerico = 0;

// Constructor predeterminado
Publicacion::Publicacion() : id(++autonumerico), tipo(0), imagen(""), fecha(), usuario(nullptr) {}

// Constructor sorecargado
Publicacion::Publicacion(int tipo, string imagen, Fecha fecha, Usuario *usuario): id(++autonumerico), tipo(tipo), imagen(imagen), fecha(fecha), usuario(usuario) {}

// Constructor copia
Publicacion::Publicacion(const Publicacion& p): id(p.id), tipo(p.tipo), imagen(p.imagen), fecha(p.fecha) {
    // Realizar una copia profunda del usuario si existe
    if (p.usuario != nullptr) {
        usuario = new Usuario(*p.usuario);
    }
    else {
    	usuario = nullptr;		// Asegura que el puntero sea nulo si el original es nulo
    }
}

Fecha Publicacion :: getFecha(){
	return this->fecha;
}

int Publicacion::getTipo() {
	return this->tipo;
}

int Publicacion::getId() {
	return this->id;
}

// Destructor
Publicacion::~Publicacion() {
	if (usuario != nullptr) {
		delete usuario;
	}
}
