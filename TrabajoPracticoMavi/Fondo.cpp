#include "Fondo.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Fondo::Fondo() {
	MeterAlArray();
	CambiarTextura(0);
}

void Fondo::MeterAlArray() {
	for (int i = 0; i <= 5; i++)
	{
		Texturas[i].loadFromFile(archivos[i]);
	}
}

void Fondo::CambiarTextura(int valor) {
	if ((valor >= 0) and (valor <= 5)) {
		fondo.setTexture(Texturas[valor]);
	}
	
}
