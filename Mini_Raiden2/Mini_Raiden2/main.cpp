#include "SDL\include\SDL.h"



int main(int argc, char* args[])
{

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_CreateWindowAndRenderer(480, 640, 0, &window, &renderer);


	SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255);

	SDL_Texture* title = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("2163_2.bmp"));

	SDL_Texture* player = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Sprites_P1.bmp"));

	SDL_Rect r;

	bool run = true;

	while(run)
	{
		//------------
		/* Input */

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				run = false;
			}
			switch (event.type)
			{

			}
		}


		//------------
		SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255);
		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, title, NULL, NULL);
		r = { 0,0,50,50};
		SDL_RenderCopy(renderer, player, NULL, &r);

		SDL_RenderPresent(renderer);
	}

	SDL_Quit();

	return 0;

}