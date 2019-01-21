#include "stdafx.h"
#include "Swarm.h"


namespace SDL_Testing {

	Swarm::Swarm(): lasttime(0)
	{
		m_pParticles = new Particle[NPARTICLES];
	}


	Swarm::~Swarm()
	{
		delete[] m_pParticles;
	}

	void Swarm::update(int elapsed)
	{
		int interval = elapsed - lasttime;

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			m_pParticles[i].update(interval);
		}

		lasttime = elapsed;
	}

}