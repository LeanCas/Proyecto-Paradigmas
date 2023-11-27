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
#include "Respuesta.h"
#include "Estado.h"

using namespace std;

class Pregunta : public Publicacion {
	string titulo;
	string descripcion;
	vector<string> tags;
	vector<Respuesta*> respuestas;

public:
	Pregunta();
	Pregunta(int tipo=1, string imagen="", Fecha fecha=Fecha(), Usuario* usuario=nullptr, string titulo="", string descripcion="", vector<string> tags={}, vector<Respuesta*> respuestas={});
	Pregunta(const Pregunta& p);
	// Constructor que acepta una Publicacion
	Pregunta(const Publicacion& publicacion);
	~Pregunta();
	void agregarRespuesta(Respuesta);
	void cambiarEstado(Estado*);
	void rankearRespuesta();
	void listarInformacion() override;
	string getTitulo();
	void listarRespuestas();

private:
	void notificarUsuario(Respuesta);
};


#endif /* PREGUNTA_H_ */
