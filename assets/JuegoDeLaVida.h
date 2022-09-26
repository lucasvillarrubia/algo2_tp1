#ifndef JUEGODELAVIDA_H
#define JUEGODELAVIDA_H

#include "Terreno.h"


enum EstadoJuego {
	JUGANDO,
	CONGELADO,
	REINICIADO,
	TERMINADO
};

typedef struct {
	Terreno terreno;
	EstadoJuego estado;
	int turnoActual;
	int nacimientosPromedio;
	int muertesPromedio;
	int nacidasEnTurno;
	int muertasEnTurno;
	int diasSinCambio;
} Juego;

/*
 * Inicializa el 'juego' en un estado inicial, con las estadisticas en 0, y el terreno con todas las celulas muertas.
 * Luego, pide información de inicialización segun el juego del usuario y devuelve un juego listo para jugar el primer turno.
 */
void inicializarJuego (Juego &juego);

/*
 * -------------------
 */
void solicitarSeleccionInicio (Juego &juego);

/*
 * Muestra por consola el terreno de 'juego' con los datos de su terreno, diferenciando entre celulas vivas y muertas
 * (espacios vacíos). Se actualiza constantemente.
 */
void imprimirTerreno (Juego juegoActual);

/*
 * Muestra por consola el estado de los atributos de los registros del 'juego' y datos recopilados del turno
 * actual comparados con el turno anterior y los promedios del juego en total.
 */
void mostrarEstadisticasJuego (Juego juego);

/*
 * Pide un caracter de entrada al usuario, para proseguir con las acciones correspondientes: terminar,
 * reiniciar el 'juego' u informar que se congeló. 
 */
void jugarTurno (Juego &juego);


#endif /* JUEGODELAVIDA_H */