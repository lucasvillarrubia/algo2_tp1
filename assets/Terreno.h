#ifndef TERRENO_H
#define TERRENO_H

#include "Celula.h"


typedef struct {
	Celula habitantes [MAX_FILAS][MAX_COLUMNAS];
	int celulasVivas;
	int celulasMuertas;
} Terreno;

/*
 * Devuelve un terreno de células completamente inicializado con información inicial necesaria.
 */
void inicializarTerreno (Terreno &terreno);

/*
 * Procedimiento que llama a las funciones necesarias para el cambio de estado de todas las células que
 * requieren una modificación. Actualiza los datos del 'terreno' y establece si hubo cambios o no.
 */
void creacionYGenocidio (Terreno &terreno);

/*
 * Dada una 'célula' inicializada, fiscaliza el estado de sus 8 células vecinas.
 */
int celulaVecinasVivas (Terreno terreno, Coordenada posicion);


#endif /* TERRENO_H */