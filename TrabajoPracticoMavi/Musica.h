#pragma once
#include <SFML/Audio.hpp>

using namespace sf;

class Musica
{
private:
	SoundBuffer CancionBuffer;
	Sound cancion;

	SoundBuffer disparoBuffer;
	Sound Disparo;
public:
	Musica();
	void playdisparo();
	void playCancion();
	void StopCancion();
};

