#include"Matchmaking.h"

void Matchmaking::MergeSort(std::vector<Jugador>&_ordenar)
{
   
        const int size = _ordenar.size();
        int halfsize = size / 2;
        int halfsizeplusone = halfsize + 1;

        if (size == 1) {
            return;
        }

        std::vector<Jugador> sublista1, sublista2;

        if (size % 2 == 0) {
            sublista1.resize(halfsize);
            sublista2.resize(halfsize);
        }
        else {
            sublista1.resize(halfsize);
            sublista2.resize(halfsizeplusone);
        }

        int sub1 = sublista1.size();
        int sub2 = sublista2.size();

        for (size_t i = 0; i < sub1; i++) {
            sublista1[i] = _ordenar[i];
        }

        for (size_t i = sub1, j = 0; i < size; i++, j++) {
            sublista2[j] = _ordenar[i];
        }

        MergeSort(sublista1);
        MergeSort(sublista2);

        int indice_Sub1 = 0;
        int indice_Sub2 = 0;


        for (size_t i = 0; i < size; i++)
        {
            if (indice_Sub1 == sub1) {
                _ordenar[i] = sublista2[indice_Sub2];
                indice_Sub2++;
            }
            else if (indice_Sub2 == sub2) {
                _ordenar[i] = sublista1[indice_Sub1];
                indice_Sub1++;
            }
            else if (sublista1[indice_Sub1].GetNivel() >= sublista2[indice_Sub2].GetNivel()) {
                _ordenar[i] = sublista2[indice_Sub2];
                indice_Sub2++;
            }
            else {
                _ordenar[i] = sublista1[indice_Sub1];
                indice_Sub1++;
            }
        }
       
}

Matchmaking::Matchmaking()
{
}

Matchmaking::~Matchmaking()
{
}

Matchmaking::Matchmaking(int _numJugadores)
{
	jugadoresEnEspera.resize(_numJugadores);
	for (int i = 0; i < _numJugadores; i++) {
		
		Jugador newplayer;
		newplayer.AutoGen();
		jugadoresEnEspera[i] = newplayer;
	}
   
    MergeSort(jugadoresEnEspera);



}

void Matchmaking::GenerarPartidas()
{
	partidas.resize((jugadoresEnEspera.size()/4));
	int tamañopartidas = partidas.size();
	

		for (int i = 0; i < tamañopartidas; i++) {
			for (int j=0; j < 4; j++) {
				partidas[i].AnadeJugador(jugadoresEnEspera[j]);
                if (j == 3) {
                    jugadoresEnEspera.erase(jugadoresEnEspera.begin(), jugadoresEnEspera.begin() + 4);
                }
				
			}
		}

}

void Matchmaking::mostrarjugadoresespera()
{
    std::cout << "Jugadores en Espera: " << std::endl;
    for (int i = 0; i < jugadoresEnEspera.size(); i++) {
        
        std::cout << jugadoresEnEspera[i].GetNickName() << " ";
        std::cout << jugadoresEnEspera[i].GetNivel() << std::endl;
    }
}

void Matchmaking::mostrarPartidas()
{
    std::cout << "<<<Partidas>>>" << std::endl;
    for (int i = 0; i < partidas.size(); i++) {
        std::cout << "Partida " << i << " :" << std::endl;
        partidas[i].mostrarjugadores();
    }
}
