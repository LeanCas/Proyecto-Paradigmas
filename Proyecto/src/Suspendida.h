/*
 * Suspendida.h
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */

#ifndef SUSPENDIDA_H_
#define SUSPENDIDA_H_
#include "Estado.h"

class Suspendida : public Estado {
public:
	Suspendida();
	~Suspendida();
	string getTipo();
	Estado* clonar() const override;
};

#endif /* SUSPENDIDA_H_ */
