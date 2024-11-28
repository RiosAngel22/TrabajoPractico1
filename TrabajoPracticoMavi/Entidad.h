#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Entidad
{
private:
	Sprite Personaje;
	int timer;
	int timerMaximo;
	bool visible = false;


	Vector2f Posiciones[5] = { Vector2f(255,248)
		,Vector2f(515,248),
		Vector2f(137,422),
		Vector2f(390,465),
		Vector2f(630,418) };


public:
	Sprite getPersonaje();
	void SetTextura(Texture &textura);
	void SetTimerMaximo(int tiempo);

	//funcionalidad 
	bool detectarColision(Sprite mouseSprite);
	void moverPersonaje(int valor);

	//tiempo de aparicion y desaparicion
	void reiniciarTimer();
	bool TimerTerminado();
	void reducirTimer();

	//aparecer y desaparecer
	bool getVisibilidad();
	void setVisibilidad(bool visibilidad);
};

