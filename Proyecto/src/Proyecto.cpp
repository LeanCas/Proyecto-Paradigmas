//============================================================================
// Name        : Proyecto.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Sistema.h"

int main() {
	//mini pruebita xd
	Sistema *sistema = new Sistema();

	sistema->crearUsuario("Sofi", "Cruz", "Argentina", "blasjasbjs","12345fff");
	cout <<"Nombre: " <<sistema->getUsuario(1).getNombre();

	delete sistema;
	return 0;
}
