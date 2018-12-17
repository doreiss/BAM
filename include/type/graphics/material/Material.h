#ifndef BAM_MATERIAL_H
#define BAM_MATERIAL_H

#include "type/graphics/hitable/Hitable.h"

namespace BAM { namespace graphics {
	class Material {
	public:
		virtual bool Scatter(const Ray& rayIn, const HitRecord& rec, math::Vector3& attenuation, Ray& rayScattered) const = 0;
	};
} } // BAM::graphics

#endif //BAM_MATERIAL_H