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

	Usuario* usuario2 = sistema->getUsuario(2);

	Usuario* usuario3 = sistema->getUsuario(3);

	//usuario1->listarInformacion();

	vector<string> tags;

	tags.push_back("tag1");
	tags.push_back("tag2");
	tags.push_back("tag3");

	sistema->crearPregunta("oso.png","Pregunta 1", "Descripcion 1", tags, 1);

	sistema->crearPregunta("oso.png","Pregunta 2", "Descripcion 2", tags, 1);

	sistema->crearPregunta("oso.png","Pregunta 3", "Descripcion 3", tags, 1);

	sistema->crearPregunta("oso.png","Pregunta 4", "Descripcion 4", tags, 2);

	sistema->crearPregunta("oso.png","Pregunta 5", "Descripcion 5", tags, 3);


	// LISTAMOS PUBLICACIONES

	//sistema->listarPublicaciones();

	//PROBAMOS BUSCAR PUBLICACION

	//Publicacion* respuesta1 = sistema->buscarPublicacion(1);

	// HACEMOS RESPUESTAS

	sistema->crearRespuesta(1,1,"osito.png","contenido-respuesta1");

	sistema->crearRespuesta(1,2,"osito.png","contenido-respuesta2");

	sistema->crearRespuesta(1,3,"osito.png","contenido-respuesta3");

	//.sistema->getUsuario(1)->aceptarSolucion(sistema->getPublicacion())

	//PRUEBA DE FUNCION DE DAR ME GUSTA, es id=6 por el autonumerico incremental en publicaciones, al crearse 5 publicaciones antes de pregunta
	sistema->darMG(1,6);
	sistema->darMG(2,6);
	sistema->darMG(3,6);
	sistema->darMG(3,8);
	sistema->darMG(1,6);
	//cout<<endl<<endl<<"Mostrar las publicaciones y sus me gustas en respuestas"<<endl;
	//sistema->listarPublicaciones();

	/*cout<<endl<<endl<<"Prueba de cambio de estado"<<endl;
	sistema->eliminarUsuario(2);
	sistema->listarPublicaciones();
	*/
	//usuario1->aceptarSolucion(sistema->getPregunta(1), 7);
	sistema->getUsuario(1)->aceptarSolucion(dynamic_cast<Pregunta*>(sistema->getPublicacion(1)),7);
	sistema->crearRespuesta(1,2,"osito.png","contenido-respuesta2");
	sistema->getUsuario(1)->aceptarSolucion(dynamic_cast<Pregunta*>(sistema->getPublicacion(1)),8);
	//sistema->getUsuario(1)->listarRespuestasAceptadas();
	sistema->rankearUsuarios();
	//sistema->listarPublicaciones();
	return 0;
}
