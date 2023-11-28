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
	Estado* estado;

public:
	Pregunta();
	Pregunta(string imagen="", Fecha fecha=Fecha(), Usuario* usuario=nullptr, string titulo="", string descripcion="", vector<string> tags={}, vector<Respuesta*> respuestas={});
	Pregunta(const Pregunta& p);
	~Pregunta();
	void agregarRespuesta(Respuesta* respuesta);
	Estado* getEstado();
	void cambiarEstado(Estado* nuevoEstado);
	void rankearRespuesta();
	void listarInformacion() override;
	string getTitulo();
	void listarRespuestas();
	vector<Respuesta*> getRespuestas();
	void notificarUsuario(Respuesta*);
};


#endif /* PREGUNTA_H_ */
