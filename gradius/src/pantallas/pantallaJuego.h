#ifndef PANTALLAJUEGO_H
#define PANTALLAJUEGO_H

#include"raylib.h"

namespace Juego {
	namespace PantallaJuego {
		enum fases { inicio, juego, salirAMenu, fin };
		extern fases fase;
		extern bool pausa;
		extern bool hayVolumen;

		void actualizarJuego();
		void dibujarJuego();
		void inicializarPantJuego();
		void desinicializarPantJuego();
	}
}

#endif