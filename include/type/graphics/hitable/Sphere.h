#ifndef BAM_HITABLE_SPHERE_H
#define BAM_HITABLE_SPHERE_H

#include "type/graphics/hitable/Hitable.h"
#include "type/graphics/material/Lambertian.h"

namespace BAM { namespace graphics {
	class Sphere : public Hitable {
	public:
		Sphere() {}

		Sphere(math::Vector3 center, real radius, Material* matPtr) : mCenter(center), mRadius(radius), mMaterialPtr(matPtr) {}
		Sphere(math::Vector3 center, real radius) : mCenter(center), mRadius(radius), mMaterialPtr(new Lambertian(math::Vector3(REAL_HALF, REAL_HALF, REAL_HALF))) {}

		virtual bool Hit(const Ray& r, real t_min, real t_max, HitRecord& rec) const override;
		virtual bool BoundingBox(real t0, real t1, AABB& box) const override;


		math::Vector3 mCenter;
		real mRadius;
		Material* mMaterialPtr;
	};

} } // BAM::graphics

#endif //BAM_HITABLE_SPHERE_H