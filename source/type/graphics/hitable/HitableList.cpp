#include "type/graphics/hitable/HitableList.h"

bool BAM::graphics::HitableList::Hit(const Ray& r, real t_min, real t_max, HitRecord& rec) const {
	HitRecord tempRec;
	bool hitAny = false;
	real closestYet = t_max;
	for (std::vector<Hitable*>::const_iterator it = mList.begin(); it != mList.end(); ++it) {
		if ((*it)->Hit(r, t_min, closestYet, tempRec)) {
			hitAny = true;
			closestYet = tempRec.mT;
			rec = tempRec;
		}
	}
	return hitAny;
}

bool BAM::graphics::HitableList::BoundingBox(real t0, real t1, AABB & box) const {
	if (mList.size() < 1) {
		return false;
	}

	AABB tempBox; 
	std::vector<Hitable*>::const_iterator it = mList.begin();
	bool firstTrue = (*it)->BoundingBox(t0, t1, tempBox);
	if (!firstTrue) {
		return false;
	}
	else {
		box = tempBox;
	}
	++it;
	for (; it != mList.end(); ++it) {
		if((*it)->BoundingBox(t0,t1,tempBox)){
			box = SurroundingBox(box, tempBox);
		}
		else {
			return false;
		}
	}
	return true;
}