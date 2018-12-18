#include "type/graphics/hitable/hitableobject/Sphere.h"

BAM::math::Vector3 BAM::graphics::Sphere::Center(real t) const {
	return (REAL_ONE - t)*mCenter + t * mFutureCenter;
}

bool BAM::graphics::Sphere::Hit(const Ray& r, real t_min, real t_max, HitRecord& rec) const {
	math::Vector3 originToCenter = r.Origin() - Center(r.Time());
	real a = Dot(r.Direction(), r.Direction());
	real b = Dot(originToCenter, r.Direction());
	real c = Dot(originToCenter, originToCenter) - mRadius * mRadius;
	real discriminant = b * b - a * c;
	if (discriminant > 0) {
		real temp = (-b - realSqrt(b*b - a * c)) / a;
		if (temp < t_max && temp > t_min) {
			rec.mT = temp;
			rec.mP = r.PointAtParam(rec.mT);
			rec.mNormal = (rec.mP - Center(r.Time())) / mRadius;
			rec.mMaterialPtr = mMaterialPtr;
			return true;
		}

		temp = (-b + realSqrt(b*b - a * c)) / a;
		if (temp < t_max && temp > t_min) {
			rec.mT = temp;
			rec.mP = r.PointAtParam(rec.mT);
			rec.mNormal = (rec.mP - Center(r.Time())) / mRadius;
			rec.mMaterialPtr = mMaterialPtr;
			return true;
		}
	}
	return false;
}

bool BAM::graphics::Sphere::BoundingBox(AABB& box) const {
	AABB firstBox = AABB(mCenter - math::Vector3(mRadius, mRadius, mRadius), mCenter + math::Vector3(mRadius, mRadius, mRadius));
	AABB secondBox = AABB(mFutureCenter - math::Vector3(mRadius, mRadius, mRadius), mFutureCenter + math::Vector3(mRadius, mRadius, mRadius));
	box = SurroundingBox(firstBox, secondBox);
	return true;
}

void BAM::graphics::Sphere::Update(const math::Vector3& nextPosition) {
	mCenter = mFutureCenter;
	mFutureCenter = nextPosition;
}
