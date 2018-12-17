#ifndef BAM_VECTOR3_H
#define BAM_VECTOR3_H

#include "type/math/Vector2.h"

namespace BAM { namespace math {

	#define VEC3_ZERO Vector3()

	class Vector3 : public Vector2 {
	public:
		Vector3(void) : Vector2(), mZ(REAL_ZERO), mW(REAL_ZERO) {}
		Vector3(const real& xDef,const real& yDef,const real& zDef) : Vector2(xDef,yDef), mZ(zDef), mW(REAL_ZERO) {}

		inline Vector3& Clear() {
			mX = REAL_ZERO;
			mY = REAL_ZERO;
			mZ = REAL_ZERO;
		}

		inline const Vector3& operator+() const { return *this; }
		inline Vector3 operator-() const { return Vector3(-mX, -mY, -mZ); }
		inline real operator[] (int i) const {
			assert(i <= 2);
			if (i == 0) {
				return mX;
			}
			if (i == 1) {
				return mY; 
			}
			if (i == 2) {
				return mZ;
			}
			return REAL_ZERO;
		}
		inline real& operator[](int i) {
			assert(i <= 2);
			if (i == 0) {
				return mX;
			}
			if (i == 1) {
				return mY;
			}
			if (i == 2) {
				return mZ;
			}
			else {
				return mW;
			}
		}
		
		inline Vector3& operator+=(const Vector3& that) {
			mX += that.mX; 
			mY += that.mY;
			mZ += that.mZ;
			return *this;
		}
		inline Vector3& operator-=(const Vector3& that) {
			mX -= that.mX; 
			mY -= that.mY; 
			mZ -= that.mZ;
			return*this;
		}
		inline Vector3& operator/=(const Vector3& that) {
			mX /= that.mX;
			mY /= that.mY;
			mZ /= that.mZ;
			return *this;
		}
		inline Vector3& operator*=(const Vector3& that) {
			mX *= that.mX;
			mY *= that.mY;
			mZ *= that.mZ;
			return *this;
		}
		inline Vector3& operator*=(const real& scale) {
			mX *= scale; 
			mY *= scale;
			mZ *= scale;
			return *this;
		}
		inline Vector3& operator/=(const real& scale) {
			mX /= scale;
			mY /= scale;
			mZ /= scale;
			return *this;
		}
		inline Vector3& operator=(const Vector3& that) {
			mX = that.mX; 
			mY = that.mY; 
			mZ = that.mZ;
			return *this;
		}

		inline real Magnitude(void) const { return realSqrt(mX*mX + mY*mY + mZ*mZ); }
		inline real SquaredMagnitude(void) const { return (mX*mX + mY * mY + mZ * mZ); }
		inline void Normalise(void) {
			real l = Magnitude();
			if (l > REAL_ZERO)
			{
				(*this) *= (REAL_ONE) / l;
			}
		}

		real mZ;

	protected:
		Vector3(const real& xDef,const real& yDef,const real& zDef, const real& wDef) : Vector2(xDef,yDef), mZ(zDef), mW(wDef) {}
		real mW;
	};

	inline std::istream& operator>>(std::istream& is, Vector3& v3) {
		is >> v3[0] >> v3[1] >> v3[2];
		return is;
	}
	inline std::ostream& operator<<(std::ostream& os, Vector3& v3) {
		os << v3.mX << " " <<  v3.mY << " " << v3.mZ;
		return os;
	}


} } // BAM::math

#endif // BAM_VECTOR3_H