#pragma once
#include <SFML/Graphics.hpp>
#include "Entidad.h"
#include "Musica.h"

using namespace sf;

class Rehen: public Entidad
{
private:
	Texture RehenTextura;
	int timer = 2500;
	Musica m1;

public:
	Rehen();
	void Gritar();
};

