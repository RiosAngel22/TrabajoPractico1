#include "Rehen.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Rehen::Rehen() {
	RehenTextura.loadFromFile("Assets/rehen.png");
	SetTextura(RehenTextura);
	SetTimerMaximo(timer);
}