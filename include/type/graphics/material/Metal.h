#ifndef BAM_MATERIAL_METAL_H
#define BAM_MATERIAL_METAL_H

#include "type/graphics/material/Material.h"

namespace BAM { namespace graphics {
	
	class Metal : public Material {
	public:
		Metal() : mAlbedo(math::Vector3(REAL_FOUR / REAL_FIVE, REAL_FOUR / REAL_FIVE, REAL_FOUR / REAL_FIVE)), mFuzz(REAL_ZERO) {}
		Metal(const math::Vector3& a) : mAlbedo(a), mFuzz(REAL_ZERO) {}
		Metal(const math::Vector3& a, real f) :  mAlbedo(a) {
			mFuzz = ((f < REAL_ONE) ? f : REAL_ONE);
		}
		virtual bool Scatter(const Ray& rayIn, const HitRecord& rec, math::Vector3& attenuation, Ray& rayScattered) const override; 
	
	private:
		math::Vector3 mAlbedo;
		real mFuzz;
	};

} } // BAM::graphics

#endif //BAM_MATERIAL_METAL_H
#pragma once
