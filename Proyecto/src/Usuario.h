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
	vector<Publicacion*> likesRespuestas;
	vector<Publicacion*> publicaciones;
public:
	Usuario();
	~Usuario();
	string getNombre();
	void eliminarCuenta();
	int contarRespuestasAceptadas();
	void crearPregunta(int tipo=1, string img);
	void crearRespuesta(Pregunta);
	void aceptarSolucion(Respuesta);
	void listarInformacion();
};



#endif /* USUARIO_H_ */
