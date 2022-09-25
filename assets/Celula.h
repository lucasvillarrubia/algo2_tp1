#ifndef CELULA_H
#define CELULA_H

static const int MAX_FILAS = 20;
static const int MAX_COLUMNAS = 80;


enum EstadoCelula {
	VIVA,
	MUERTA
};

enum TipoUbicacion {
	BORDE_IZQ,
	BORDE_DER,
	BORDE_ARR,
	BORDE_ABA,
	ESQ_SUP_IZQ,
	ESQ_SUP_DER,
	ESQ_INF_IZQ,
	ESQ_INF_DER,
	CENTRO
};

typedef struct {
	int fila;
	int columna;
} Coordenada;

typedef struct {
	Coordenada posicion;
	int vecinasVivas;
	EstadoCelula estado;
	TipoUbicacion ubicacion;
} Celula;


/*
 * Devuelve una célula con su informacion inicial necesaria cargada.
 */
Celula inicializarCelula (int fila, int columna);

/*
 * Indica si la 'célula' recibida se encuentra en alguna de las esquinas según los máximos y mínimos de filas y columnas.
 */
bool estaCelulaEnVertice (Coordenada posicion);

/*
 * Indica si la 'célula' recibida se encuentra en alguno de los máximos o mínimos de filas o columnas.
 */
bool estaCelulaAlBorde (Coordenada posicion);

/*
*   Devuelve true si la fila y columna de la coordenada recibida se encuentran dentro de los máximos establecidos.
*/
bool estaDentroRango (int fila, int columna);



#endif /* CELULA_H */