#ifndef BAM_PHYSICS_BODY_PARTICLE_WORLD_H
#define BAM_PHYSICS_BODY_PARTICLE_WORLD_H

#include <vector>

#include "type/physics/body/Particle.h"
#include "type/physics/force/ParticleForceGenerator.h"

namespace BAM { namespace physics {

	class ParticleWorld {
	public:
		typedef std::vector<Particle*> Particles;
		ParticleWorld(Particles particles, ParticleForceRegistry reg) : mParticles(particles), mForceRegistry(reg) {}
		
		void startFrame() {
			for (Particles::iterator p = mParticles.begin(); p != mParticles.end(); ++p) {
				(*p)->ClearAccumulation();
			}
		}

		void Integrate(real duration) {
			for (Particles::iterator p = mParticles.begin(); p != mParticles.end(); ++p) {
				(*p)->Integrate(duration);
			}
		}
		void runPhysics(real duration) {
			mForceRegistry.UpdateForces(duration);
			Integrate(duration);
		}

		Particles mParticles;
		ParticleForceRegistry mForceRegistry;
	};

} } // BAM::physics

#endif //BAM_CAMERA_H