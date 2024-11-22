#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Boton
{
private:
	Text texto;
	RectangleShape Fondo;

public:
	Boton(String textNuevo, Vector2f Posicion, int tamaño, Color color,Font &fuente);
	Text getBoton();
	RectangleShape getFondo();
	bool EstaArribaDelMouse(Window &App);
	void EfectoHover(Window& App);
};

