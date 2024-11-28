#include "Mira.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Mira::Mira(){
	//cargamos la textura y la centramos
	MiraTextura.loadFromFile("Assets/mira.png");
	mira.setTexture(MiraTextura);
	mira.setOrigin(MiraTextura.getSize().x * 0.5, MiraTextura.getSize().y * 0.5);
};

void Mira::MoverMira(Window &App) {
	//la mira se mueve hacia el mouse relativo al tamaño de la pantalla 
	mira.setPosition(Mouse::getPosition(App).x, Mouse::getPosition(App).y);
}

Sprite Mira::ObtenerMira() {
	return mira;
}

void Mira::Disparar() {
	//reproducimos el sonido de disparo
	d1.playdisparo();
}