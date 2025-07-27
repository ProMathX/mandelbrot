#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <complex.h>
#include <wctype.h>

#define WIDTH 1920
#define HEIGHT 1080
#define COLOR_WHITE SDL_MapRGB(psurface->format, 255, 255, 255)
#define MANDELBROT_LIMIT 2
#define ZOOM 400
#define OFFSET_X 100

int check_mandelbrot(double real, double imag){
    double _Complex c = real + imag * I;
    double _Complex z = 0;

    for(int i = 0; i < 100; i++){
        z = z * z + c;

    }
    // Is z exceeding?
    return cabs(z) < MANDELBROT_LIMIT;
}

double cabs(double _Complex number){
    return sqrt(pow(creal(number), 2) + pow(cimag(number), 2));

}

void visualize_mandelbrot_window(SDL_Surface *psurface){
    for(int x = 0; x < WIDTH; x++){

        for(int y = 0; y < HEIGHT; y++){

            //transform coordinate system
            double real = ((double) (x - WIDTH/2 - OFFSET_X))/ZOOM;
            double imaginary = - ((double) (y - HEIGHT/2))/ZOOM;

            if(check_mandelbrot(real,imaginary)){
               SDL_Rect pixel = {x,y,1,1};
               SDL_FillRect(psurface, &pixel, COLOR_WHITE);
            }
        }
    }
   //SDL_UpdateWindowSurface(pwindow);

}

int main(){

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *pwindow =  SDL_CreateWindow("Mandelbrot",
                                             SDL_WINDOWPOS_CENTERED,
                                             SDL_WINDOWPOS_CENTERED,
                                             WIDTH,
                                             HEIGHT,
                                             0);

    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
    SDL_Event event;
    int event_running = 1;

    while (event_running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    event_running = 0;
                break;
            }
        }

       visualize_mandelbrot_window(psurface);

       SDL_Delay(4000);
       SDL_UpdateWindowSurface(pwindow);
    }


}
