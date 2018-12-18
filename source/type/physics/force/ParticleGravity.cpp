#include "bam_math.h"
#include "type\physics\force\ParticleGravity.h"

void BAM::physics::ParticleGravity::UpdateForce(Particle * particle, real tDuration) {
	if (!particle->HasFiniteMass()) {
		return;
	}
	particle->AddForce(mGravity*particle->Mass());

}
