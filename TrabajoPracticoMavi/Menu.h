#pragma once
#include <SFML/Graphics.hpp>
#include "Boton.h"

using namespace sf;

class Menu
{
private:
	Text Texto1;
	Text Texto2;

	//guardamos como punteros porque no se pueden inicializar afuera de una funcion
	Boton* Iniciar;
	Boton* ActivarSonido;
	Boton* Cerrar;

	RectangleShape Fondo;
public:
	Menu(Font &Fuente);
	void EfectoHover(Window &app);
	int ChequearClicks(Window &app);
	void DibujarMenu(RenderWindow &app);
};

