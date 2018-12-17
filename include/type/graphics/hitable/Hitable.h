#ifndef BAM_HITABLE_H
#define BAM_HITABLE_H

#include "type/graphics/Ray.h"

namespace BAM { namespace graphics {

	class Material;

	struct HitRecord {
		real mT; 
		math::Vector3 mP;
		math::Vector3 mNormal;
		Material* mMaterialPtr;
	};

	class Hitable {
	public: 
		virtual bool Hit(const Ray& r, real t_min, real t_max, HitRecord& rec) const = 0;
	};

} } // BAM::graphics

#endif //BAM_HITABLE_H