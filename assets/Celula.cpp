#include "Celula.h"



Celula inicializarCelula (int fila, int columna)
{
	Celula nuevaCelula;
	nuevaCelula.posicion.fila = fila;
	nuevaCelula.posicion.columna = columna;
	nuevaCelula.estado = MUERTA;
	return nuevaCelula;
}


bool celulaDentroRango (int fila, int columna) {
	return ((fila <= MAX_FILAS) && (fila >= 1) && (columna <= MAX_COLUMNAS) && (columna >= 1));
}


