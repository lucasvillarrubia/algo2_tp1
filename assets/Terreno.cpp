#include "Terreno.h"



void inicializarTerreno (Terreno &terreno)
{
	for (int i = 0; i < MAX_FILAS; i++) {
		for (int j = 0; j < MAX_COLUMNAS; j++) {
			terreno.habitantes[i][j] = inicializarCelula (i+1, j+1);
		}
	}
	terreno.celulasVivas = 0;
	terreno.celulasMuertas = MAX_FILAS * MAX_COLUMNAS;
}


void creacionYGenocidio (Terreno &terreno)
{
	int screenshotTerreno [MAX_FILAS][MAX_COLUMNAS];
	for (int i = 0; i < MAX_FILAS; i++) {
		for (int j = 0; j < MAX_COLUMNAS; j++) {
			screenshotTerreno [i][j] = celulaVecinasVivas(terreno, terreno.habitantes[i][j].posicion);
		}
	}
	for (int i = 0; i < MAX_FILAS; i++) {
		for (int j = 0; j < MAX_COLUMNAS; j++) {
			if ((terreno.habitantes[i][j].estado == MUERTA) && (screenshotTerreno[i][j] == 3)) {
				terreno.habitantes[i][j].estado = VIVA;
				terreno.celulasVivas++;
			}
			else if (terreno.habitantes[i][j].estado == VIVA && (screenshotTerreno[i][j] < 2 || screenshotTerreno[i][j] > 3)) {
				terreno.habitantes[i][j].estado = MUERTA;
				terreno.celulasMuertas++;
			}
		}
	}
}


int celulaVecinasVivas (Terreno terreno, Coordenada posicion) 
{
	int contadorVecinasVivas = 0;
	for (int i = (posicion.fila-1); i < (posicion.fila+1); i++) {
		for (int j = (posicion.columna-1); j < (posicion.columna+1); j++) {
			if (i == posicion.fila && j == posicion.columna)
				continue;
			if (celulaDentroRango (i, j)) {
				if (terreno.habitantes[i-1][j-1].estado == VIVA) {
					contadorVecinasVivas++;
				}
			}
		}
	}
	return contadorVecinasVivas;
}