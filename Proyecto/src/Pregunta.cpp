/*
 * Pregunta.cpp
 *
 *  Created on: 26 nov. 2023
 *      Author: chavi
 */
#include <vector>
#include <algorithm>
#include <functional>
#include "Pregunta.h"
#include "Usuario.h"
#include "Activa.h"
#include "Inactiva.h"
#include "Solucionada.h"
#include "Suspendida.h"

Estado* Pregunta::estadoActiva = new Activa();
Estado* Pregunta::estadoInactiva = new Inactiva();
Estado* Pregunta::estadoSolucionada = new Solucionada();
Estado* Pregunta::estadoSuspendida = new Suspendida();


// Constructor predeterminado
Pregunta::Pregunta(): Publicacion(), titulo(""), descripcion("") {
	respuestas = vector<Respuesta*>();
	// respuestas = {};
	estado = estadoActiva;
}

// Constructor sobrecargado
Pregunta::Pregunta(string imagen, Fecha fecha, Usuario* usuario, string titulo, string descripcion, vector<string> tags, vector<Respuesta*> respuestas): Publicacion(1, imagen, fecha, usuario), titulo(titulo), descripcion(descripcion), tags(tags), estado(estadoActiva) {}

// Constructor copia (evaluar si es necesario mantenerlo o no)
Pregunta::Pregunta(const Pregunta& p): Publicacion(p), titulo(p.titulo), descripcion(p.descripcion), tags(p.tags),estado(p.estado){
    // Clona el estado de la pregunta referenciada utilizando el método clonar
  //  estado = p.estado->clonar();

	// Realiza una copia profunda del vector de respuestas
	for (Respuesta* respuesta : p.respuestas) {
		Respuesta* nuevaRespuesta = new Respuesta(*respuesta);
		respuestas.push_back(nuevaRespuesta);
	}
}

void Pregunta :: agregarRespuesta(Respuesta* respuesta){
	this->respuestas.push_back(respuesta);
}

void Pregunta :: addRespuesta(Respuesta* respuesta){
	this->estado->agregarRespuesta(respuesta, this);
}

// Destructor
Pregunta::~Pregunta() {
	for (Respuesta* respuesta : respuestas) {
		delete respuesta;
	}
	respuestas.clear();
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
	estado = nuevoEstado;		// Se asigna el nuevo estado recibido como parámetro
}

void Pregunta::rankearRespuesta() {
    // Ordenamos las respuestas en funcion de la cantidad de "me gusta"
    sort(respuestas.begin(), respuestas.end(),[](Respuesta* u1, Respuesta* u2) {
                  if (u1->esAceptada() && !u2->esAceptada()) {
                      // Respuesta aceptada va antes
                      return true;
                  } else if (!u1->esAceptada() && u2->esAceptada()) {
                      // Respuesta aceptada va después
                      return false;
                  } else {
                      // Ambas respuestas no aceptadas,
                      // Entonces ordenar por la cantidad de "me gustas"
                      return u1->contarMeGusta() > u2->contarMeGusta();
                  }
              });
    this->listarRespuestas();
}

void Pregunta::notificarUsuario(Respuesta* respuesta) {
	string mensaje = "El usuario " + respuesta->getUsuario()->getNombre() + " respondió a tu pregunta: " + this->getTitulo();
	this->usuario->agregarNotificacion(mensaje);
}
