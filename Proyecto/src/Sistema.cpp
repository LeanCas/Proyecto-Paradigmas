/*
 * Sistema.cpp
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */

#include <vector>
#include "Sistema.h"

Sistema::Sistema(){}

void Sistema :: crearUsuario(string nombre, string apellido, string paisOrigen, string email, string contrasenia){
	Usuario* nuevoUsuario = new Usuario(nombre, apellido, paisOrigen, email, contrasenia);
	this->usuarios.push_back(nuevoUsuario);
}

Publicacion* Sistema::BuscarPublicaion(int id)
{
	Publicacion* Encontrado;
	vector<Publicacion*>::iterator it;
	for(it = publicaciones.begin(); it != publicaciones.end(); ++it)
	{
		if((*it)->getId() == id)
		{
			Encontrado = (*it);
		}
	}
	return Encontrado;
}

Usuario* Sistema::getUsuario(int id) {
	Usuario* Encontrado;
	vector<Usuario*>::iterator it;
	for(it = usuarios.begin(); it!=usuarios.end(); ++it)
	{
		if((*it)->getId()==id)
		{
			Encontrado = (*it);
			break;
		}
	}
	return Encontrado;
}

Respuesta* Sistema::getRespuesta(int idRespuesta) {
	Respuesta* Encontrado;
	vector<Respuesta*>::iterator it;
	for(it = respuestas.begin(); it!=respuestas.end(); ++it)
	{
		if((*it)->getId()==idRespuesta)
		{
			Encontrado = (*it);
			break;
		}
	}
	return Encontrado;
}

void Sistema::eliminarUsuario(int idUsuario)
{
	Usuario* UsuarioEliminar = getUsuario(idUsuario);
	UsuarioEliminar->eliminarCuenta();
}

Sistema::~Sistema() //Destructor de sistema sin terminar
{
    for (Usuario* usuario : usuarios)
    {
        delete usuario;
    }
    usuarios.clear();
}

void Sistema::darMG(int idUsuario, int idRespuesta) {
    Respuesta* respuesta = getRespuesta(idRespuesta);
    Usuario* usuario = getUsuario(idUsuario);

    if (respuesta && usuario && !usuario->pertenece(idRespuesta)) {
        respuesta->darMG();
        usuario->agregarRespuestaLikeada(respuesta);
    }
}
