/*
 * Sistema.h
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */

#ifndef SISTEMA_H_
#define SISTEMA_H_
#include <iostream>
#include "Usuario.h"
#include "Respuesta.h"
#include <vector>
using namespace std;

class Sistema {
	string nombre;
	vector<Respuesta*> respuestas;
	vector<Usuario*> usuarios;
public:
	Sistema();
	~Sistema();
	void crearUsuario(string, string, string, string, string);
	void suspenderPublicacion(Publicacion*);
	void listarPublicaciones();
	void eliminarPublicacion(int);
	void darMG(int idUsuario, int idRespuesta);
	Usuario getUsuario(int idUsuario);
	Respuesta getRespuesta(int idRespuesta); Creo que deberia devolver un puntero a Respuesta
	void rankearUsuarios();
	void eliminarUsuario(int idUsuario);
};





#endif /* SISTEMA_H_ */
