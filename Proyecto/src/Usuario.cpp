/*
 * Usuario.cpp
 *
 *  Created on: 26 nov. 2023
 *      Author: chavi
 */

#include "Usuario.h"
#include "Publicacion.h"
#include "Respuesta.h"
#include "Pregunta.h"

using namespace std;

int Usuario::autonumerico = 0;

// Constructor predeterminado
Usuario::Usuario(): id(++autonumerico){}

// Constructor sobrecargado
Usuario::Usuario(string nombre, string apellido, string paisOrigen, string email, string contrasenia, const vector<Publicacion*>& publicaciones, const vector<Respuesta*>& likesRespuestas): id(++autonumerico), nombre(nombre), apellido(apellido), paisOrigen(paisOrigen),email(email), contrasenia(contrasenia), publicaciones(publicaciones), likesRespuestas(likesRespuestas){}

// Constructor copia
Usuario::Usuario(const Usuario& u): id(u.id), nombre(u.nombre),apellido(u.apellido), paisOrigen(u.paisOrigen), email(u.email), contrasenia(u.contrasenia), notificaciones(u.notificaciones) {
	for (Publicacion* publicacion : u.publicaciones) {
		if (publicacion != nullptr) {
			if (publicacion->getTipo() == 1) {
				Pregunta* pregunta = dynamic_cast<Pregunta*>(publicacion);	// Se transforma la publicacion al tipo Pregunta
				if (pregunta != nullptr) {
					Pregunta* nuevaPregunta = new Pregunta(*pregunta);
					publicaciones.push_back(nuevaPregunta);
				}
			}
			else if (publicacion->getTipo() == 2){
				Respuesta* respuesta = dynamic_cast<Respuesta*>(publicacion);
				if (respuesta != nullptr) {
					Respuesta* nuevaRespuesta = new Respuesta(*respuesta);
					publicaciones.push_back(nuevaRespuesta);
				}
			}
		}
	}
	for (Respuesta* respuesta : u.likesRespuestas) {
		if (respuesta != nullptr) {
			Respuesta* nuevaRespuesta = new Respuesta(*respuesta);
			likesRespuestas.push_back(nuevaRespuesta);
		}
	}
}

void Usuario::eliminarCuenta()
{
	for(Publicacion* publicacion : publicaciones)
	{
		if(publicacion->getTipo() == 1)
		{
			Pregunta* pregunta = dynamic_cast<Pregunta*>(publicacion); //Realiza una conversión desde una clase especificada a una clase derivada
			pregunta->cambiarEstado(pregunta->estadoInactiva);
		}
	}
}

// Destructor
Usuario::~Usuario() {
    // Liberar memoria de las publicaciones
    for (Publicacion* publicacion : publicaciones) {
        delete publicacion;
    }

    // Liberar memoria de las respuestas que le gustan al usuario
    for (Publicacion* respuesta : likesRespuestas) {
        delete respuesta;
    }
}

string Usuario::getNombre(){
	return nombre;
}

int Usuario::getId(){
	return id;
}

void Usuario::agregarRespuestaLikeada(Respuesta* respuesta) {
    likesRespuestas.push_back(respuesta);
}



bool Usuario::pertenece(int idBuscado) {
	for (Publicacion* publicacion : publicaciones) {
		if (publicacion->getId() == idBuscado) {
			return true;
		}
	}
	return false;
}

int Usuario::contarRespuestasAceptadas(){
	int cont = 0;
	vector<Publicacion*>::iterator it;
	for(it = publicaciones.begin(); it!=publicaciones.end(); ++it)
	{// Utilizamos dynamic_cast para comprobar si el objeto es de tipo Respuesta
		if ((*it)->getTipo() == 2 && dynamic_cast<Respuesta*>(*it) != nullptr) {
			// El puntero apunta a un objeto de tipo Respuesta, podemos llamar a esAceptada()
			if (dynamic_cast<Respuesta*>(*it)->esAceptada()) {
				cont++;
			}
		}
	}
	return cont;
}

void Usuario::listarInformacion(){
	cout << "Id: " << id << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Apellido: " << apellido << endl;
	cout << "Email: " << email<<endl;
}

void Usuario::aceptarSolucion(Pregunta* pregunta, int idRespuesta) {
	for (Respuesta* respuesta : pregunta->getRespuestas()) {
		if (respuesta->getId() == idRespuesta) {
			respuesta->aceptarSolucion();
		}
	}
}

Pregunta* Usuario::crearPregunta(string imagen, string titulo, string descripcion, vector<string> tags) {
    Pregunta* nuevaPregunta = new Pregunta(imagen, Fecha(), this, titulo, descripcion, tags);
    publicaciones.push_back(nuevaPregunta);
    return nuevaPregunta;
}


Respuesta* Usuario::crearRespuesta(Pregunta* pregunta, string imagen, string contenido){
	Respuesta* nuevaRespuesta = new Respuesta(imagen, Fecha(), this, contenido);
	pregunta->addRespuesta(nuevaRespuesta);
	return nuevaRespuesta;
}


void Usuario::agregarNotificacion(string mensaje) {
	notificaciones.push_back(mensaje);
}
