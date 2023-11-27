/*
 * Usuario.h
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */

#ifndef USUARIO_H_
#define USUARIO_H_
#include <iostream>
#include <vector>
#include "Publicacion.h"
#include "Respuesta.h"

using namespace std;

class Usuario {
	int id;
	static int autonumerico;
	string nombre;
	string apellido;
	string paisOrigen;
	string email;
	string contrasenia;
	vector<string> notificaciones;
	vector<Publicacion*> publicaciones;
	vector<Respuesta*> likesRespuestas;

public:
	Usuario();
	Usuario(string nombre, string apellido, string paisOrigen, string email, string contrasenia, const vector<Publicacion*>& publicaciones={}, const vector<Respuesta*>& likesRespuestas={});
	Usuario(const Usuario& u);
	~Usuario();
	string getNombre();
	int getId();
	void eliminarCuenta();
	void crearPregunta(string imagen, string titulo, string descripcion, vector<string> tags={}, vector<Respuesta*> respuestas={});

	//int contarRespuestasAceptadas();
	//void crearPregunta(string imagen, string titulo, string descripcion, vector<string> tags={});
	//void crearRespuesta(Pregunta);
	//void aceptarSolucion(Respuesta); Estos dos ultimos creo que deberian recibir un puntero a publicación
	//void listarInformacion();
};



#endif /* USUARIO_H_ */
