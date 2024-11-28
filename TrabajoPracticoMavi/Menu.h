#pragma once
#include <SFML/Graphics.hpp>
#include "Boton.h"

using namespace sf;

class Menu
{
private:
	Text Texto1;
	Text Texto2;
	Texture Fondo;
	Sprite FondoSprite;

	//guardamos como punteros porque no se pueden inicializar afuera de una funcion
	Boton* Iniciar;
	Boton* ActivarSonido;
	Boton* Cerrar;

public:
	Menu(Font &Fuente);
	void EfectoHover(Window &app);
	int ChequearClicks(Window &app);
	void DibujarMenu(RenderWindow &app);
};

