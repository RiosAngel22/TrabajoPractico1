#pragma once
#include <SFML/Graphics.hpp>
#include "Boton.h"

using namespace sf;

class PantallaFinal
{
private:
	Texture TexturaVictoria;
	Texture TexturaDerrota;
	Sprite Pantalla;

	Text texto;
	Boton* regreso;

public:
	PantallaFinal(Font &fuente);
	void setVictoria(bool victoria);
	void setTexto(String textoInput);
	void DibujarPantalla(RenderWindow &App);
	bool regresoPrecionado(Window &App);
	void efectoHover(Window& app);
};

