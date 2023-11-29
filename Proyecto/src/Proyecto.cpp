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

	sistema->crearUsuario("usuario-nombre 1", "usuario-apellido 1", "Argentina", "example@gmail.com", "12345");











	/*
	//mini pruebita xd
	Sistema *sistema = new Sistema();

	sistema->crearUsuario("Sofi", "Cruz", "Argentina", "blasjasbjs","12345fff");
	cout <<"Nombre: " <<sistema->getUsuario(1)->getNombre();

	delete sistema;
	*/
	return 0;
}
