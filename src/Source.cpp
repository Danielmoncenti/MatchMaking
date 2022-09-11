#include<iostream>
#include<string>
#include<vector>
#include<time.h>
#include"Jugador.h"
#include"Matchmaking.h"
#include"Partida.h"
//no se que le ha pasado al visual, pero si no ponia todas las librerias no me las pillaba, se moria el programa
int main() {
	typedef std::chrono::time_point<std::chrono::system_clock> MarcaTemporal;
	typedef std::chrono::duration<double> DiferencialTiempo;


	srand(time(NULL));
	Matchmaking generandomatchmaking(1000);

	MarcaTemporal start = std::chrono::system_clock::now();
	
	
	generandomatchmaking.GenerarPartidas();
	MarcaTemporal end = std::chrono::system_clock::now();
	DiferencialTiempo elapsed = end - start;
	std::cout << "Elapsed time: " << elapsed.count() << "s" << std::endl;
	generandomatchmaking.mostrarjugadoresespera();
	generandomatchmaking.mostrarPartidas();
}