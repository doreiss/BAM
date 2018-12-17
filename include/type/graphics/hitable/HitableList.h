#ifndef BAM_HITABLE_LIST_H
#define BAM_HITABLE_LIST_H

#include <list>
#include "type/graphics/hitable/Hitable.h"

namespace BAM { namespace graphics {

	class HitableList : public Hitable {
	public: 
		HitableList() {}
		HitableList(std::list<Hitable*> l) : mList(l) {}
		virtual bool Hit(const Ray& r, real t_min, real t_max, HitRecord& rec) const override;
		std::list<Hitable*> mList; 
	};

} } // BAM::graphics

#endif //BAM_HITABLE_LIST_H