#include "Boton.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Boton::Boton(String textNuevo, Vector2f Posicion,int tamaño,Font &fuente,Color colorprimario,Color colorsecundario) {
	//ingresamos los colores principales y alternativos
	ColorDefault = colorprimario;
	DefaultFondo = colorsecundario;
	texto.setFillColor(DefaultFondo);
	Fondo.setFillColor(DefaultFondo);

	//cargamos la fuente de texto
	texto.setFont(fuente);

	//ingresamos el texto del input
	texto.setString(textNuevo);
	texto.setPosition(Posicion.x, Posicion.y);
	
	//width/2 y height/2 nos dan el centro absoluto
	texto.setOrigin(texto.getLocalBounds().width / 2, texto.getGlobalBounds().height / 2);

	//le ponemos un fondo
	//situamos el fondo al borde izquierdo, y le quitamos un poco de offset para centrarlo horizontalmente
	//de la misma forma, situamos el fondo al borde de arriba, y le quitamos offset de altura
	Fondo.setPosition(Vector2f(texto.getGlobalBounds().left - texto.getGlobalBounds().width/6.5, texto.getGlobalBounds().top - texto.getGlobalBounds().height/3));

	//el fondo usa los global bounds del texto multiplicados para que sobresalgan
	Fondo.setSize(Vector2f(texto.getGlobalBounds().width * 1.3,texto.getGlobalBounds().height * 1.5));
	
}

Text Boton::getBoton() {
	return texto;
}

RectangleShape Boton::getFondo() {
	return Fondo;
}

bool Boton::EstaArribaDelMouse(Window &App) {
	//si el mouse coincide posicion con el boton, regresa true
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
	//al coincidir posicion, el mouse crea un efecto

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

