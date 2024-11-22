#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Musica.h"

using namespace sf;

class Mira
{
private:
	Texture MiraTextura;
	Sprite mira;
	Musica d1;


public:
	Mira();
	void MoverMira(Window &App);
	Sprite ObtenerMira();
	void Disparar();
};

