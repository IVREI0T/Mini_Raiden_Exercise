#include "SDL\include\SDL.h"


int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *window = SDL_CreateWindow("Game", 400, 400, 480, 640, NULL);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_PRESENTVSYNC);

	SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255);

	SDL_Texture* title = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("2163_2.bmp"));

	SDL_Texture* player = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("Sprites_P1.bmp"));

	SDL_Rect player_rect;

	bool run = true;
	int ship_x = 0;
	int ship_y = 0;
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
			case SDL_KEYDOWN:
			{
				switch (event.key.keysym.scancode)
				{
				case SDL_SCANCODE_LEFT:
				{
					ship_x -= 2;
					break;
				}
				case SDL_SCANCODE_RIGHT:
				{
					ship_x += 2;
					break;
				}
				case SDL_SCANCODE_UP:
				{
					ship_y -= 2;
					break;
				}
				case SDL_SCANCODE_DOWN:
				{
					ship_y += 2;
					break;
				}
				case SDL_SCANCODE_ESCAPE:
				{
					run = false;
					break;
				}
				default: break;

				}
			}
			}
		}
		
		//------------
		SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255);
		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, title, NULL, NULL);
		player_rect = { ship_x,ship_y,50,50};
		SDL_RenderCopy(renderer, player, NULL, &r);

		SDL_RenderPresent(renderer);
	}

	SDL_Quit();

	return 0;

}