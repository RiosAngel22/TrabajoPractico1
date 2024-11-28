#include "Rehen.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Rehen::Rehen() {
	//carga el sprite de la rehen y setea su timer
	RehenTextura.loadFromFile("Assets/rehen.png");
	SetTextura(RehenTextura);
	SetTimerMaximo(timer);
}
