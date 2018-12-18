#ifndef BAM_HITABLE_SPHERE_H
#define BAM_HITABLE_SPHERE_H

#include "type/graphics/hitable/hitableobject/HitableObject.h"
#include "type/graphics/material/Lambertian.h"

namespace BAM { namespace graphics {
	class Sphere : public HitableObject {
	public:
		Sphere() {}

		Sphere(math::Vector3 center, real radius, Material* matPtr) : mCenter(center), mFutureCenter(center), mRadius(radius), mMaterialPtr(matPtr) {}
		Sphere(math::Vector3 center, real radius) : mCenter(center), mRadius(radius), mMaterialPtr(new Lambertian(math::Vector3(REAL_HALF, REAL_HALF, REAL_HALF))) {}

		math::Vector3 Center(real t) const;

		virtual bool Hit(const Ray& r, real t_min, real t_max, HitRecord& rec) const override;
		virtual bool BoundingBox(AABB& box) const override;
		virtual void Update(const math::Vector3& nextPosition) override;

		math::Vector3 mCenter;
		math::Vector3 mFutureCenter;
		real mRadius;
		Material* mMaterialPtr;
	};

} } // BAM::graphics

#endif //BAM_HITABLE_SPHERE_H