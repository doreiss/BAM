#ifndef BAM_PHYSICS_FORCE_PARTICLE_FORCE_GENERATOR_H
#define BAM_PHYSICS_FORCE_PARTICLE_FORCE_GENERATOR_H

#include <vector>

#include "type/physics/body/Particle.h"

namespace BAM { namespace physics { 
	class ParticleForceGenerator {
	public: 
		virtual void UpdateForce(Particle*, real tDuration) = 0;
	};

	class ParticleForceRegistry {
	protected:
		struct ParticleForceRegistration {
			
			ParticleForceRegistration(Particle* particle, ParticleForceGenerator* fg) :
				mParticlePtr(particle), mParticleFgPtr(fg) {}

			Particle* mParticlePtr;
			ParticleForceGenerator* mParticleFgPtr;
		};

		typedef std::vector<ParticleForceRegistration> Registry;
		Registry mRegistrations;
	public:
		ParticleForceRegistry() {}
		void Add(Particle* particle, ParticleForceGenerator* fg);
		void Clear();
		void UpdateForces(real tDuration);
	};
}  } // BAM::physics

#endif //BAM_CAMERA_H