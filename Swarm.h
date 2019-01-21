#pragma once
#include "Particle.h"

namespace SDL_Testing {

	class Swarm
	{
	public:
		const static int NPARTICLES = 5000;
	private:
		Particle * m_pParticles;
		int lasttime;

	public:
		Swarm();
		~Swarm();
		void update(int elapsed);

		const Particle * const getParticles() { return m_pParticles; }
	};

}