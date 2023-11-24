/*
 * Activa.h
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */

#ifndef ACTIVA_H_
#define ACTIVA_H_
#include "Estado.h"

class Activa : public Estado {
public:
	Activa();
	~Activa();
	string getTipo();
};

#endif /* ACTIVA_H_ */
