#include "Musica.h"
#include <SFML/Audio.hpp>


using namespace sf;

Musica::Musica() {
	//cargamos nuestra musica
	CancionBuffer.loadFromFile("Assets/cancionVaquera.wav");
	disparoBuffer.loadFromFile("Assets/disparo.wav");
	pingBuffer.loadFromFile("Assets/ping.wav");

	CancionVictoriaBuffer.loadFromFile("Assets/CancionVictoria.wav");
	CancionDerrotaBuffer.loadFromFile("Assets/CancionDerrota.wav");

	CancionVictoria.setBuffer(CancionVictoriaBuffer);
	CancionDerrota.setBuffer(CancionDerrotaBuffer);

	//configuramos la cancion principal
	cancion.setBuffer(CancionBuffer);
	cancion.setLoop(true);
	cancion.setVolume(20);

	Disparo.setBuffer(disparoBuffer);

	ping.setBuffer(pingBuffer);
	ping.setVolume(80);
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

void Musica::playPing() {
	ping.play();
}

void Musica::playVictoria() {
	CancionVictoria.play();
}

void Musica::playDerrota() {
	CancionDerrota.play();
}

Sound Musica::getVictoria() {
	return CancionVictoria;
}

Sound Musica::getDerrota() {
	return CancionDerrota;
}