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

	SoundBuffer pingBuffer;
	Sound ping;

	SoundBuffer CancionVictoriaBuffer;
	Sound CancionVictoria;

	SoundBuffer CancionDerrotaBuffer;
	Sound CancionDerrota;

public:
	Musica();
	void playdisparo();
	void playCancion();
	void StopCancion();

	void playVictoria();
	void playDerrota();
	Sound getVictoria();
	Sound getDerrota();

	void playPing();


};

