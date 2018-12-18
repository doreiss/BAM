#ifndef BAM_VECTOR2_H
#define BAM_VECTOR2_H

#include <iostream>
#include <assert.h>

#include "precision.h"

namespace BAM { namespace math {

	#define VEC2_ZERO Vector2()

	class Vector2 {
	public: 
		Vector2(void) 
			  : mX(REAL_ZERO), mY(REAL_ZERO) {}
		Vector2(const real xDef,const real yDef) 
			  : mX(xDef), mY(yDef) {}

		inline void Clear(void) {
			mX = REAL_ZERO; 
			mY = REAL_ZERO; 
		}

		inline const Vector2& operator+() const { return *this; }
		inline Vector2 operator-() const { return Vector2(-mX, -mY); }
		inline real operator[] (int i) const {
			assert(i <= 1);
			if (i == 0) {
				return mX;
			}
			else {
				return mY;
			}
		}
		inline real& operator[](int i) {
			assert(i <= 1);
			if (i == 0) {
				return mX;
			}
			else {
				return mY;
			}
		}


		inline Vector2&   operator+=(const Vector2& that) {
			mX += that.mX; 
			mY += that.mY;
			return *this;
		}
		inline Vector2&    operator-=(const Vector2& that) {
			mX -= that.mX; 
			mY -= that.mY;
			return *this;
		}
		inline Vector2&    operator*=(const real scale) {
			mX *= scale; 
			mY *= scale;
			return *this;
		}
		inline Vector2& operator/=(const real& scale) {
			mX /= scale;
			mY /= scale;
			return *this;
		}
		inline Vector2&    operator=(const Vector2& that) {
			mX = that.mX; 
			mY = that.mY;
			return *this;
		}

		inline real Magnitude(void) const {return realSqrt(mX*mX+mY*mY);}
		inline real SquaredMagnitude(void) const {return (mX*mX+mY*mY);}
		inline void Normalise(void) {
			real l = Magnitude();
			if (l > REAL_ZERO) 
			{
				(*this) *= (REAL_ONE)/l;
			}
		}
		 
		real mX;
		real mY; 
	};

	inline std::istream& operator>>(std::istream& is, Vector2& v2) {
		is >> v2[0] >> v2[1];
		return is;
	}
	inline std::ostream& operator<<(std::ostream& os, Vector2& v2) {
		os << v2.mX << " " << v2.mY;
		return os;
	}




} } // BAM::math

#endif // BAM_VECTOR2_H