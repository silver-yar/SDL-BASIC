// SDL BASIC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Screen.h"
#include "Swarm.h"
#include <math.h>
#include <iostream>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#undef main

using namespace std;
using namespace SDL_Testing;


int main()
{ 
	srand(time(NULL));

	Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing SQL." << endl;
	}

	Swarm swarm;

	while (true) {
		// Update Particles

		// Draw Particles
		int elapsed = SDL_GetTicks();

		swarm.update(elapsed);
		
		unsigned char red = (1 + sin(elapsed * 0.0001)) * 128;
		unsigned char green = (1 + sin(elapsed * 0.0002)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;
		const Particle * const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = (particle.m_y * Screen::SCREEN_WIDTH / 2) + (Screen::SCREEN_HEIGHT / 2);

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		//Draw the Screen
		screen.update();

		// Check for messages and events
		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}
