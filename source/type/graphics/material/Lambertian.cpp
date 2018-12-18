#include "type/graphics/material/Lambertian.h"

bool BAM::graphics::Lambertian::Scatter(const Ray& rayIn, const HitRecord& rec, math::Vector3& attenuation, Ray& rayScattered) const {
	math::Vector3 target = rec.mP + rec.mNormal + math::RandomWithinUnitSphere();
	rayScattered = Ray(rec.mP, target - rec.mP, rayIn.Time());
	attenuation = mAlbedo;
	return true;
}