#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<time.h>
#include "Partida.h"
#include"Jugador.h"
#include<chrono>

class Matchmaking
{
private:
	std::vector<Jugador> jugadoresEnEspera;
	std::vector<Partida> partidas;


	void MergeSort(std::vector<Jugador>&_ordenar);

public:

	Matchmaking();
	~Matchmaking();
	Matchmaking(int _numJugadores);
	void GenerarPartidas();
	void mostrarjugadoresespera();
	void mostrarPartidas();

};

