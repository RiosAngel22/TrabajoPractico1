#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Fondo
{
private:
	Sprite fondo;
	Texture Texturas[6];
	String archivos[6] = {
		"Assets/saloon.png",
		"Assets/saloonV1.png",
		"Assets/saloonV2.png",
		"Assets/saloonV3.png",
		"Assets/saloonPuerta.png",
		"Assets/saloonV4.png"
	};


public:
	Fondo();

	Sprite getSprite() {
		return fondo;
	}

	void MeterAlArray();

	void CambiarTextura(int valor);
};

