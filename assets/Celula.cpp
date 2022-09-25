#include "Celula.h"



/*
*   PRE: Recibe dos enteros (máximos) positivos.
* 	POST: Devuelve true si la fila y columna de la coordenada recibida se encuentran dentro de los máximos recibidos.
*/
TipoUbicacion ubicarCelula (Coordenada posicion)
{
	TipoUbicacion aux;
	if (!estaCelulaAlBorde (posicion)) {
		return CENTRO;
	}
	else {
		if (posicion.fila == 1) {
			if (posicion.columna == 1) {
				aux = ESQ_SUP_IZQ;
			}
			else if (posicion.columna == 80) {
				aux = ESQ_SUP_DER;
			}
			else {
				aux = BORDE_ARR;
			}
		}
		else if (posicion.fila == 20) {
			if (posicion.columna == 1) {
				aux = ESQ_INF_IZQ;
			}
			else if (posicion.columna == 80) {
				aux = ESQ_INF_DER;
			}
			else {
				aux = BORDE_ABA;
			}
		}
		else if (posicion.columna == 1) {
			aux = BORDE_IZQ;
		}
		else {
			aux = BORDE_DER;
		}
	}
	return aux;
}


Celula inicializarCelula (int fila, int columna)
{
	Celula nuevaCelula;
	nuevaCelula.posicion.fila = fila;
	nuevaCelula.posicion.columna = columna;
	nuevaCelula.estado = MUERTA;
	nuevaCelula.ubicacion = ubicarCelula (nuevaCelula.posicion);
	return nuevaCelula;
}


bool estaCelulaEnVertice (Coordenada posicion)
{
	return (((posicion.fila == 1) && (posicion.columna == 1)) ||
			((posicion.fila == 1) && (posicion.columna == 80)) ||
			((posicion.fila == 20) && (posicion.columna == 1)) ||
			((posicion.fila == 20) && (posicion.columna == 80)));
}


bool estaCelulaAlBorde (Coordenada posicion)
{
	return ((posicion.fila == 1) ||
			(posicion.columna == 1) ||
			(posicion.fila == 20) ||
			(posicion.columna == 80));
}


bool estaDentroRango (int fila, int columna) {
	return ((fila <= MAX_FILAS) && (fila >= 1) && (columna <= MAX_COLUMNAS) && (columna >= 1));
}