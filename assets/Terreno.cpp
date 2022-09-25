#include "Terreno.h"


Terreno inicializarTerreno ()
{
	Terreno nuevo;
	for (int i = 0; i < MAX_FILAS; i++) {
		for (int j = 0; j < MAX_COLUMNAS; j++) {
			nuevo.habitantes[i][j] = inicializarCelula (i+1, j+1);
		}
	}
	nuevo.celulasVivas = 0;
	nuevo.celulasMuertas = MAX_FILAS * MAX_COLUMNAS;
	return nuevo;
}


void diagnosticarCelula (Celula celula, int vecinasVivas)
{
	if ((celula.estado == MUERTA) && (vecinasVivas == 3)) {
		celula.estado = VIVA;
		return;
	}
	else if ((celula.estado == VIVA) && ((vecinasVivas < 2) || (vecinasVivas > 3))) {
		celula.estado = MUERTA;
	}
}


void creacionYGenocidio (Terreno terreno)
{
	int screenshotTerreno [MAX_FILAS][MAX_COLUMNAS];
	for (int i = 0; i < MAX_FILAS; i++) {
		for (int j = 0; j < MAX_COLUMNAS; j++) {
			screenshotTerreno [i][j] = celulaVecinasVivas(terreno, terreno.habitantes[i][j].posicion);
		}
	}

	for (int i = 0; i < MAX_FILAS; i++) {
		for (int j = 0; j < MAX_COLUMNAS; j++) {
			diagnosticarCelula (terreno.habitantes[i][j], screenshotTerreno[i][j]);
		}
	}
}


int celulaVecinasVivas (Terreno terreno, Coordenada posicion)
{
	int contadorVecinasVivas = 0;
	if (estaDentroRango (posicion.fila+1, posicion.columna)) {
		if (terreno.habitantes[posicion.fila+1][posicion.columna].estado == VIVA)
			contadorVecinasVivas++;
	}
	if (estaDentroRango (posicion.fila, posicion.columna+1)) {
		if (terreno.habitantes[posicion.fila][posicion.columna+1].estado == VIVA)
			contadorVecinasVivas++;
	}
	if (estaDentroRango (posicion.fila-1, posicion.columna)) {
		if (terreno.habitantes[posicion.fila-1][posicion.columna].estado == VIVA)
			contadorVecinasVivas++;
	}
	if (estaDentroRango (posicion.fila, posicion.columna-1)) {
		if (terreno.habitantes[posicion.fila][posicion.columna-1].estado == VIVA)
			contadorVecinasVivas++;
	}
	if (estaDentroRango (posicion.fila+1, posicion.columna+1)) {
		if (terreno.habitantes[posicion.fila+1][posicion.columna+1].estado == VIVA)
			contadorVecinasVivas++;
	}
	if (estaDentroRango (posicion.fila+1, posicion.columna-1)) {
		if (terreno.habitantes[posicion.fila+1][posicion.columna-1].estado == VIVA)
			contadorVecinasVivas++;
	}
	if (estaDentroRango (posicion.fila-1, posicion.columna+1)) {
		if (terreno.habitantes[posicion.fila-1][posicion.columna+1].estado == VIVA)
			contadorVecinasVivas++;
	}
	if (estaDentroRango (posicion.fila-1, posicion.columna-1)) {
		if (terreno.habitantes[posicion.fila-1][posicion.columna-1].estado == VIVA)
			contadorVecinasVivas++;
	}
	return contadorVecinasVivas;
}
