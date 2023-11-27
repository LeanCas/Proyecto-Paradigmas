/*
 * Estado.cpp
 *
 *  Created on: 27 nov. 2023
 *      Author: chavi
 */

#include "Estado.h"

int Estado::autonumerico = 0;

Estado::Estado(): id(++autonumerico) {}

string Estado::getTipo() {
	return tipo;
}
