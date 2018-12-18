#ifndef BAM_PHYSICS_FORCE_PARTICLE_GRAVITY_H
#define BAM_PHYSICS_FORCE_PARTICLE_GRAVITY_H

#include <vector>
#include "type/physics/force/ParticleForceGenerator.h"

namespace BAM { namespace physics { 
	class ParticleGravity : public ParticleForceGenerator {
	public: 
		ParticleGravity(const math::Vector3& gravity) : mGravity(gravity) {}
		virtual void UpdateForce(Particle* particle, real tDuration) override;
	private:
		math::Vector3 mGravity;
	};

} } // BAM::physics

#endif //BAM_CAMERA_H