#include "type/graphics/hitable/HitableList.h"

bool BAM::graphics::HitableList::Hit(const Ray& r, real t_min, real t_max, HitRecord& rec) const {
	HitRecord tempRec;
	bool hitAny = false;
	real closestYet = t_max;
	for (std::list<Hitable*>::const_iterator it = mList.begin(); it != mList.end(); ++it) {
		if ((*it)->Hit(r, t_min, closestYet, tempRec)) {
			hitAny = true;
			closestYet = tempRec.mT;
			rec = tempRec;
		}
	}
	return hitAny;
}