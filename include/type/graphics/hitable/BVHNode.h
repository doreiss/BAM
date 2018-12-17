#ifndef BAM_HITABLE_BVHNODE_H
#define BAM_HITABLE_BVHNODE_H

#include <vector>
#include "Hitable.h"

namespace BAM { namespace graphics {

	class BVHNode : public Hitable {
	public:
		BVHNode() {}
		BVHNode(std::vector<Hitable*> l, real time0, real time1);
		virtual bool Hit(const Ray& r, real t_min, real t_max, HitRecord& rec) const override;
		virtual bool BoundingBox(real t0, real t1, AABB& box) const override;
		Hitable* mLeftChild;
		Hitable* mRightChild;
		AABB mBox;
	};

	bool BoxXAxisCompare(const Hitable* a, const Hitable* b);
	bool BoxYAxisCompare(const Hitable* a, const Hitable* b);
	bool BoxZAxisCompare(const Hitable* a, const Hitable* b);

} } // BAM::graphics

#endif
