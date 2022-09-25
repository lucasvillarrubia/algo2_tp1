#include "JuegoDeLaVida.h"
#include <iostream>
#include <cstdlib>


using namespace std;


bool esInputValido (int ingresado, char tipoInput)
{
	if (tipoInput == 'C') {
		return (ingresado <= MAX_COLUMNAS && ingresado > 0);
	}
	else {
		return (ingresado <= MAX_FILAS && ingresado > 0);
	}
}


void imprimirAvisoError () {
	cout << "El término ingresado no está comprendido por las directivas o límites brindados por el juego." << endl;
	cout << "Por favor, ingrese otra vez su respuesta:" << endl;
}


void solicitarSeleccionInicio (Juego &juego)
{
	char inicioUser;
	int inputUser = 0, fila = 0, columna = 0;
	cout << "Para iniciar el juego, deberá ingresar posiciones del terreno en el cual desee células vivas" << endl;
	cout << "Presione P para comenzar el juego con el terreno vacío o;" << endl;
	cout << "Presione cualquier otra letra para cargar el terreno" << endl;
	cin >> inicioUser;
	if (inicioUser == 'P' || inicioUser == 'p')
		return;

	for (int i = 0; i < (MAX_FILAS * MAX_COLUMNAS); i++) {
		cout << endl << "Ingrese la primera coordenada (fila) para una célula viva:" << endl;
		cout << "(la respuesta ingresada debe ser un número entero del 1 al " << MAX_FILAS << ")" << endl;
		cout << "PARA TERMINAR LA CARGA DEL TERRENO PRESIONE 0" << endl;
		cin >> inputUser;
		if (inputUser == 0)
			break;
		while (!esInputValido(inputUser, 'F')) {
			imprimirAvisoError ();
			cin >> inputUser;
		}
		fila = inputUser;
		cout << endl << "Ahora ingrese la segunda coordenada (columna) para una célula viva" << endl;
		cout << "(la respuesta ingresada debe ser un número entero del 1 al " << MAX_COLUMNAS << ")" << endl;
		cout << "PARA TERMINAR LA CARGA DEL TERRENO PRESIONE 0 (SE ASIGNARÁ UN NÚMERO DE COLUMNA ALEATORIO)" << endl;
		cin >> inputUser;
		if (inputUser == 0) {
			columna = rand() % 80 + 1;
			juego.terreno.habitantes[fila-1][columna-1].estado = VIVA;
			break;
		}
		while (!esInputValido(inputUser, 'C')) {
			imprimirAvisoError ();
			cin >> inputUser;
		}
		columna = inputUser;
		juego.terreno.habitantes[fila-1][columna-1].estado = VIVA;
	}
}


void inicializarJuego (Juego &juego)
{
	Juego nuevo;
	nuevo.terreno = inicializarTerreno();
	nuevo.estado = JUGANDO;
	nuevo.turnoActual = 0;
	nuevo.natalidadEnJuego = 0;
	nuevo.mortalidadEnJuego = 0;
	nuevo.nacidasEnTurno = 0;
	nuevo.muertasEnTurno = 0;
	solicitarSeleccionInicio (nuevo);
	juego = nuevo;
}


void imprimirTerreno (Juego juegoActual)
{
	cout << endl;
	for (int i = 0; i < MAX_FILAS; i++) {
		cout << " " << i+1 << "  ";
		if (i < 9)
			cout << " ";
		for (int j = 0; j < MAX_COLUMNAS; j++) {
			if (juegoActual.terreno.habitantes[i][j].estado == VIVA) {
				cout << "1 ";
			}
			else {
				cout << "0 ";
			}
		}
		cout << endl;
	}
	cout << endl;
}


/*
int cambiarEstadoJuego (Juego * juego)
{
	h
}


void mostrarEstadisticasJuego (Juego juego)
{
	h
}


void jugarTurno (Juego * juego)
{
	h
}
*/
