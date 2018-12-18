#ifndef BAM_GRAPHICS_HITABLE_OBJECT_H
#define BAM_GRAPHICS_HITABLE_OBJECT_H

#include "type/graphics/hitable/Hitable.h"
#include "type/physics/body/Particle.h"


namespace BAM {
	namespace graphics {

		class HitableObject : public Hitable {
		public:

			virtual bool Hit(const Ray& r, real t_min, real t_max, HitRecord& rec) const = 0;
			virtual bool BoundingBox(AABB& box) const = 0;
			void FollowParticle(physics::Particle* particle) {
				mNextPosition = particle->mPosition;
				Update();
			}
			virtual void Update() = 0;
			math::Vector3 mNextPosition;

		};

	}
} // BAM::graphics

#endif //BAM_HITABLE_LIST_H
