/*
 * Fecha.cpp
 */

#include "Fecha.h"
#include <sstream>
#include <ctime>
#include <iostream>
using namespace std;

Fecha::Fecha() {
	setFechaActual();
	//cout<<"Constructor de Fecha "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
Fecha::Fecha(short int d, short int m, short int a) {
	setFecha(d, m, a);
	//cout<<"Constructor de Fecha "<<dia<<"/"<<mes<<"/"<<anio<<endl;

}
Fecha::Fecha(const Fecha &f) :
	dia(f.dia), mes(f.mes), anio(f.anio) {
	//cout<<"Constructor de Fecha "<<dia<<"/"<<mes<<"/"<<anio<<endl;

}

void Fecha::setFechaActual(void) {
	struct tm *ptr;
	time_t sec;

	time(&sec);
	ptr = localtime(&sec);
	dia = (short) ptr->tm_mday;
	mes = (short) ptr->tm_mon + 1;
	anio = (short) ptr->tm_year + 1900;
}

void Fecha::setFecha(const short d, const short m, const short a) {
	dia = d;
	mes = m;
	anio = a;
	if(!esAnioValido() || !esMesValido() || !esDiaValido()){
		setFechaActual();
	}
}

bool Fecha::esAnioValido() const {
	return (anio > 0);
}
bool Fecha::esMesValido() const {
	return (mes >= 1 && mes <= 12);
}
bool Fecha::esDiaValido() const {
	return (dia >= 1 && dia <= diasEnMes(mes));
}

short Fecha::diasEnMes(const short m) const{
	short cantidadDias = 0;
	switch (m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			cantidadDias = 31;
			break;
		case 2:
			if (esAnioBisiesto()) {
				cantidadDias = 29;
			} else {
				cantidadDias = 28;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			cantidadDias = 30;
			break;
	}
	return cantidadDias;
}


bool Fecha::esAnioBisiesto() const {
	return ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0);
}


short Fecha::getDia() const {
	return dia;
}
short Fecha::getMes() const {
	return mes;
}
short Fecha::getAnio() const {
	return anio;
}
string Fecha::toString() {
	stringstream flujo;
	flujo << this->dia <<"/"<< this->mes <<"/"<< this->anio;
	return string(flujo.str());
}


//Devuelve la diferencia en a�os de 2 fechas
int operator-(Fecha fecha1, Fecha fecha2){
	int dif = fecha1.getAnio() - fecha2.getAnio();
	if( fecha1.getMes()< fecha2.getMes() || (fecha1.getMes()==fecha2.getMes() && fecha1.getDia()< fecha2.getDia()))
		dif=dif-1;
	return dif;
}
//Devuelve true si fecha1 es menor que fecha2
bool operator<(Fecha fecha1, Fecha fecha2){
	bool valor=true;
	if(fecha1.getAnio() > fecha2.getAnio())
		valor =false;
	else
		if(fecha1.getAnio() == fecha2.getAnio())
			if(fecha1.getMes() > fecha2.getMes())
				valor= false;
			else
				if(fecha1.getMes() == fecha2.getMes())
					if(fecha1.getDia() > fecha2.getDia())
						valor= false;
	return valor;

}
