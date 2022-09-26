#ifndef CELULA_H
#define CELULA_H

static const int MAX_FILAS = 20;
static const int MAX_COLUMNAS = 80;


enum EstadoCelula {
	VIVA,
	MUERTA
};

typedef struct {
	int fila;
	int columna;
} Coordenada;

typedef struct {
	Coordenada posicion;
	int vecinasVivas;
	EstadoCelula estado;
} Celula;

/*
 * Devuelve una célula con su informacion inicial necesaria cargada.
 */
Celula inicializarCelula (int fila, int columna);

/*
*   Devuelve true si la fila y columna de la coordenada recibida se encuentran dentro de los máximos establecidos.
*/
bool celulaDentroRango (int fila, int columna);


#endif /* CELULA_H */