#include <SDL.h>
#include <cmath>
#include <vector>

// Función para generar los puntos del corazón
std::vector<SDL_Point> drawheart(int cx, int cy, int r, double paso) {
    std::vector<SDL_Point> puntos;
    for (double a = 0; a < 2 * M_PI; a += paso) {
        SDL_Point p;
        p.x = cx + 16 * r * pow(sin(a), 3);
        p.y = cy - (13 * r * cos(a) - 5 * r * cos(2 * a) - 2 * r * cos(3 * a) - r * cos(4 * a));
        puntos.push_back(p);
    }
    return puntos;
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO); // Inicializar SDL2

    // Crear una ventana
    SDL_Window* ventana = SDL_CreateWindow("Corazón", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);

    // Generar los puntos del corazón
    std::vector<SDL_Point> puntos = drawheart(400, 300, 10, 0.01);

    // Dibujar el corazón
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Color rojo
    SDL_RenderDrawLines(renderer, &puntos[0], puntos.size());

    SDL_RenderPresent(renderer); // Actualizar la ventana

    SDL_Delay(20000); // Esperar 5 segundos

    // Limpiar
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    SDL_Quit();

    return 0;
}
