/*
 * Inactiva.h
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */

#ifndef INACTIVA_H_
#define INACTIVA_H_
#include "Estado.h"

class Inactiva : public Estado {
public:
	Inactiva();
	~Inactiva();
	string getTipo();
};

#endif /* INACTIVA_H_ */
