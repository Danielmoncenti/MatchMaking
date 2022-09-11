#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<time.h>
#include"Jugador.h"
const int MAX_JUGADORES = 4;

class Partida
{
private:

	Jugador players[MAX_JUGADORES];
	int numJugadoresEnPartida;

public:
	Partida();
	void AnadeJugador(Jugador& _jugador);
	void mostrarjugadores();
	~Partida();
};

