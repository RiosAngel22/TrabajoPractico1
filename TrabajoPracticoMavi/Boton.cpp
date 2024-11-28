#include "Boton.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Boton::Boton(String textNuevo, Vector2f Posicion,int tamaño,Font &fuente) {
	//cargamos texto
	texto.setFont(fuente);

	//ingresamos el texto del input
	texto.setString(textNuevo);
	texto.setPosition(Posicion.x, Posicion.y);
	texto.setFillColor(DefaultFondo);
	//width/2 y height/2 nos dan el centro absoluto
	texto.setOrigin(texto.getLocalBounds().width / 2, texto.getGlobalBounds().height / 2);

	//le ponemos un fondo
	//situamos el fondo al borde izquierdo, y le quitamos un poco de offset para centrarlo horizontalmente
	//de la misma forma, situamos el fondo al borde de arriba, y le quitamos offset de altura
	Fondo.setPosition(Vector2f(texto.getGlobalBounds().left - texto.getGlobalBounds().width/6.5, texto.getGlobalBounds().top - texto.getGlobalBounds().height/3));

	//el fondo usa los global bounds del texto multiplicados por 1.5 y 2 respectivamente
	Fondo.setSize(Vector2f(texto.getGlobalBounds().width * 1.3,texto.getGlobalBounds().height * 1.5));
	Fondo.setFillColor(DefaultFondo);
}

Text Boton::getBoton() {
	return texto;
}

RectangleShape Boton::getFondo() {
	return Fondo;
}

bool Boton::EstaArribaDelMouse(Window &App) {
	FloatRect colision;
	colision = Fondo.getGlobalBounds();
	bool resultado;
	if (colision.contains(Mouse::getPosition(App).x, Mouse::getPosition(App).y)) {
		resultado = true;
		}
	else {
		resultado = false;
	}
	return resultado;
	}
	
void Boton::EfectoHover(Window& App) {
	FloatRect colision;
	colision = Fondo.getGlobalBounds();
	if (colision.contains(Mouse::getPosition(App).x, Mouse::getPosition(App).y)) {
		texto.setFillColor(ColorDefault);
		Fondo.setFillColor(DefaultFondo);
	}
	else {
		texto.setFillColor(DefaultFondo);
		Fondo.setFillColor(ColorDefault);
	}
}

