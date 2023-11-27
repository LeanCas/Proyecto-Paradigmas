/*
 * Pregunta.cpp
 *
 *  Created on: 26 nov. 2023
 *      Author: chavi
 */

#include "Pregunta.h"
#include "Usuario.h"

// Constructor predeterminado
Pregunta::Pregunta(): Publicacion(), titulo(""), descripcion("") {
	respuestas = vector<Respuesta*>();
	// respuestas = {};
}

// Constructor sobrecargado
Pregunta::Pregunta(string imagen, Fecha fecha, Usuario* usuario, string titulo, string descripcion, vector<string> tags, vector<Respuesta*> respuestas): Publicacion(1, imagen, fecha, usuario), titulo(titulo), descripcion(descripcion), tags(tags) {}

// Constructor copia
Pregunta::Pregunta(const Pregunta& p): Publicacion(p), titulo(p.titulo), descripcion(p.descripcion), tags(p.tags) {
	// Realiza una copia profunda del vector de respuestas
	for (Respuesta* respuesta : p.respuestas) {
		Respuesta* nuevaRespuesta = new Respuesta(*respuesta);
		respuestas.push_back(nuevaRespuesta);
	}
}

void Pregunta :: agregarRespuesta(Respuesta* respuesta){
	this->respuestas.push_back(respuesta);
}

Pregunta::Pregunta(const Publicacion& publicacion) : Publicacion(publicacion) {}

// Destructor
Pregunta::~Pregunta() {
	for (Respuesta* respuesta : respuestas) {
		delete respuesta;
	}
}

void Pregunta::listarInformacion() {
	cout << "Título: " << this->titulo << endl;
	cout << "Descripción: " << this->descripcion << endl;
	cout << "Imagen: " << this->imagen << endl;
	//cout << "Estado: " << this->estado;
	cout << "Fecha: " << this->fecha << endl;
	cout << "Etiquetas: " << endl;
	for (string T : this->tags) {
		cout << T << endl;
	}
}

vector<Respuesta*> Pregunta::getRespuestas() {
	return respuestas;
}
