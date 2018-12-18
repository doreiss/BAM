#ifndef BAM_GRAPHICS_HITABLE_OBJECT_H
#define BAM_GRAPHICS_HITABLE_OBJECT_H

#include "type/math/Quaternion.h"
#include "type/graphics/hitable/Hitable.h"
#include "type/physics/body/Particle.h"


namespace BAM { namespace graphics {
	class HitableObject : public Hitable {
	public:
		virtual bool Hit(const Ray& r, real t_min, real t_max, HitRecord& rec) const = 0;
		virtual bool BoundingBox(AABB& box) const = 0;
		virtual void Update(const math::Vector3& nextPosition) = 0;
	};
} } // BAM::graphics

#endif //BAM_HITABLE_LIST_H
