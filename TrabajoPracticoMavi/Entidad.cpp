#include "Entidad.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace sf;
using namespace std;

void Entidad::moverPersonaje(int valor) {
	Personaje.setPosition(Posiciones[valor]);
}

Sprite Entidad::getPersonaje() {
	return Personaje;
}

bool Entidad::detectarColision(Sprite mouseSprite) {
	//informa si el disparo impacto contra el sprite
	FloatRect colision = Personaje.getGlobalBounds();
	if (colision.contains(mouseSprite.getPosition())) {
		return true;
	}
	else {
		return false;
	}
}

void Entidad::SetTimerMaximo(int tiempo) {
	//esto se deberia declarar primero, para que la primera vez que usemos el timer, este no sea 0
	timerMaximo = tiempo;
	timer = tiempo;
}

void Entidad::SetTextura(Texture &textura) {
	Personaje.setTexture(textura);
}

void Entidad::reducirTimer() {
	timer -= 1;
}

void Entidad::reiniciarTimer() {
	timer = timerMaximo;
}

bool Entidad::TimerTerminado() {
	if (timer == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Entidad::getVisibilidad() {
	return visible;
}

void Entidad::setVisibilidad(bool visibilidad) {
	visible = visibilidad;
}