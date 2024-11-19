/////Librerías//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Fondo.h"

/////Variables//////
using namespace sf;
using namespace std;

int alto;
int ancho;
int valor = 0;

Fondo f1;

int main()
{
	/////Creamos la ventana//////
	RenderWindow App(VideoMode(800, 600, 32), "ventana");

	while (App.isOpen())
	{
		
		App.clear();
		App.draw(f1.getSprite());
		App.display();
	}
	return 0;}