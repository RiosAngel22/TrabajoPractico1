#include "Villano.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Villano::Villano() {
	texturaVillano.loadFromFile("Assets/Villano.png");
	SetTextura(texturaVillano);
	SetTimerMaximo(timer);
}

void Villano::Disparo() {
	m1.playdisparo();
}