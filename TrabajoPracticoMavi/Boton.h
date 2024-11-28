#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Boton
{
private:
	Text texto;
	RectangleShape Fondo;
	Color ColorDefault;
	Color DefaultFondo;

public:
	Boton(String textNuevo, Vector2f Posicion, int tama�o,Font &fuente,Color ColorPrimario,Color ColorSecundario);
	Text getBoton();
	RectangleShape getFondo();
	bool EstaArribaDelMouse(Window &App);
	void EfectoHover(Window& App);
};

