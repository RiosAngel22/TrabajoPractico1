#include <SFML/Graphics.hpp>
#include "Menu.h"

Menu::Menu(Font &Fuente){

	Fondo.setSize(Vector2f(800, 600));
	Fondo.setFillColor(Color::Black);

	//configuramos el titulo
	Texto1.setFont(Fuente);
	
	Texto1.setScale(1.5, 1.5);
	Texto1.setOutlineThickness(0.5);
	Texto1.setOutlineColor(Color::Yellow);
	Texto1.setPosition(Vector2f(50, 100));
	Texto1.setString("Juego de vaqueros");
	Texto1.setFillColor(Color::White);

	//configuramos las reglas
	Texto2.setFont(Fuente);
	Texto2.setScale(0.5, 0.5);
	Texto2.setPosition(Vector2f(50, 200));
	Texto2.setString("Reglas: Disparar a los villanos, evitar a los civiles, \n si le disparar a un civil perderas puntos y 1 vida, \n consigue 10 puntos para ganar");

	//usamos los pointers para crear botones
	Iniciar = new Boton("iniciar juego", Vector2f(550, 400), 5, Color::White,Fuente);
	ActivarSonido = new Boton("activar/desactivar sonido", Vector2f(550, 450), 5, Color::White,Fuente);
	Cerrar = new Boton("cerrar juego", Vector2f(550, 500), 5, Color::White,Fuente);
}

void Menu::DibujarMenu(RenderWindow &App) {
	//usamos una funcion de dibujo con renderWindow en vez de window, para ahorrarnos dibujar tantas cosas
	App.draw(Fondo);

	//dibujamos el titulo y las instrucciones
	App.draw(Texto1);
	App.draw(Texto2);

	//dibujamos boton 1
	App.draw(Iniciar->getFondo());
	App.draw(Iniciar->getBoton());
	

	//dibujamos boton 2
	App.draw(ActivarSonido->getFondo());
	App.draw(ActivarSonido->getBoton());
	

	//Dibujamos boton 3
	App.draw(Cerrar->getFondo());
	App.draw(Cerrar->getBoton());
	
}

void Menu::EfectoHover(Window &app) {
	Iniciar->EfectoHover(app);
	ActivarSonido->EfectoHover(app);
	Cerrar->EfectoHover(app);
}

int Menu::ChequearClicks(Window& app) {
	//el numero que devuelvan pasa por un switch que interpreta lo que quieren, asi se mantiene modular y expandible
	int valor;

	if (Iniciar->EstaArribaDelMouse(app)) {
		valor = 1;
	}
	else if (ActivarSonido->EstaArribaDelMouse(app)) {
		valor = 2;
	}
	else if (Cerrar->EstaArribaDelMouse(app)) {
		valor = 3;
	}
	else {
		valor = 0;
	}
	return valor;
}

