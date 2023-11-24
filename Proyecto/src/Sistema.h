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
#include <vector>
using namespace std;

class Sistema {
	string nombre;
	vector<Publicacion*> publicaciones;
	vector<Usuario> usuarios;
public:
	Sistema();
	~Sistema();
	void crearUsuario(string, string, string, string, string);
	void suspenderPublicacion(Publicacion);
	void listarPublicaciones();
	void eliminarPublicacion(int);
	void darMG(int idUsuario, int idRespuesta);
	Usuario getUsuario(int idUsuario);
	Respuesta getRespuesta(int idRespuesta);
	void rankearUsuarios();
	void eliminarUsuario(int idUsuario);
};





#endif /* SISTEMA_H_ */
