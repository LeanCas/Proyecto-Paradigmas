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

Usuario Sistema::getUsuario(int id)
{
	Usuario *Encontrado;
	vector<Usuario*>::iterator it;
	for(it = usuarios.begin(); it!=usuarios.end(); ++it)
	{
		if((*it)->getId()==id)
		{
			Encontrado = (*it);
			break;
		}
	}
	return *Encontrado;
}

Respuesta Sistema :: getRespuesta(int idRespuesta){
	Respuesta *Encontrado;
		vector<Respuesta*>::iterator it;
		for(it = respuestas.begin(); it!=respuestas.end(); ++it)
		{
			if((*it)->getId()==idRespuesta)
			{
				Encontrado = (*it);
				break;
			}
		}
		return *Encontrado;
}




Sistema::~Sistema() //Destructor de sistema sin terminar
{
    for (Usuario* usuario : usuarios)
    {
        delete usuario;
    }
    usuarios.clear();
}

