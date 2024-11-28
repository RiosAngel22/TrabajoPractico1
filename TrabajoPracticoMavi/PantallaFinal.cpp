#include "PantallaFinal.h"
#include <SFML/Graphics.hpp>

using namespace sf;

PantallaFinal::PantallaFinal(Font &fuente) {
	TexturaVictoria.loadFromFile("Assets/PantallaVictoria.png");
	TexturaDerrota.loadFromFile("Assets/PantallaDerrota.png");
	regreso = new Boton("reiniciar juego", Vector2f(390, 460), 3,fuente, Color(0xbe8b56ff), Color(0x222034ff));
	texto.setFont(fuente);
	texto.setPosition(180, 250);
}
void PantallaFinal::setVictoria(bool victoria) {
	if (victoria) {
		Pantalla.setTexture(TexturaVictoria);
	}
	else if (!victoria){
		Pantalla.setTexture(TexturaDerrota);
	}
}

void PantallaFinal::setTexto(String textoInput) {
	texto.setString(textoInput);
}

void PantallaFinal::DibujarPantalla(RenderWindow &App) {
	App.draw(Pantalla);
	App.draw(texto);
	App.draw(regreso->getFondo());
	App.draw(regreso->getBoton());
}

bool PantallaFinal::regresoPrecionado(Window &App) {
	return regreso->EstaArribaDelMouse(App);
}

void PantallaFinal::efectoHover(Window& App) {
	regreso->EfectoHover(App);
}