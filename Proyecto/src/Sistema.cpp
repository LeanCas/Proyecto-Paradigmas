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
#include "Suspendida.h"

Sistema::Sistema(string nombre){
	this->nombre = nombre;
}

void Sistema :: crearUsuario(string nombre, string apellido, string paisOrigen, string email, string contrasenia){
	Usuario* nuevoUsuario = new Usuario(nombre, apellido, paisOrigen, email, contrasenia);
	this->usuarios.push_back(nuevoUsuario);
}

/*
void Sistema::listarPublicaciones()
{
	for(Publicacion* publicacion : publicaciones)
	{
		if(publicacion->getTipo() == 1)
		{
			Pregunta* pregunta = dynamic_cast<Pregunta*>(publicacion);
			pregunta->getTitulo();
			pregunta->listarRespuestas();
		}
	}
}*/

void Sistema::listarPublicaciones()
{
	for(Publicacion* publicacion : publicaciones)
	{
		if(publicacion->getTipo() == 1)
		{
			Pregunta* pregunta = dynamic_cast<Pregunta*>(publicacion);
			pregunta->getTitulo();
			pregunta->listarRespuestas();
		}
	}
}

Publicacion* Sistema::buscarPublicacion(int id)
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

/*void Sistema :: suspenderPublicacion(Publicacion* publicacion){

	Pregunta* pregunta = dynamic_cast<Pregunta*>(publicacion);

	Fecha fechaActual;
	fechaActual.setFechaActual();
	Fecha fechaPublicacion;
	fechaPublicacion = pregunta->getFecha();

	if(fechaActual.getMes() - fechaPublicacion.getMes() >= 6){
		Estado* nuevoEstado = new Suspendida();
		pregunta->cambiarEstado(nuevoEstado);
	}
}*/

void Sistema::eliminarPublicacion(int id)
{
	Publicacion* publicacionAEliminar = buscarPublicacion(id);
	delete publicacionAEliminar; //Invoca al destructor de la clase derivada correspondiente
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
	Respuesta* Encontrado = dynamic_cast<Respuesta*>(buscarPublicacion(idRespuesta));
	return Encontrado;
}

void Sistema::eliminarUsuario(int idUsuario)
{
	Usuario* UsuarioEliminar = getUsuario(idUsuario);
	UsuarioEliminar->eliminarCuenta();
}

Sistema::~Sistema()
{
	for (Publicacion* publicacion : publicaciones)
	{
		delete publicacion;
	}
	publicaciones.clear();

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


void Sistema::rankearUsuarios(){
	    sort(usuarios.begin(), usuarios.end(), [](Usuario* u1,Usuario* u2) {
	        return u1->contarRespuestasAceptadas() > u2->contarRespuestasAceptadas();
	    });
	    cout << "Usuarios rankeados por respuestas aceptadas:" <<endl;
	    for (Usuario* usuario : usuarios) {
	        cout << "ID: "<<usuario->getId()<<", Nombre: "<<usuario->getNombre()<<endl;
	    }
}





//AGREGADO ULTIMO

void Sistema :: agregarPublicacion(Publicacion* publicacion){
	this->publicaciones.push_back(publicacion);
}



