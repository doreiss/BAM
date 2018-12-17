#include "type/graphics/material/Dielectric.h"

bool BAM::graphics::Refract(const math::Vector3& v, const math::Vector3& n, real niOverNt, math::Vector3& refracted) {
math::Vector3 uv = math::UnitVector(v);
real dt = math::Dot(uv, n);
real discrim = REAL_ONE - niOverNt * niOverNt*(REAL_ONE - dt * dt);
	if (discrim > 0) {
		refracted = niOverNt * (uv - (n*dt)) - n * realSqrt(discrim);
		return true;
	}
	else {
		return false;
	}
}

BAM::real BAM::graphics::Schlick(real cosine, real refInd) {
	real r0 = (REAL_ONE - refInd) / (REAL_ONE + refInd);
	r0 = r0 * r0;
	real omCos = REAL_ONE - cosine;
	return r0 + (REAL_ONE - r0)*omCos*omCos*omCos*omCos*omCos;
}

bool BAM::graphics::Dielectric::Scatter(const Ray& rayIn, const HitRecord& rec, math::Vector3& attenuation, Ray& rayScattered) const {
	math::Vector3 outwardNormal = math::Vector3();
	math::Vector3 reflected = math::Reflect(rayIn.Direction(), rec.mNormal);
	real niOverNt;
	attenuation = math::Vector3(REAL_ONE, REAL_ONE, REAL_ONE);
	math::Vector3 refracted = math::Vector3();
	real reflectProb;
	real cosine;


	if (math::Dot(rayIn.Direction(), rec.mNormal) > 0) {
		outwardNormal = -rec.mNormal;
		niOverNt = mRefInd;
		cosine = mRefInd * math::Dot(rayIn.Direction(), rec.mNormal) / rayIn.Direction().Magnitude();

	}
	else {
		outwardNormal = rec.mNormal;
		niOverNt = REAL_ONE / mRefInd;
		cosine = -math::Dot(rayIn.Direction(), rec.mNormal) / rayIn.Direction().Magnitude();
	}
	if (Refract(rayIn.Direction(), outwardNormal, niOverNt, refracted)) {
		reflectProb = Schlick(cosine, mRefInd);
	}
	else {
		reflectProb = REAL_ONE;
	}
	if (math::UniformRand() < reflectProb) {
		rayScattered = Ray(rec.mP, reflected);
	}
	else {
		rayScattered = Ray(rec.mP, refracted);
	}
	return true;
}