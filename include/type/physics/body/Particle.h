#ifndef BAM_PHYSICS_BODY_PARTICLE_H
#define BAM_PHYSICS_BODY_PARTICLE_H

#include "type/math/Vector3.h"

namespace BAM { namespace physics {

	class Particle {
	public:

		Particle(math::Vector3 iPos, math::Vector3 iVel, math::Vector3 iAcc, real imass, real damping = REAL_ONE) : mPosition(iPos), mVelocity(iVel), mAcceleration(iAcc), mForceAccumulation(), mIMass(imass), mDamping(damping) {}

		real Mass() { return REAL_ONE/mIMass; }
		real IMass() { return mIMass; }

		bool HasFiniteMass() { return (mIMass > REAL_ZERO); }

		void Integrate(real tDuration);
		void AddForce(const math::Vector3& force);
		void ClearAccumulation();

		math::Vector3 mPosition;
		math::Vector3 mVelocity;
		math::Vector3 mAcceleration;
		math::Vector3 mForceAccumulation;
		real mDamping;
		real mIMass;
	};

} } // BAM::physics

#endif //BAM_CAMERA_H