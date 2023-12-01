/*
 * Respuesta.cpp
 *
 *  Created on: 26 nov. 2023
 *      Author: chavi
 */

#include "Respuesta.h"
#include "Usuario.h"

// Constructor predeterminado
Respuesta::Respuesta(): Publicacion(), contenido(""), meGusta(0), aceptada(false) {
	this->tipo= 2;
}

// Constructor sobrecargado
Respuesta::Respuesta(string imagen, Fecha fecha, Usuario *usuario, string contenido, int meGusta, bool aceptada): Publicacion(2, imagen, fecha, usuario), contenido(contenido), meGusta(meGusta), aceptada(aceptada) {}

// Constructor copia
Respuesta::Respuesta(const Respuesta& r): Publicacion(r), contenido(r.contenido), meGusta(r.meGusta), aceptada(r.aceptada) {}

// Destructor
Respuesta::~Respuesta() {
	//Publicacion::~Publicacion();		// Llama al destructor virtual de la clase base. Esto garantiza que se realice la limpieza adecuada en la jerarquía de clases.
}

void Respuesta::listarInformacion() {
	cout << endl;
	cout<<"Id respuesta: "<<id<<endl;
	if(aceptada){
		cout<<"Aceptada"<<endl;
	}else{
		cout<<"Sin aceptar"<<endl;
	}
	cout << "Contenido: " << contenido << endl;
	cout << "Me gusta: " << meGusta << endl;
	cout << "Fecha: " << fecha << endl;
	cout << "Aceptada :" << aceptada << endl;
	cout << endl;
}

void Respuesta::darMG() {
	this->meGusta++;
}
bool Respuesta::esAceptada(){
	return aceptada;
}

void Respuesta::aceptarSolucion() {
	aceptada = true;
}

int Respuesta::contarMeGusta(){
	return meGusta;
}

void Respuesta::agregarRespuestaUsuario(){
	usuario->agregarRespuesta(this);
}
