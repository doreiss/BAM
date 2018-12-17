#ifndef BAM_MATERIAL_LAMBERTIAN_H
#define BAM_MATERIAL_LAMBERTIAN_H

#include "type/graphics/material/Material.h"

namespace BAM {
	namespace graphics {
		class Lambertian : public Material {
		public:
			Lambertian() : mAlbedo(math::Vector3(REAL_HALF, REAL_HALF, REAL_HALF)) {}
			Lambertian(const math::Vector3& a) : mAlbedo(a) {}
			virtual bool Scatter(const Ray& rayIn, const HitRecord& rec, math::Vector3& attenuation, Ray& rayScattered) const override;
		private: 
			math::Vector3 mAlbedo;
		};
	}
} // BAM::graphics

#endif //BAM_MATERIAL_LAMBERTIAN_H
