#include "type/graphics/hitable/Sphere.h"

bool BAM::graphics::Sphere::Hit(const Ray& r, real t_min, real t_max, HitRecord& rec) const {
	math::Vector3 originToCenter = r.Origin() - mCenter;
	real a = Dot(r.Direction(), r.Direction());
	real b = Dot(originToCenter, r.Direction());
	real c = Dot(originToCenter, originToCenter) - mRadius * mRadius;
	real discriminant = b * b - a * c;
	if (discriminant > 0) {
		real temp = (-b - realSqrt(b*b - a * c)) / a;
		if (temp < t_max && temp > t_min) {
			rec.mT = temp;
			rec.mP = r.PointAtParam(rec.mT);
			rec.mNormal = (rec.mP - mCenter) / mRadius;
			rec.mMaterialPtr = mMaterialPtr;
			return true;
		}

		temp = (-b + realSqrt(b*b - a * c)) / a;
		if (temp < t_max && temp > t_min) {
			rec.mT = temp;
			rec.mP = r.PointAtParam(rec.mT);
			rec.mNormal = (rec.mP - mCenter) / mRadius;
			rec.mMaterialPtr = mMaterialPtr;
			return true;
		}
	}
	return false;
}