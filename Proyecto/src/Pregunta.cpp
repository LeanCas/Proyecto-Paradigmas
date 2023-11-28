/*
 * Pregunta.cpp
 *
 *  Created on: 26 nov. 2023
 *      Author: chavi
 */

#include "Pregunta.h"
#include "Usuario.h"
#include "Activa.h"

// Constructor predeterminado
Pregunta::Pregunta(): Publicacion(), titulo(""), descripcion("") {
	respuestas = vector<Respuesta*>();
	// respuestas = {};
	estado = new Activa();
}

// Constructor sobrecargado
Pregunta::Pregunta(string imagen, Fecha fecha, Usuario* usuario, string titulo, string descripcion, vector<string> tags, vector<Respuesta*> respuestas): Publicacion(1, imagen, fecha, usuario), titulo(titulo), descripcion(descripcion), tags(tags), estado(new Activa()) {}

// Constructor copia
Pregunta::Pregunta(const Pregunta& p): Publicacion(p), titulo(p.titulo), descripcion(p.descripcion), tags(p.tags) {
    // Clona el estado de la pregunta referenciada utilizando el método clonar
    estado = p.estado->clonar();

	// Realiza una copia profunda del vector de respuestas
	for (Respuesta* respuesta : p.respuestas) {
		Respuesta* nuevaRespuesta = new Respuesta(*respuesta);
		respuestas.push_back(nuevaRespuesta);
	}
}

void Pregunta :: agregarRespuesta(Respuesta* respuesta){
	this->respuestas.push_back(respuesta);
}

// Destructor
Pregunta::~Pregunta() {
	for (Respuesta* respuesta : respuestas) {
		delete respuesta;
	}
}

void Pregunta::listarInformacion() {
	cout << "Título: " << titulo << endl;
	cout << "Descripción: " << descripcion << endl;
	cout << "Imagen: " << imagen << endl;
	cout << "Estado: " << estado->getTipo();
	cout << "Fecha: " << fecha << endl;
	cout << "Etiquetas: " << endl;
	for (string T : tags) {
		cout << T << endl;
	}
}

vector<Respuesta*> Pregunta::getRespuestas() {
	return respuestas;
}

string Pregunta::getTitulo(){
	return titulo;
}

void Pregunta::listarRespuestas()
{
	for(Respuesta* respuesta: respuestas)
	{
		respuesta->listarInformacion();
	}
}

Estado* Pregunta::getEstado() {
	return estado;
}

void Pregunta::cambiarEstado(Estado* nuevoEstado) {
	delete estado;		// Esto libera la memoria del estado anterior
	estado = nuevoEstado;		// Se asigna el nuevo estado recibido como parámetro
}
