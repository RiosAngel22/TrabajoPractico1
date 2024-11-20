#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Mira
{
private:
	Texture MiraTextura;
	Sprite mira;

public:
	Mira();
	void MoverMira(Window &App);
	Sprite ObtenerMira();
};

