#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<time.h>
class Jugador
{
private:
	std::string nickName;
	int nivel;

public:

	Jugador();
	Jugador(std::string _nickName, int _nivel);
	void AutoGen();
	std::string GetNickName();
	int GetNivel();

	~Jugador();

};
