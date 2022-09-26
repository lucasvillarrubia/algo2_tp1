#include "JuegoDeLaVida.h"
#include <iostream>
#include <cstdlib>

using namespace std;


void imprimirAvisoError () {
	cout << "\nEl termino ingresado no esta comprendido por las directivas o limites brindados por el juego." << endl;
	cout << "Por favor, ingrese otra vez su respuesta:" << endl;
}


void solicitarSeleccionInicio (Juego &juego)
{
	int inputUser = 0, fila = 0, columna = 0;
	cout << "\nPara iniciar el juego, debera ingresar posiciones del terreno en el cual desee celulas vivas (no mas de " << MAX_FILAS * MAX_COLUMNAS << ")" << endl;
	for (int i = 0; i < (MAX_FILAS * MAX_COLUMNAS); i++) {
		cout << endl << "Ingrese la primera coordenada (fila) para una celula viva:" << endl;
		cout << "(la respuesta ingresada debe ser un numero entero del 1 al " << MAX_FILAS << ")" << endl;
		cout << "PARA TERMINAR LA CARGA DEL TERRENO INGRESE 0" << endl;
		cin >> inputUser;
		if (inputUser == 0)
			break;
		while (inputUser > MAX_FILAS || inputUser < 1) {
			imprimirAvisoError ();
			cin >> inputUser;
		}
		fila = inputUser;
		cout << endl << "Ahora ingrese la segunda coordenada (columna) para una celula viva" << endl;
		cout << "(la respuesta ingresada debe ser un numero entero del 1 al " << MAX_COLUMNAS << ")" << endl;
		cin >> inputUser;
		while (inputUser > MAX_COLUMNAS || inputUser < 1) {
			imprimirAvisoError ();
			cin >> inputUser;
		}
		columna = inputUser;
		juego.terreno.habitantes[fila-1][columna-1].estado = VIVA;
		juego.terreno.celulasVivas++;
		juego.terreno.celulasMuertas--;
	}
}


void inicializarJuego (Juego &juego)
{
	inicializarTerreno(juego.terreno);
	juego.turnoActual = 0;
	juego.nacimientosPromedio = 0;
	juego.muertesPromedio = 0;
	juego.nacidasEnTurno = 0;
	juego.muertasEnTurno = 0;
	juego.diasSinCambio = 0;
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


void mostrarEstadisticasJuego (Juego juego)
{
	cout << "Days without freezing: " << juego.turnoActual << endl;
	cout << "\nEl turno anterior se contabilizaron:" << endl;
	cout << "\tNacimientos: " << juego.nacidasEnTurno << endl;
	cout << "\tMuertes: " << juego.muertasEnTurno << endl;
	cout << "\nPromedio total de nacimientos: " << juego.nacimientosPromedio << endl;
	cout << "Promedio total de muertes: " << juego.muertesPromedio << endl;
}


void actualizarJuego (Juego &juego)
{
	if (juego.diasSinCambio >= 2) {
		juego.estado = CONGELADO;
		inicializarJuego (juego);
		return;
	}
	int nacimientosTotales = 0, muertesTotales = 0;
	int vivasAntes = juego.terreno.celulasVivas, muertasAntes = juego.terreno.celulasMuertas;
	juego.turnoActual++;
	creacionYGenocidio (juego.terreno);
	juego.nacidasEnTurno = juego.terreno.celulasVivas - vivasAntes;
	juego.muertasEnTurno = juego.terreno.celulasMuertas - muertasAntes;
	nacimientosTotales += juego.nacidasEnTurno;
	juego.nacimientosPromedio = (nacimientosTotales / juego.turnoActual);
	muertesTotales += juego.muertasEnTurno;
	juego.muertesPromedio = (muertesTotales / juego.turnoActual);
	if (juego.nacidasEnTurno == 0 && juego.muertasEnTurno == 0)
		juego.diasSinCambio++;
}


void jugarTurno (Juego &juego)
{
	char inputUser;
	cout << "Ingrese una opcion para continuar:" << endl;
	cout << "\tR para REINICIAR" << endl;
	cout << "\tX para TERMINAR" << endl;
	cout << "\tcualquier otra letra para CONTINUAR" << endl;
	cin >> inputUser;
	switch (inputUser) {
		case 'x':
			juego.estado = TERMINADO;
			break;
		case 'r':
			juego.estado = REINICIADO;
			inicializarJuego (juego);
			break;
		default:
			actualizarJuego (juego);
	}
}