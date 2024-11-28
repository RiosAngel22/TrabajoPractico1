#include "Fondo.h"

using namespace sf;

Fondo::Fondo() {
	MeterAlArray();
	CambiarTextura(0);
}

void Fondo::MeterAlArray() {
	//carga todas nuestras texturas en un array
	for (int i = 0; i <= 5; i++)
	{
		Texturas[i].loadFromFile(archivos[i]);
	}
}

void Fondo::CambiarTextura(int valor) {
	//Situa la textura correcta cuando la llamamos, asegurandose de no pasarse de los limites
	if ((valor >= 0) and (valor <= 5)) {
		fondo.setTexture(Texturas[valor]);
	}
	
}

Sprite Fondo::getSprite(){
	return fondo;
}
