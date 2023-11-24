/*
 * Pregunta.h
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */

#ifndef PREGUNTA_H_
#define PREGUNTA_H_
#include <iostream>
#include <vector>
#include "Publicacion.h"

using namespace std;

class Pregunta : public Publicacion {
	string titulo;
	string descripcion;
	vector<string> tags;
	vector<Respuesta*> respuestas;
public:
	Pregunta();
	~Pregunta();
	void agregarRespuesta(Respuesta);
	void cambiarEstado(Estado);
	void rankearRespuesta();
	void listarInformacion();
	string getTitulo();
	void listarRespuestas();
private:
	void notificarUsuario(Respuesta);
};




#endif /* PREGUNTA_H_ */
