//============================================================================
// Name        : Proyecto.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Sistema.h"
#include "Usuario.h"
#include "Publicacion.h"
#include "Pregunta.h"
#include "Respuesta.h"
#include "Estado.h"
#include "Activa.h"
#include "Inactiva.h"
#include "Suspendida.h"
#include "Solucionada.h"
#include "Fecha.h"

int main() {

	//PRUEBA DE SISTEMA

	//CREACION DE RESPUESTAS

	Sistema* sistema = new Sistema("Nombre sistema");

	//CREACION DE USUARIOS

	sistema->crearUsuario("usuario-nombre 1", "usuario-apellido 1", "Argentina", "example1@gmail.com", "12345");

	sistema->crearUsuario("usuario-nombre 2", "usuario-apellido 2", "Uruguay", "example2@gmail.com", "12345");

	sistema->crearUsuario("usuario-nombre 3", "usuario-apellido 3", "Colombia", "example3@gmail.com", "12345");

	//CREACION DE PREGUNTAS

	Usuario* usuario1 = sistema->getUsuario(1);

	usuario1->listarInformacion();

	vector<string> tags;

	tags.push_back("tag1");
	tags.push_back("tag2");
	tags.push_back("tag3");

	usuario1->crearPregunta(sistema,"oso.png","Pregunta 1", "Descripcion 1", tags);

	usuario1->crearPregunta(sistema,"oso.png","Pregunta 2", "Descripcion 2", tags);

	usuario1->crearPregunta(sistema,"oso.png","Pregunta 3", "Descripcion 3", tags);

	// LISTAMOS PUBLICACIONES

	sistema->listarPublicaciones();






	/*
	//mini pruebita xd
	Sistema *sistema = new Sistema();

	sistema->crearUsuario("Sofi", "Cruz", "Argentina", "blasjasbjs","12345fff");
	cout <<"Nombre: " <<sistema->getUsuario(1)->getNombre();

	delete sistema;
	*/
	return 0;
}
