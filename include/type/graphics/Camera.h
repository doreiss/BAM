#ifndef BAM_CAMERA_H
#define BAM_CAMERA_H

#include "type/graphics/Ray.h"

namespace BAM { namespace graphics {
	class Camera {
	public:
		Camera() {}
		Camera(math::Vector3 lookFrom, math::Vector3 lookAt, math::Vector3 viewUp, real vFOVDegrees, real aspectRatio, real aperture, real focalLength);
		Ray RayAtUV(real u, real v) const;

	private:
		math::Vector3 mLowerLeftCorner; 
		math::Vector3 mHorizontal; 
		math::Vector3 mVertical;
		math::Vector3 mOrigin;

		math::Vector3 mU; 
		math::Vector3 mV; 
		math::Vector3 mW;

		real mLensRadius;
	};
} } // BAM::graphics

#endif //BAM_CAMERA_H