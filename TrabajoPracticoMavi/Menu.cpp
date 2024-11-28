#include <SFML/Graphics.hpp>
#include "Menu.h"

Menu::Menu(Font &Fuente){

	Fondo.loadFromFile("Assets/menu.png");
	FondoSprite.setTexture(Fondo);

	//configuramos el titulo
	Texto1.setFont(Fuente);
	Texto1.setScale(1.3, 1.3);
	Texto1.setPosition(Vector2f(30, 600));
	Texto1.setString("El deber de un sheriff");
	Texto1.setFillColor(Color(0xbe8b56ff));

	//configuramos las reglas
	Texto2.setFont(Fuente);
	Texto2.setScale(0.8, 0.8);
	Texto2.setPosition(Vector2f(30, 660));
	Texto2.setString("Reglas: Disparar a los villanos,\n evitar a los civiles, \n si le disparar a un civil\n perderas puntos y 1 vida, \n consigue 10 puntos para ganar");
	Texto2.setFillColor(Color(0xbe8b56ff));

	//usamos los pointers para crear botones
	Iniciar = new Boton("iniciar juego", Vector2f(405, 500), 1,Fuente, Color(0xbe8b56ff), Color(0x222034ff));
	ActivarSonido = new Boton("activar sonido", Vector2f(400, 530), 1,Fuente, Color(0xbe8b56ff), Color(0x222034ff));
	Cerrar = new Boton("cerrar juego", Vector2f(405, 560), 1,Fuente, Color(0xbe8b56ff), Color(0x222034ff));
}

void Menu::DibujarMenu(RenderWindow &App) {
	//usamos una funcion de dibujo con renderWindow en vez de window, para ahorrarnos dibujar tantas cosas
	App.draw(FondoSprite);

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
	//Activamos los efectos hover en conjunto
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

