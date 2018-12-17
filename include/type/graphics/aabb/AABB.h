#pragma once
#ifndef BAM_AABB_H
#define BAM_AABB_H

#include "type/graphics/Ray.h"

namespace BAM { namespace graphics {
	
	//Axis Aligned Bounding Box

	class AABB {
		public:
			AABB() {}
			AABB(const math::Vector3& min, const math::Vector3 max) : mMin(min), mMax(max) {}

			math::Vector3 Min() const { return mMin; }
			math::Vector3 Max() const { return mMax; }

			//A. Kensler's (Pixar) AABB hit fcn
			inline bool Hit(const Ray& rayIn, real tMin, real tMax) const {
				for (int a = 0; a < 3; ++a) {
					real invD = REAL_ONE / rayIn.Direction()[a];
					real t0 = (Min()[a] - rayIn.Origin()[a])*invD;
					real t1 = (Max()[a] - rayIn.Origin()[a])*invD;
					if (invD < REAL_ZERO) {
						std::swap(t0, t1);
					}
					tMin = t0 > tMin ? t0 : tMin;
					tMax = t1 < tMax ? t1 : tMax;
				}
				if (tMax <= tMin) {
					return false;
				}
				return true;
			}

		private:
			math::Vector3 mMin; 
			math::Vector3 mMax;
	};

	AABB SurroundingBox(AABB box0, AABB box1);

} } // BAM::graphics

#endif //BAM_CAMERA_H