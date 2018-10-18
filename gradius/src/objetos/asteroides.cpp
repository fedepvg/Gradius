#include "asteroides.h"

#include "raylib.h"
#include "pantallas/pantallaJuego.h"

namespace Juego {
	namespace Asteroides {
		using namespace PantallaJuego;

		static const int velocidadAst = 200;
		static int radioMaxAst = 8;
		static int radioMinAst = 4;
		static Texture2D spriteAsteroide;
		static const int totalAsteroides = 40;
		int asteroidesDestruidos = 0;
		static void chequearColisionBordes();
		static void moverAsteroides();
		static void crearAsteroides();

		Asteroide asteroide;

		void chequearColisionBordes() {
			if (asteroide.activo) {
				if (asteroide.pos.x <= -asteroide.textura.width) {
					asteroide.activo = false;
				}
			}
		}

		void crearAsteroides() {
			asteroide.radio =(GetRandomValue(radioMinAst,radioMaxAst)/100000.0f) *(float)(GetScreenWidth()*GetScreenHeight());
			asteroide.activo = true;
			asteroide.textura = spriteAsteroide;
			asteroide.pos.x = GetScreenWidth()+asteroide.textura.width;
			asteroide.pos.y = GetRandomValue(0+asteroide.textura.height/2, GetScreenHeight() - asteroide.textura.height / 2);
			asteroide.velocidad.x = GetRandomValue(-500, -1000);
			asteroide.velocidad.y = 0.0f;
			asteroide.posYEscala = { asteroide.pos.x , asteroide.pos.y , asteroide.radio*2 , asteroide.radio*2 };
			asteroide.spriteFuente = { 0.0f , 0.0f , (float)spriteAsteroide.width , (float)spriteAsteroide.height };
			asteroide.origen = { asteroide.radio , asteroide.radio };
		}

		void desinicializarAsteroides() {

		}

		void moverAsteroides() {
			chequearColisionBordes();
			if (asteroide.activo){
				asteroide.pos.x += asteroide.velocidad.x*GetFrameTime();
				//asteroide.pos.y += asteroide.velocidad.y*GetFrameTime();
				asteroide.posYEscala.x = asteroide.pos.x;
				asteroide.posYEscala.y = asteroide.pos.y;
			}else {
				asteroide.activo = true;
				asteroide.pos.x = GetScreenWidth() + asteroide.textura.width;
				asteroide.pos.y = GetRandomValue(0, GetScreenHeight());
				asteroide.velocidad.x = GetRandomValue(-500,-1000);
			}
		}

		void inicializarAsteroides() {
			spriteAsteroide = LoadTexture("res/asteroide.png");
			crearAsteroides();
		}

		void actualizarAsteroides() {
			moverAsteroides();
		}

		void dibujarAsteroides(){
			if (asteroide.activo) {
				if (!pausa) {
					DrawTexturePro(asteroide.textura, asteroide.spriteFuente, asteroide.posYEscala, asteroide.origen, 0.0f, WHITE);
				}
				else {
					DrawTexturePro(asteroide.textura, asteroide.spriteFuente, asteroide.posYEscala, asteroide.origen, 0.0f, LIGHTGRAY);
				}
			}
		}
	}
}