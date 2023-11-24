/*
 * Estado.h
 *
 *  Created on: 24 nov. 2023
 *      Author: Alumno
 */

#ifndef ESTADO_H_
#define ESTADO_H_
#include <iostream>

using namespace std;

class Estado {
	static int autonumerico;
protected:
	int id;
	string tipo;
public:
	Estado();
	virtual ~Estado();
	virtual string getTipo() = 0;
};




#endif /* ESTADO_H_ */
