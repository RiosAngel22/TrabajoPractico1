#include "Mira.h"


using namespace sf;

Mira::Mira(){
	MiraTextura.loadFromFile("Assets/mira.png");
	mira.setTexture(MiraTextura);
	mira.setOrigin(MiraTextura.getSize().x * 0.5, MiraTextura.getSize().y * 0.5);
};

void Mira::MoverMira(Window &App) {
	mira.setPosition(Mouse::getPosition(App).x, Mouse::getPosition(App).y);
}

Sprite Mira::ObtenerMira() {
	return mira;
}