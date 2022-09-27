#include <iostream>
#include "assets/JuegoDeLaVida.h"

using namespace std;

int main () {
	Juego nuevoJuego;
	nuevoJuego.estado = JUGANDO;
	inicializarJuego (nuevoJuego);
	while (nuevoJuego.estado != TERMINADO) {
		nuevoJuego.estado = JUGANDO;
		solicitarSeleccionInicio (nuevoJuego);
		while (nuevoJuego.estado == JUGANDO) {
			imprimirTerreno (nuevoJuego);
			mostrarEstadisticasJuego (nuevoJuego);
			jugarTurno (nuevoJuego);
		}
	}
	return 0;
}