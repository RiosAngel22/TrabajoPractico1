#include "Villano.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Villano::Villano() {
	//carga el sprite del villano y setea su timer
	texturaVillano.loadFromFile("Assets/Villano.png");
	SetTextura(texturaVillano);
	SetTimerMaximo(timer);
}

void Villano::Disparo() {
	m1.playdisparo();
}

void Villano::DisparoAVillano() {
	m1.playPing();
}