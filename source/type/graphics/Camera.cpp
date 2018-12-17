#include "type/graphics/Camera.h"

BAM::graphics::Camera::Camera(math::Vector3 lookFrom, math::Vector3 lookAt, math::Vector3 viewUp, real vFOVDegrees, real aspectRatio, real aperture, real focalLength) {
	mLensRadius = aperture / REAL_TWO;

	real theta = vFOVDegrees * PI / REAL_HUNDRED_EIGHTY;
	real halfHeight = realTan(REAL_HALF*theta);
	real halfWidth = aspectRatio * halfHeight;

	mOrigin = lookFrom;

	mW = math::UnitVector(lookFrom - lookAt);
	mU = math::UnitVector(math::Cross(viewUp, mW));
	mV = math::Cross(mW, mU);

	mLowerLeftCorner = mOrigin - focalLength * (halfWidth*mU + halfHeight * mV + mW);
	mHorizontal = REAL_TWO * halfWidth*focalLength*mU;
	mVertical = REAL_TWO * halfHeight*focalLength*mV;
}

BAM::graphics::Ray BAM::graphics::Camera::RayAtUV(real u, real v) const {
	math::Vector3 randomDisc = (mLensRadius * math::RandomWithinUnitDisc());
	math::Vector3 offset = randomDisc.mX*mU + randomDisc.mY*mV;
	return Ray(mOrigin + offset, mLowerLeftCorner + (u * mHorizontal) + (v * mVertical) - mOrigin - offset);
}