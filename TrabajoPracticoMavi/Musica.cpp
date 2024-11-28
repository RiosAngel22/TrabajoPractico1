#include "Musica.h"
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;

Musica::Musica() {
	if (!CancionBuffer.loadFromFile("Assets/cancionVaquera.wav")) {
		std::cout << "cancion no cargada";
	};
	if (!disparoBuffer.loadFromFile("Assets/disparo.wav")) {
		std::cout << "disparo no cargado";
	};

	cancion.setBuffer(CancionBuffer);
	cancion.setLoop(true);
	cancion.setVolume(30);

	Disparo.setBuffer(disparoBuffer);
}

void Musica::playCancion() {
	cancion.play();
};

void Musica::playdisparo() {
	Disparo.play();
}

void Musica::StopCancion() {
	cancion.stop();
}