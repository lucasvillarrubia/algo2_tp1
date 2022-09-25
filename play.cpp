#include <iostream>
#include <cstdlib>
#include "assets/JuegoDeLaVida.h"


using namespace std;


int main () {
	Juego nuevoJuego;
	inicializarJuego (nuevoJuego);
	imprimirTerreno (nuevoJuego);
	
	/*
	while (nuevoJuego.estado == JUGANDO) {
		imprimirTerreno (nuevoJuego);
		mostrarEstadisticasJuego (nuevoJuego);
		jugarTurno (&nuevoJuego);
	}
	if (nuevoJuego.estado == CONGELADO) {
		cout << "El juego está congelado. Presione X para reiniciar." << endl;
		cin >> inputUser;
		cambiarEstadoJuego (&nuevoJuego);
	}
	else if (nuevoJuego.estado == TERMINADO) {
		cout << "Hasta la otra vida." << endl;
		cambiarEstadoJuego (&nuevoJuego);
	}
	*/
	
	return 0;
}