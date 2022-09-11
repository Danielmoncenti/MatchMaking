#include "Jugador.h"


Jugador::Jugador()
{
	nivel = -1;
	nickName = " ";
}

Jugador::Jugador(std::string _nickName, int _nivel)
{
	nivel = _nivel;
	nickName = _nickName;
}

void Jugador::AutoGen()
{
	

	nivel = rand() % 99 + 1;
	int randomID = rand() % 100000;
	std::string id(std::to_string(randomID));
	nickName = "Jugador" + id;

}

std::string Jugador::GetNickName()
{
	return nickName;
}

int Jugador::GetNivel()
{
	return nivel;
}

Jugador::~Jugador()
{
}
