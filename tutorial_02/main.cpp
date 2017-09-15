#include <SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *gWindow = NULL;				// This is the window to render on to
SDL_Surface* gScreenSurface = NULL; 	// Surface contained by the window
SDL_Surface* gHelloWorld = NULL; 		// Image to load and show on the screen

// initialization function
bool init() {
	// Initialization flag
	bool success = true;

	// Initialize SDL
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	} else {
		// Create Window
		gWindow = SDL_CreateWindow( "SDL_Tutorial_02", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if ( gWindow == NULL ) {
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		} else {
			// Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}

	return success;
}

bool loadMedia() {
	// Success flag
	bool success = true;

	// Load splash image
	gHelloWorld = SDL_LoadBMP( "tutorial_02/hello.bmp" );
	if ( gHelloWorld == NULL ) {
		printf( "Unable to load image %s! SDL Error: %s\n", "tutorial_02/hello.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}

void close() {
	// Free surface
	SDL_FreeSurface( gHelloWorld );
	gHelloWorld = NULL;

	// Destroy Window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	// Quit SDL Subsystem
	SDL_Quit();
}

int main(int argc, char *args[]) {
    
	// Initialize
	if ( !init() ) {
		printf( "Failed to initialize!\n" );
	} else {
		// Load media
		if ( !loadMedia() ) {
			printf( "Failed to load media!\n" );
		} else {
			// Apply the image
			SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
			
			// Update the surface
			SDL_UpdateWindowSurface( gWindow );

			// Wait 2 seconds
			SDL_Delay( 2000 );
		}
	}

	// Free and quit SDL
	close();

	return 0;
}
