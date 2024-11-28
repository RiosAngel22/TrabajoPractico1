/////Librerías//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <time.h>


#include "Fondo.h"
#include "Mira.h"
#include "Musica.h"
#include "Boton.h"
#include "Menu.h"
#include "villano.h"
#include "Rehen.h"

#include <iostream>

/////Variables//////
using namespace sf;
using namespace std;

//pantalla
int alto;
int ancho;

//puntos
int valor = 0;
int vidas = 3;

bool musica = true;

//clases basicas de funcionalidad
Fondo f1;
Mira m1;
Musica c1;

Text texto;
String textoString;
Font fuente;


Boton* b1;
Menu* m2;
bool menuActivo = true;

Texture* texturaChica;
Texture* texturaGrande;

Villano e1;
Rehen e2;

int random;

int dibujadoActual;

int timer = 3000;

int decidirPersonaje() {
	int valor = rand() % 3 +1 ;
	cout << valor;
	return valor;
}


int main()
{	
	//Cargamos la fuente principal del juego
	if (!fuente.loadFromFile("Assets/upheavtt.ttf")) {
			cout << "error cargando fuente";
	};

	//creamos la interfas de usuario

	texto.setFont(fuente);

	b1 = new Boton("regresar", Vector2f(120, 30), 4, fuente);
	m2 = new Menu(fuente);
	

	//creamos y aleatorizamos posicion
	srand(time(NULL));
	random = rand() % 5;
	e1.moverPersonaje(random);
	e2.moverPersonaje(random);

	e1.setVisibilidad(false);
	e2.setVisibilidad(false);

	dibujadoActual = decidirPersonaje();

	f1.CambiarTextura(0);

	//tocamos cancion por primera vez, luego se manejara desde el menu
	c1.playCancion();



	//Creamos la ventana
	RenderWindow App(VideoMode(800, 800, 32), "Juego de vaqueros");

	while (App.isOpen())
	{
		Event evt;
		while (App.pollEvent(evt)) {
			switch (evt.type)
			{
			case::Event::Closed:
				App.close();

			//chequeos de click
			case Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Left)) {
					//si el menu esta activo, chequeamos cada opcion
					//-------------------------------------------------------------------
					if (menuActivo) {
						int valor = m2->ChequearClicks(App);
						switch (valor) {
						case 0:
							break;
						case 1:
							//Cerramos el menu
							menuActivo = false;
							break;
						case 2:
							//encendemos o apagamos la musica
							musica = !musica;
							if (musica) {
								c1.playCancion();
							}
							else if (!musica) {
								c1.StopCancion();
							}
							break;
						case 3:
							//cerramos el juego
							App.close();
						}
					}
					if (b1->EstaArribaDelMouse(App)) {
						//volvemos al menu
						menuActivo = true;
						//reiniciamos el juego
						valor = 0;
						f1.CambiarTextura(0);
						e1.setVisibilidad(false);
						e1.reiniciarTimer();
						e2.setVisibilidad(false);
						e2.reiniciarTimer();
					}
					//-------------------------------------------------------------------

						//chequeamos colisiones y reiniciamos posicion
					if (e1.detectarColision(m1.ObtenerMira())) {
						if (e1.getVisibilidad()) {

							//si le disparar a un enemigo, aumentamos su punto, randomizamos su posicion, lo escondemos y cerramos las ventanas
							cout << "villano disparado";
							valor++;
							random = rand() % 5;
							e1.setVisibilidad(false);
							e1.reiniciarTimer();

							dibujadoActual = decidirPersonaje();
						}
					}
					if (e2.detectarColision(m1.ObtenerMira())) {
						if (e2.getVisibilidad()) {
							cout << "civil disparado";
							vidas--;
							random = rand() % 5;
							e2.setVisibilidad(false);
							e2.reiniciarTimer();

							dibujadoActual = decidirPersonaje();
						}
					}



					//si clickeamos dispara
					if (musica) {
						m1.Disparar();
					}
				}
				break;


			case::Event::MouseMoved:
				//si el menu esta activo, el menu tiene effecto al hacer hover, sino, el boton de regreso lo tiene
				if (menuActivo) {
					m2->EfectoHover(App);
				}
				else {
					b1->EfectoHover(App);
				}

				//si estamos jugando, escondemos el mouse, si no, lo mostramos
				if (menuActivo) {
					App.setMouseCursorVisible(true);
				}
				else if (!menuActivo) {
					App.setMouseCursorVisible(false);
				}
				break;
		}
	}
			//fin de seccion Input
			//-------------------------------------------------------------

			
			
			//movemos el mouse
			m1.MoverMira(App);


			texto.setString(textoString);
			texto.setScale(1.1, 1.1);
			texto.setPosition(30, 650);
			textoString = "puntaje actual: "+ to_string(valor)+"\n vidas actuales: "+ to_string(vidas);

			App.clear();

			//dibujamos menu
			if (menuActivo) {
				m2->DibujarMenu(App);
			}
			else {
				
				switch (dibujadoActual)
				{
					case 1:
						e2.setVisibilidad(false);
						e2.reiniciarTimer();


						e1.setVisibilidad(true);
						e1.moverPersonaje(random);
						App.draw(e1.getPersonaje());
						f1.CambiarTextura(random + 1);
						e1.reducirTimer();
					
						break;

					case 2:
						e1.setVisibilidad(false);
						e1.reiniciarTimer();

						e2.setVisibilidad(true);
						e2.moverPersonaje(random);
						App.draw(e2.getPersonaje());
						f1.CambiarTextura(random + 1);
						e2.reducirTimer();

						break;
					case 3:
						f1.CambiarTextura(0);
						e1.setVisibilidad(false);
						e2.setVisibilidad(false);
						timer--;

				}
				
				if (e1.TimerTerminado()) {
					e1.Disparo();
					vidas--;
					dibujadoActual = decidirPersonaje();
					e1.setVisibilidad(false);
					e1.reiniciarTimer();
					random = rand() % 5;
				}
				if (e2.TimerTerminado()) {
					dibujadoActual = decidirPersonaje();
					e2.setVisibilidad(false);
					e2.reiniciarTimer();
					random = rand() % 5;
				}
				if (timer == 0) {
					timer = 3000;
					dibujadoActual = decidirPersonaje();
				}


				App.draw(f1.getSprite());
				

				//dibujamos boton de regreso
				App.draw(b1->getFondo());
				App.draw(b1->getBoton());

				//dibujamos el cursor
				App.draw(m1.ObtenerMira());

				//Dibujamos puntos
				App.draw(texto);
			}

			App.display();
			}	return 0;}