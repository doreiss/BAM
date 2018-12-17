#include "bam_math.h"

namespace BAM { namespace math {
	real SqrtFast(const real& r, const unsigned int& it) {
		assert(it <= 3);
		return r*RSqrtFast(r,it);
	}

	Vector3 RandomWithinUnitDisc() {
		Vector3 p;
		Vector3 offset = Vector3(REAL_ONE, REAL_ONE, REAL_ZERO);
		do {
			p = REAL_TWO * Vector3(UniformRand(), UniformRand(), REAL_ZERO) - offset;
		} while (p.SquaredMagnitude() >= REAL_ONE);
		return p;
	}
	Vector3 RandomWithinUnitSphere() {
		Vector3 p;
		Vector3 offset = Vector3(REAL_ONE, REAL_ONE, REAL_ONE);
		do {
			p = REAL_TWO * Vector3(UniformRand(), UniformRand(), UniformRand()) - offset;
		} while (p.SquaredMagnitude() >= REAL_ONE);
		return p;
	}


} } //BAM::math
