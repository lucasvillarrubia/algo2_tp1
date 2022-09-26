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
		solicitarSeleccionInicio (nuevoJuego);
		while (nuevoJuego.estado == JUGANDO) {
			imprimirTerreno (nuevoJuego);
			mostrarEstadisticasJuego (nuevoJuego);
			jugarTurno (nuevoJuego);
			if (nuevoJuego.estado == REINICIADO) {
				nuevoJuego.estado = JUGANDO;
				cout << "REINICIADO" << endl;
				break;
			}
			if (nuevoJuego.estado == CONGELADO) {
				cout << "\nEL juego esta congelado! Ingrese X para terminar el juego o cualquier otra letra para comenzar otra vez." << endl;
				cin >> inputUser;
				if (inputUser == 'X' || inputUser == 'x') { nuevoJuego.estado = TERMINADO; }
				else { nuevoJuego.estado = JUGANDO; }
				break;
			}
		}
	}
	cout << "\nJuego terminado. Nos vemos en otra vida." << endl;
	return 0;
}