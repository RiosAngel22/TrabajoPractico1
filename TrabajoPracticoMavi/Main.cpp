/////Librerías//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Fondo.h"
#include "Mira.h"
#include "Musica.h"
#include "Boton.h"
#include "Menu.h"

#include <iostream>

/////Variables//////
using namespace sf;
using namespace std;

int alto;
int ancho;
int valor = 0;

bool musica = true;

Fondo f1;
Mira m1;
Musica c1;

Text texto;
Font fuente;

Boton* b1;
Menu* m2;
bool menuActivo = true;


int main()
{
	if (!fuente.loadFromFile("Assets/upheavtt.ttf")) {
		cout << "error cargando fuente";
	};

	/////Creamos la ventana//////
	RenderWindow App(VideoMode(800, 600, 32), "Juego de vaqueros");

	c1.playCancion();
	m2 = new Menu(fuente);

	while (App.isOpen())
	{
		Event evt;
		while (App.pollEvent(evt)) {
			switch (evt.type)
			{
			case::Event::Closed:
				App.close();

			case Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Left)) {
					if (menuActivo) {
						int valor = m2->ChequearClicks(App);
						switch (valor) {
						case 0:
							break;
						case 1:
							menuActivo = false;
							break;
						case 2:
							musica = !musica;
							if (musica) {
								c1.playCancion();
							}
							else if (!musica) {
								c1.StopCancion();
							}
							break;
						case 3:
							App.close();
						}
					}

					if (musica) {
						m1.Disparar();
					}
				}
				break;

			case::Event::MouseMoved:
				if (menuActivo) {
					m2->EfectoHover(App);
				}
				break;
			}

				if (menuActivo) {
					App.setMouseCursorVisible(true);
				}
				else if (!menuActivo) {
					App.setMouseCursorVisible(false);
				}
			}

		
			m1.MoverMira(App);
			App.clear();
			if (menuActivo) {
				m2->DibujarMenu(App);
			}
			else{
				App.draw(f1.getSprite());
				App.draw(m1.ObtenerMira());
			}

			App.display();
			}	return 0;}