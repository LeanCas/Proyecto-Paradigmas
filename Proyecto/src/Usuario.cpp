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
				Pregunta* nuevaPublicacion = new Pregunta(*publicacion);
				publicaciones.push_back(nuevaPublicacion);
			}
			else {
				Respuesta* nuevaPublicacion = new Respuesta(*publicacion);
				publicaciones.push_back(nuevaPublicacion);
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
	vector<Publicacion*>::iterator it;
	for(it = publicaciones.begin(); it!=publicaciones.end(); ++it)
	{
		Pregunta* pregunta = dynamic_cast<Pregunta*>(*it);//Realiza una conversión desde una clase especificada a una clase derivada
		if(pregunta!=nullptr)
		{
			//pregunta->cambiarEstado();
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

void Usuario::crearPregunta(string imagen, string titulo, string descripcion, vector<string> tags, vector<Respuesta*> respuestas) {
    Pregunta* nuevaPregunta = new Pregunta(imagen, Fecha(), this, titulo, descripcion, tags, respuestas);
    publicaciones.push_back(nuevaPregunta);
}
