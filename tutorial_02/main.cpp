#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32; // bits per pixel, i.e. 32-bit color pixels

// Surfaces 
SDL_Surface *message = NULL;
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;

SDL_Surface* load_image( std::string filename ) {
    // Temporary storage for the image that's loaded
    SDL_Surface *loadedImage = NULL;

    // The optimized image that will be used
    SDL_Surface *optimizedImage = NULL;

    // Load the image
    loadedImage = IMG_Load( filename.c_str() );

    if ( loadedImage != NULL ) {
        // Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage) ;

        // Free the old image
        SDL_FreeSurface( loadedImage );
    }

    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface *source, SDL_Surface *destination ) {
    // Make a temporary rectangle to hold the offsets
    SDL_Rect offset;

    // Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;

    // Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

int main(int argc, char *args[]) {
    // Start SDL
    if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) {
        return 1;
    }

    // Set up screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    // sanity check
    if ( screen == NULL ) {
        return 1;
    }

    // Set Window Caption
    SDL_WM_SetCaption( "Hello World", NULL );

    // Load image
    message = load_image( "tutorial_02/hello.bmp" );
    background = load_image( "tutorial_02/background.bmp" );

    // Apply background to screen
    apply_surface( 0, 0, background, screen );
    apply_surface( 0, 400, background, screen );

    // Apply message to screen
    apply_surface( 0, 40, message , screen );

    // Update Screen
    if ( SDL_Flip( screen ) == -1) {
        return 1;
    }

    // Pause
    SDL_Delay( 2000 );

    // Free the loaded images
    SDL_FreeSurface( background );
    SDL_FreeSurface( message );

    // Quit SDL
    SDL_Quit();

    return 0;
}
