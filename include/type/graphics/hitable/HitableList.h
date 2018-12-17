#ifndef BAM_HITABLE_LIST_H
#define BAM_HITABLE_LIST_H

#include <vector>
#include "type/graphics/hitable/Hitable.h"

namespace BAM { namespace graphics {

	class HitableList : public Hitable {
	public: 
		HitableList() {}
		HitableList(std::vector<Hitable*> l) : mList(l) {}
		virtual bool Hit(const Ray& r, real t_min, real t_max, HitRecord& rec) const override;
		virtual bool BoundingBox(real t0, real t1, AABB& box) const override;
		std::vector<Hitable*> mList; 
	};

} } // BAM::graphics

#endif //BAM_HITABLE_LIST_H