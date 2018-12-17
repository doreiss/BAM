#include "type/graphics/material/Metal.h"

bool BAM::graphics::Metal::Scatter(const Ray& rayIn, const HitRecord& rec, math::Vector3& attenuation, Ray& rayScattered) const {
	math::Vector3 reflected = math::Reflect(math::UnitVector(rayIn.Direction()), rec.mNormal);
	rayScattered = Ray(rec.mP, reflected + mFuzz * math::RandomWithinUnitSphere());
	attenuation = mAlbedo;
	return (math::Dot(rayScattered.Direction(), rec.mNormal) > 0);
}