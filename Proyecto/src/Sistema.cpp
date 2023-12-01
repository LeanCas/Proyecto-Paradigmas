/*
 * Sistema.cpp
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */
#include <vector>
#include <algorithm>
#include "Sistema.h"
#include "Usuario.h"
#include "Pregunta.h"

Sistema::Sistema(string nombre){
	this->nombre = nombre;
}

void Sistema :: crearUsuario(string nombre, string apellido, string paisOrigen, string email, string contrasenia){
	Usuario* nuevoUsuario = new Usuario(nombre, apellido, paisOrigen, email, contrasenia);
	this->usuarios.push_back(nuevoUsuario);
}

void Sistema::crearPregunta(string imagen, string titulo, string descripcion, vector<string> tags, int idUsuario) {
	Usuario* usuario = getUsuario(idUsuario);
	if(usuario != nullptr) {
		Pregunta *nuevaPregunta = usuario->crearPregunta(imagen, titulo, descripcion, tags);
		publicaciones.push_back(nuevaPregunta);
	}
}

void Sistema :: crearRespuesta(int idPregunta,int idUsuario,string imagen,string contenido){
	Pregunta* pregunta = getPregunta(idPregunta);
	Usuario* usuario = getUsuario(idUsuario);
	if(pregunta != nullptr){
		Respuesta* nuevaRespuesta = usuario->crearRespuesta(pregunta, imagen, contenido);
		publicaciones.push_back(nuevaRespuesta);
	}
}

void Sistema::suspenderPublicacion(int idPublicacion) {
	Pregunta* publicacion = dynamic_cast<Pregunta*>(getPublicacion(idPublicacion));
	Fecha fechaActual;
	fechaActual.setFechaActual();
	Fecha fechaPublicacion;
	fechaPublicacion = publicacion->getFecha();

	if(fechaActual.getMes() - fechaPublicacion.getMes() >= 6){
		publicacion->cambiarEstado(publicacion->estadoInactiva);
	}
}

void Sistema::listarPublicaciones() {
	for(Publicacion* publicacion : publicaciones) {
		if(publicacion->getTipo() == 1) {
			Pregunta* pregunta = dynamic_cast<Pregunta*>(publicacion);
			cout<<endl; //AGREGUE ESTA LINEA PARA DARLE MAS ESPACIO A LAS PUBLICACIONES
			pregunta->listarInformacion();
			pregunta->rankearRespuesta();
			//pregunta->listarRespuestas();
		}
	}
}

void Sistema::eliminarPublicacion(int idPublicacion) {
	Publicacion* publicacionAEliminar = getPublicacion(idPublicacion);
	if(publicacionAEliminar != nullptr) {
		vector<Publicacion*>::iterator it;
		for(it = publicaciones.begin(); it!=publicaciones.end(); ++it) {
			if((*it) == publicacionAEliminar) {
				delete (*it);
				publicaciones.erase(it);
				break;
			}
		}
	}
}

void Sistema::eliminarUsuario(int idUsuario) {
    Usuario* usuarioAEliminar = getUsuario(idUsuario);

    if (usuarioAEliminar != nullptr) {
        vector<Usuario*>::iterator it;
        for (it = usuarios.begin(); it != usuarios.end(); ++it) {
            if ((*it) == usuarioAEliminar) {
                usuarios.erase(it);
                break;
            }
        }
        usuarioAEliminar->eliminarCuenta();
    }
}


void Sistema::darMG(int idUsuario, int idRespuesta) {
    Respuesta* respuesta = this->getRespuesta(idRespuesta);
    Usuario* usuario = this->getUsuario(idUsuario);

    if (respuesta != nullptr && usuario != nullptr && !usuario->pertenece(idRespuesta)) {
        respuesta->darMG();
        usuario->agregarRespuestaLikeada(respuesta);
    }
}

void Sistema::rankearUsuarios(){
	    sort(usuarios.begin(), usuarios.end(), [](Usuario* u1,Usuario* u2) {
	        return u1->contarRespuestasAceptadas() > u2->contarRespuestasAceptadas();
	    });
	    cout << "Usuarios rankeados por respuestas aceptadas:" <<endl;
	    for (Usuario* usuario : usuarios) {
	        cout << "ID: "<<usuario->getId()<<", Nombre: "<<usuario->getNombre()<<endl;
	    }
}
// Getters

Publicacion* Sistema::getPublicacion(int idPublicacion) {
	Publicacion* encontrado = nullptr;
	vector<Publicacion*>::iterator it;
	for(it = publicaciones.begin(); it != publicaciones.end(); ++it) {
		if((*it)->getId() == idPublicacion) {
			encontrado = (*it);
		}
	}
	return encontrado;
}

Usuario* Sistema::getUsuario(int id) {
	Usuario* Encontrado;
	vector<Usuario*>::iterator it;
	for(it = usuarios.begin(); it!=usuarios.end(); ++it) {
		if((*it)->getId()==id) {
			Encontrado = (*it);
			break;
		}
	}
	return Encontrado;
}

Respuesta* Sistema::getRespuesta(int idRespuesta) {
	Respuesta* Encontrado = dynamic_cast<Respuesta*>(getPublicacion(idRespuesta));
	return Encontrado;
}

Pregunta* Sistema::getPregunta(int idPregunta){
	Pregunta* Encontrado = dynamic_cast<Pregunta*>(getPublicacion(idPregunta));
	return Encontrado;
}

// Destructor

Sistema::~Sistema() {
	for (Publicacion* publicacion : publicaciones) {
		delete publicacion;
	}
	publicaciones.clear();

    for (Usuario* usuario : usuarios) {
        delete usuario;
    }
    usuarios.clear();
}
