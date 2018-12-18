#include <algorithm>
#include <iostream>
#include "type\graphics\hitable\BVHNode.h"

BAM::graphics::BVHNode::BVHNode(std::vector<Hitable*> l) {
	int axis = int(3 * math::UniformRand());
	if (axis == 0) {
		std::sort(l.begin(), l.end(), BoxXAxisCompare);
	}
	else if (axis == 1) {
		std::sort(l.begin(), l.end(), BoxYAxisCompare);
	}
	else {
		std::sort(l.begin(), l.end(), BoxZAxisCompare);
	}
	if (l.size() == 1) {
		mLeftChild = mRightChild = *l.begin();
	}
	else if (l.size() == 2) {
		mLeftChild = *l.begin();
		mRightChild = *(l.begin()+1);
	}
	else {
		std::size_t const halfSize = l.size() / 2;
		mLeftChild = new BVHNode(std::vector<Hitable*>(l.begin(),l.begin()+halfSize));
		mRightChild = new BVHNode(std::vector<Hitable*>(l.begin()+halfSize, l.end()));
	}
	AABB boxLeft, boxRight; 
	if (!mLeftChild->BoundingBox(boxLeft) || !mRightChild->BoundingBox(boxRight)) {
		std::cerr << "No bounding box in BVHNode constructor\n";
	}
	mBox = SurroundingBox(boxLeft, boxRight);
}

bool BAM::graphics::BVHNode::Hit(const Ray & r, real t_min, real t_max, HitRecord & rec) const {
	if (mBox.Hit(r, t_min, t_max)) {
		HitRecord leftRecord, rightRecord; 
		bool hitLeft = mLeftChild->Hit(r, t_min, t_max, leftRecord);
		bool hitRight = mRightChild->Hit(r, t_min, t_max, rightRecord);
		if (hitLeft && hitRight) {
			if (leftRecord.mT < rightRecord.mT) {
				rec = leftRecord;
			}
			else {
				rec = rightRecord;
			}
			return true;
		}
		else if (hitLeft) {
			rec = leftRecord;
			return true;
		}
		else if (hitRight) {
			rec = rightRecord;
			return true;
		}
		else {
			return false; 
		}
	}
	else {
		return false;
	}
}

bool BAM::graphics::BVHNode::BoundingBox(AABB & box) const {
	box = mBox;
	return true;
}

bool BAM::graphics::BoxXAxisCompare(const Hitable * a, const Hitable * b) {
	AABB boxLeft, boxRight;
	if (!a->BoundingBox(boxLeft) || !b->BoundingBox(boxRight)) {
		std::cerr << "No bounding box in BVHNode constructor\n";
	}
	if (boxLeft.Min().mX - boxRight.Min().mX < 0.0) {
		return false;
	}
	else {
		return true;
	}
}

bool BAM::graphics::BoxYAxisCompare(const Hitable * a, const Hitable * b)
{
	AABB boxLeft, boxRight;
	if (!a->BoundingBox(boxLeft) || !b->BoundingBox(boxRight)) {
		std::cerr << "No bounding box in BVHNode constructor\n";
	}
	if (boxLeft.Min().mY - boxRight.Min().mY < 0.0) {
		return false;
	}
	else {
		return true;
	}
}

bool BAM::graphics::BoxZAxisCompare(const Hitable * a, const Hitable * b)
{
	AABB boxLeft, boxRight;
	if (!a->BoundingBox( boxLeft) || !b->BoundingBox(boxRight)) {
		std::cerr << "No bounding box in BVHNode constructor\n";
	}
	if (boxLeft.Min().mZ - boxRight.Min().mZ < 0.0) {
		return false;
	}
	else {
		return true;
	}
}
