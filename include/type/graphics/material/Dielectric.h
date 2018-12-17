#ifndef BAM_MATERIAL_DIELECTRIC_H
#define BAM_MATERIAL_DIELECTRIC_H

#include "type/graphics/material/Material.h"

namespace BAM {
	namespace graphics {

		bool Refract(const math::Vector3& v, const math::Vector3& n, real niOverNt, math::Vector3& refracted);
		real Schlick(real cosine, real refInd);

		class Dielectric : public Material {
		public:
			Dielectric() : mRefInd(REAL_THREEHALVES) {}
			Dielectric(real refInd) : mRefInd(refInd) {}
			virtual bool Scatter(const Ray& rayIn, const HitRecord& rec, math::Vector3& attenuation, Ray& rayScattered) const override;

		private:
			real mRefInd;
		};
	}
} // BAM::graphics

#endif //BAM_MATERIAL_METAL_H
