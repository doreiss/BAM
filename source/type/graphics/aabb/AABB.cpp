#include "type/graphics/aabb/AABB.h"

BAM::graphics::AABB BAM::graphics::SurroundingBox(AABB box0, AABB box1) {
	math::Vector3 small(math::realMin(box0.Min().mX, box1.Min().mX), math::realMin(box0.Min().mY, box1.Min().mY), math::realMin(box0.Min().mZ, box1.Min().mZ));
	math::Vector3 big(math::realMax(box0.Max().mX, box1.Max().mX), math::realMax(box0.Max().mY, box1.Max().mY), math::realMax(box0.Max().mZ, box1.Max().mZ));
	return AABB(small, big);
}