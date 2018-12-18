#ifndef BAM_RAY_H
#define BAM_RAY_H

#include "bam_math.h"

namespace BAM { namespace graphics {
	class Ray {
	public:
		Ray() {}
		Ray(const math::Vector3& aDef, const math::Vector3& bDef, 
			real ti = 0.0) :
			mA(aDef), mB(bDef), mT(ti) {}

		math::Vector3 Origin() const { return mA; }
		math::Vector3 Direction() const { return mB; }
		math::Vector3 PointAtParam(real t) const { return mA + (mB*t); }
		inline real Time() const { return mT;  }


	private: 
		math::Vector3 mA; 
		math::Vector3 mB;
		real mT;
	};
} } // BAM::graphics

#endif //BAM_RAY_H