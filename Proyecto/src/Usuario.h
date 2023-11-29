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
#include "Sistema.h"
#include "Publicacion.h"
#include "Respuesta.h"
#include "Pregunta.h"

class Sistema;

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
	void crearPregunta(string imagen, string titulo, string descripcion, vector<string> tags={});
	void crearPregunta(Sistema* sistema, string imagen, string titulo, string descripcion, vector<string> tags={});
	void agregarRespuestaLikeada(Respuesta* respuesta);
	bool pertenece(int idBuscado);
	int contarRespuestasAceptadas();
	void aceptarSolucion(Pregunta* pregunta, int idRespuesta);
	void crearRespuesta(Pregunta* pregunta,string,string); // Debe llamar a addRespuesta
	void listarInformacion();
};



#endif /* USUARIO_H_ */
