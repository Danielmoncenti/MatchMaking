#include "Partida.h"
Partida::Partida()
{
	numJugadoresEnPartida = 0;
}

void Partida::AnadeJugador(Jugador& _jugador)
{
	
		players[numJugadoresEnPartida] = _jugador;
		numJugadoresEnPartida++;

}

void Partida::mostrarjugadores()
{

	for (int i = 0; i < MAX_JUGADORES; i++) {
		std::cout << players[i].GetNickName() << " Nivel:" << players[i].GetNivel() << std::endl;
	}
}

Partida::~Partida()
{
}
