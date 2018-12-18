#include<algorithm>

#include "type\physics\force\ParticleForceGenerator.h"

void BAM::physics::ParticleForceRegistry::Add(Particle * particle, ParticleForceGenerator * fg) {
	mRegistrations.push_back(ParticleForceRegistration(particle, fg));
}

void BAM::physics::ParticleForceRegistry::Clear() {
	mRegistrations.clear();
}

void BAM::physics::ParticleForceRegistry::UpdateForces(real tDuration) {
	Registry::iterator it = mRegistrations.begin();
	for (; it != mRegistrations.end(); ++it) {
		it->mParticleFgPtr->UpdateForce(it->mParticlePtr, tDuration);
	}
}
