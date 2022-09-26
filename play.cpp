#include <iostream>
#include <cstdlib>
#include "assets/JuegoDeLaVida.h"

using namespace std;

int main ()
{
	char inputUser;
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
	cout << "\nJuego terminado. Nos vemos en otra vida." << endl;
	return 0;
}
