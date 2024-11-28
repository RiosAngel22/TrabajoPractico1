/////Librerías//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>

//utilidades
#include "Fondo.h"
#include "Mira.h"
#include "Musica.h"
#include "Boton.h"
#include "Menu.h"
#include "PantallaFinal.h"

//personajes
#include "villano.h"
#include "Rehen.h"



/////Variables//////
using namespace sf;
using namespace std;

//pantalla
int alto;
int ancho;

//puntos
int valor = 0;
int vidas = 3;
int vidasCivilesPerdidas;
int puntajeFinal;

bool musica = true;

//clases basicas de funcionalidad
Fondo f1;
Mira m1;
Musica c1;


//interfaz de usuario
Text texto;
String textoString;
Font fuente;
Boton* b1;
Menu* m2;
PantallaFinal* p1;
bool menuActivo = true;
bool pantallaFinalActiva;

//sin esta variable, la melodia de victoria o derrota se repite infinitamente
bool melodiaFinalSonando = false;

//personajes
Villano e1;
Rehen e2;

//posicion aleatoria
int random;

//personaje actual
int dibujadoActual;

//tiempo sin mostrar un personaje
int timer = 1000;

//decide el siguiente personaje en aparecer
int decidirPersonaje() {
	int valor = rand() % 3 +1 ;
	return valor;
}

//restablecemos todos los valores
void reiniciarPartida() {
	//reiniciamos el juego
	valor = 0;
	vidas = 3;
	vidasCivilesPerdidas = 0;
	puntajeFinal = 0;

	f1.CambiarTextura(0);
	e1.setVisibilidad(false);
	e1.reiniciarTimer();
	e2.setVisibilidad(false);
	e2.reiniciarTimer();
	melodiaFinalSonando = false;

}

int main()
{	
	//Cargamos la fuente principal del juego
	if (!fuente.loadFromFile("Assets/upheavtt.ttf")) {
			cout << "error cargando fuente";
	};

	//creamos la interfas de usuario

	texto.setFont(fuente);

	b1 = new Boton("regresar", Vector2f(120, 30), 4, fuente,Color::White,Color::Black);
	m2 = new Menu(fuente);
	p1 = new PantallaFinal(fuente);

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

	//style close inpide que el usuario agrande la pantalla
	RenderWindow App(VideoMode(800, 800, 32), "El deber de un sheriff - Angel Rios",Style::Close);

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
					//-------------------------------------------------------------------

					//boton de regreso al menu
					if (pantallaFinalActiva) {
						if (p1->regresoPrecionado(App)) {
							reiniciarPartida();
							pantallaFinalActiva = false;
							c1.playCancion();
						}
					}
					
					//boton de regreso al juego
					if (b1->EstaArribaDelMouse(App)) {
						reiniciarPartida();
						menuActivo = true;
					}
					
					//chequeamos colisiones y reiniciamos posicion
					if (e1.detectarColision(m1.ObtenerMira())) {
						if (e1.getVisibilidad()) {

							//si le disparar a un enemigo, aumentamos su punto, randomizamos su posicion, lo escondemos y suena un sonido feliz
							valor++;
							random = rand() % 5;
							e1.setVisibilidad(false);
							e1.reiniciarTimer();
							if (musica) {
								e1.DisparoAVillano();
							}
							

							dibujadoActual = decidirPersonaje();
						}
					}
					if (e2.detectarColision(m1.ObtenerMira())) {
						if (e2.getVisibilidad()) {
							//si le disparamos a la rehen, perdemos una vida, randomizamos su posicion, la escondemos y suena un sonido dolorozo 
							vidas--;
							random = rand() % 5;
							e2.setVisibilidad(false);
							e2.reiniciarTimer();

							vidasCivilesPerdidas++;

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
				//si el menu esta activo,los botones tienen effecto al hacer hover
				if (menuActivo) {
					m2->EfectoHover(App);
				}
				else if (pantallaFinalActiva) {
					p1->efectoHover(App);
				}
				else {
					b1->EfectoHover(App);
				}

				//si estamos jugando, escondemos el mouse, si no, lo mostramos
				if ((menuActivo) or (pantallaFinalActiva)){
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

			//cargamos el texto de la interfaz
			texto.setString(textoString);
			texto.setScale(1.1, 1.1);
			texto.setFillColor(Color(0xbe8b56ff));
			texto.setPosition(30, 650);
			textoString = "puntaje actual: "+ to_string(valor)+"\n vidas actuales: "+ to_string(vidas)+"\n Trabajo MAVI";

			//aparecemos la pantalla final y tocamos una melodia correspondiente
			if ((valor >= 10) or (vidas <= 0)) {

				pantallaFinalActiva = true;
				puntajeFinal = valor - (vidasCivilesPerdidas * 2);
				
				c1.StopCancion();
				if (valor >= 10) {
					p1->setVictoria(true);

					//usamos la variable melodia sonando para evitar repeticion
					if ((!melodiaFinalSonando) and (musica)) {
						c1.playVictoria();
						melodiaFinalSonando = true;
					}
					
				}
				else if (vidas <= 0) {
					p1->setVictoria(false);
					if ((!melodiaFinalSonando) and (musica)) {
						c1.playDerrota();
						melodiaFinalSonando = true;
					}
				}
			}



			p1->setTexto("enemigos eliminados:   \n  " + to_string(valor) + "\n vidas civiles perdidas:   \n  " + to_string(vidasCivilesPerdidas) +"\n puntaje final : \n  " + to_string(puntajeFinal));

			App.clear();

			//dibujamos menu
			if (menuActivo) {
				m2->DibujarMenu(App);
			}
			else if (pantallaFinalActiva) {
				p1->DibujarPantalla(App);
			}
			else {
				
				switch (dibujadoActual)
				{
					case 1:
						//Ocultamos al enemigo, mostramos al rehen y lo movemos, reducimos su timer y abrimos su ventana
						e2.setVisibilidad(false);
						e2.reiniciarTimer();


						e1.setVisibilidad(true);
						e1.moverPersonaje(random);
						App.draw(e1.getPersonaje());
						f1.CambiarTextura(random + 1);
						e1.reducirTimer();
					
						break;

					case 2:
						//Ocultamos al rehen, mostramos al enemigo y lo movemos, reducimos su timer y abrimos su ventana
						e1.setVisibilidad(false);
						e1.reiniciarTimer();

						e2.setVisibilidad(true);
						e2.moverPersonaje(random);
						App.draw(e2.getPersonaje());
						f1.CambiarTextura(random + 1);
						e2.reducirTimer();

						break;
					case 3:
						//ocultamos a ambos
						f1.CambiarTextura(0);
						e1.setVisibilidad(false);
						e2.setVisibilidad(false);
						timer--;

				}
				
				if (e1.TimerTerminado()) {
					//si el enemigo espera lo suficiente, nos dispara y hacemos un ruido de dolor
					e1.Disparo();
					vidas--;

					//quitamos al enemigo
					dibujadoActual = decidirPersonaje();
					e1.setVisibilidad(false);
					e1.reiniciarTimer();
					random = rand() % 5;
				}
				if (e2.TimerTerminado()) {
					//si la rehen espera lo suficiente, se esconde
					dibujadoActual = decidirPersonaje();
					e2.setVisibilidad(false);
					e2.reiniciarTimer();
					random = rand() % 5;
				}
				if (timer == 0) {
					timer = 1000;
					dibujadoActual = decidirPersonaje();
				}

				//dibujamos el fondo
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