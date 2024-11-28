#pragma once
#include <SFML/Graphics.hpp>
#include "Entidad.h"
#include "Musica.h"

using namespace sf;

class Villano: public Entidad
{
private:
	Texture texturaVillano;

	//intervalo de tiempo entre que el enemigo aparece y se esconde
	int timer = 3000;

	Musica m1;

public:
	Villano();
	void Disparo();
};

