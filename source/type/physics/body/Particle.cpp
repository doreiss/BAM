#include <assert.h>

#include "bam_math.h"
#include "type\physics\body\Particle.h"

void BAM::physics::Particle::Integrate(real tDuration) {
	if (mIMass <= REAL_ZERO) {
		return;
	}

	assert(tDuration > REAL_ZERO);

	mPosition += (tDuration*mVelocity);

	math::Vector3 resultAcceleration = mAcceleration + mForceAccumulation*mIMass;

	mVelocity += (tDuration*resultAcceleration);
	
	if (mDamping < REAL_ONE) {
		mVelocity *= realPow(mDamping, tDuration);
	}

	ClearAccumulation();
}

void BAM::physics::Particle::AddForce(const math::Vector3 & force) {
	mForceAccumulation += force;
}

void BAM::physics::Particle::ClearAccumulation() {
	mForceAccumulation.Clear();
}
