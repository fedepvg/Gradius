#include "juego.h"

#include "raylib.h"
#include "Pantallas/pantallaJuego.h"
#include "Pantallas/pantallaMenu.h"
#include "Pantallas/pantallaGameOver.h"
#include "Pantallas/pantallaCreditos.h"
#include "pantallas/pantallaAyuda.h"

namespace Juego {
	static void inicializarJuego();
	static void inicializarPantallas();
	static void actualizar();
	static void dibujar();
	static void desinicializarPantallas();
	static void desinicializarJuego();

	using namespace PantallaJuego;
	estados estado = menu;
	int anchoPantalla = 1024;
	int altoPantalla = 720;
	bool enJuego = true;

	void inicializarJuego() {
		InitWindow(anchoPantalla, altoPantalla, "Asteroids");
		InitAudioDevice();
		SetExitKey(0);
	}

	void inicializarPantallas() {
		switch (estado) {
		case menu:
			Menu::inicializarMenu();
			break;
		case partida:
			inicializarPantJuego();
			break;
		case gameOver:
			GameOver::inicializarGO();
			break;
		case creditos:
			Creditos::inicializarCreditos();
			break;
		case ayuda:
			Ayuda::inicializarAyuda();
			break;
		default:break;
		}
	}

	void actualizar() {
		switch (estado) {
		case menu:
			Menu::actualizarMenu();
			break;
		case partida:
			actualizarJuego();
			break;
		case gameOver:
			GameOver::actualizarGO();
			break;
		case creditos:
			Creditos::actualizarCreditos();
			break;
		case ayuda:
			Ayuda::actualizarAyuda();
			break;
		default:break;
		}
	}

	void dibujar() {
		BeginDrawing();

		ClearBackground({0,0,56,255});

		switch (estado) {
		case menu:
			Menu::dibujarMenu();
			break;
		case partida:
			dibujarJuego();
			break;
		case gameOver:
			GameOver::dibujarGO();
			break;
		case creditos:
			Creditos::dibujarCreditos();
			break;
		case ayuda:
			Ayuda::dibujarAyuda();
			break;
		default:break;
		}
		EndDrawing();
	}

	void desinicializarPantallas() {
		switch (estado) {
		case partida:
			desinicializarPantJuego();
			break;
		default:break;
		}
	}

	void desinicializarJuego() {
		CloseAudioDevice();
		CloseWindow();
	}

	void ejecutar() {

		inicializarJuego();

		while (enJuego && !WindowShouldClose()) {
			inicializarPantallas();
			actualizar();
			dibujar();
			desinicializarPantallas();
		}

		desinicializarJuego();
	}
}