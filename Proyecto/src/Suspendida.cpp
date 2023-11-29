/*
 * Suspendida.cpp
 *
 *  Created on: 27 nov. 2023
 *      Author: Bruno Casavalle
 */

#include "Suspendida.h"

Suspendida :: Suspendida(){}

Suspendida :: ~Suspendida(){}

string Suspendida :: getTipo(){
	return "Suspendida";
}

Estado* Suspendida :: clonar() const {
	/*Suspendida* suspendida = new Suspendida();
	return suspendida;*/
	return nullptr;
}


