/*
 * Sistema.h
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */

#ifndef SISTEMA_H_
#define SISTEMA_H_
#include <iostream>
#include <vector>
#include "Usuario.h"
#include "Respuesta.h"
#include "Pregunta.h"
#include "Publicacion.h"

using namespace std;

class Sistema {
	string nombre;
	vector<Publicacion*> publicaciones;	// Agregación
	vector<Usuario*> usuarios;	// Debe ser composición, no un vector de punteros (?)

public:
	Sistema(string);
	~Sistema();
	void crearUsuario(string nombre, string apellido, string paisOrigen, string email, string contrasenia);		// OK - revisado
	void crearPregunta(string imagen, string titulo, string descripcion, vector<string> tags, int idUsuario);		// OK - revisado
	void crearRespuesta(int idPregunta,int idUsuario,string imagen,string contenido);		// OK - revisado
	void suspenderPublicacion(int idPublicacion);		// OK - revisado
	void listarPublicaciones();		// OK - revisado
	void eliminarPublicacion(int);		// OK - revisado
	void eliminarUsuario(int idUsuario);		// OK - revisado
	void darMG(int idUsuario, int idRespuesta);		// OK - revisado
	void rankearUsuarios();		// OK - revisado

	// Getters

	Usuario* getUsuario(int idUsuario);		// OK - revisado
	Respuesta* getRespuesta(int idRespuesta);		// OK - revisado
	Pregunta* getPregunta(int idPregunta);		// OK - revisado
	Publicacion* getPublicacion(int idPublicacion);		// OK - revisado



};

#endif /* SISTEMA_H_ */
