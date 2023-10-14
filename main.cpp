//g++ -o main main.cpp -I./SDL2/include -L./SDL2/lib -lSDL2
//g++ -o main main.cpp -I./sdl/include/SDL2 -L./sdl/lib -lSDL2

#include <SDL.h>

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL initialization failed: %s", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Pixel Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Log("Window creation failed: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("Renderer creation failed: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Set the pixel color (here, we use red)
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Set the pixel position (x and y coordinates)
    int x = 100;
    int y = 100;

    // Clear the screen
    SDL_RenderClear(renderer);

    // Draw the pixel
    SDL_RenderDrawPoint(renderer, x, y);

    // Present the renderer
    SDL_RenderPresent(renderer);

    // Wait for a moment
    SDL_Delay(2000); // Wait for 2 seconds

    // Clean up and quit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}