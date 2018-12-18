#ifndef BAM_QUATERNION_H
#define BAM_QUATERNION_H

#include <iostream>
#include <assert.h>

#include "precision.h"

namespace BAM { namespace math {

	class Quaternion {
	public:
		Quaternion() : mX(REAL_ZERO), mY(REAL_ZERO), mZ(REAL_ZERO), mW(REAL_ZERO) {}
		Quaternion(real x, real y, real z, real w) : mX(x), mY(y), mZ(z), mW(w) {}

		inline void Clear(void) {
			mX = REAL_ZERO;
			mY = REAL_ZERO;
			mZ = REAL_ZERO;
			mW = REAL_ZERO;
		}

		inline const Quaternion& operator+() const { return *this; }
		inline Quaternion operator-() const { return Quaternion(-mX, -mY, -mZ, -mW); }
		inline real operator[] (int i) const {
			assert(i <= 3);
			if (i == 0) {
				return mX;
			}
			else if (i == 1) {
				return mY;
			}
			else if (i == 2) {
				return mZ;
			}
			else {
				return mW;
			}
		}
		inline real& operator[](int i) {
			assert(i <= 3);
			if (i == 0) {
				return mX;
			}
			else if (i == 1) {
				return mY;
			}
			else if (i == 2) {
				return mZ;
			}
			else {
				return mW;
			}
		}


		inline Quaternion&   operator+=(const Quaternion& that) {
			mX += that.mX;
			mY += that.mY;
			mZ += that.mZ;
			mW += that.mW;
			return *this;
		}
		inline Quaternion&   operator-=(const Quaternion& that) {
			mX -= that.mX;
			mY -= that.mY;
			mZ -= that.mZ;
			mW -= that.mW;
			return *this;
		}
		inline Quaternion&   operator*=(const Quaternion& that) {
			real x = mW * that.mX + mX * that.mW + mY * that.mZ - mZ * that.mY;
			real y = mW * that.mY - mX * that.mZ + mY * that.mW + mZ * that.mX;
			real z = mW * that.mZ + mX * that.mY - mY * that.mX + mZ * that.mW;
			real w = mW * that.mW - mX * that.mX - mY * that.mY - mZ * that.mZ;
			mX = x;
			mY = y; 
			mZ = z;
			mW = w; 
			return *this;
		}
		inline Quaternion&    operator=(const Quaternion& that) {
			mX = that.mX;
			mY = that.mY;
			mZ = that.mZ;
			mW = that.mW;
			return *this;
		}

		real mX; 
		real mY; 
		real mZ;
		real mW;
	};

	inline std::istream& operator>>(std::istream& is, Quaternion& q) {
		is >> q[0] >> q[1] >> q[2] >> q[3];
		return is;
	}

	inline std::ostream& operator<<(std::ostream& os, Quaternion& q) {
		os << q.mX << " " << q.mY << " " << q.mZ << " " << q.mW;
		return os;
	}
} } // BAM::math

#endif // BAM_QUATERNION_H
