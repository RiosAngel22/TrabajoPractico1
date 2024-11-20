/////Librerías//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Fondo.h"
#include "Mira.h"
#include <iostream>

/////Variables//////
using namespace sf;
using namespace std;

int alto;
int ancho;
int valor = 0;

Fondo f1;
Mira m1;

int main()
{
	/////Creamos la ventana//////
	RenderWindow App(VideoMode(800, 600, 32), "ventana");
	App.setMouseCursorVisible(false);

	while (App.isOpen())
	{
		m1.MoverMira(App);
		App.clear();
		App.draw(f1.getSprite());
		App.draw(m1.ObtenerMira());
		App.display();
	}
	return 0;}