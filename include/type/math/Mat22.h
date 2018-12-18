#ifndef BAM_MAT22_H
#define BAM_MAT22_H

#include <assert.h>

#include "type/math/Vector2.h"


namespace BAM { namespace math {
	class Mat22 {
	public: 
		Mat22(void) 
			: mXX(REAL_ZERO), mXY(REAL_ZERO), 
			  mYX(REAL_ZERO), mYY(REAL_ZERO) {}
		
		Mat22(const real xxDef, const real xyDef,      
			  const real yxDef, const real yyDef) 
			: mXX(xxDef), mXY(xyDef), 
			  mYX(yxDef), mYY(yyDef) {}
		
		Mat22(const Vector2& row0, const Vector2& row1) 
			: mXX(row0.mX), mXY(row0.mY), 
			  mYX(row1.mX), mYY(row1.mY) {}

		inline void SetRow(const int index, const Vector2& that) {
			assert(index == 0 || index == 1);
			switch(index) {
			case 0: 
				mXX = that.mX; 
				mXY = that.mY; 
				break;
			case 1:
				mYX = that.mX;
				mYY = that.mY; 
				break;
			default: 
				break;
			}
		}
		inline void SetColumn(const int index, const Vector2& that) {
			assert(index == 0 || index == 1);
			switch(index) {
			case 0: 
				mXX = that.mX; 
				mYX = that.mY; 
				break;
			case 1: 
				mXY = that.mX; 
				mYY = that.mY; 
				break; 
			default: 
				break;
			}
		}

		inline Vector2 GetRow(const int index) const {
			assert(index == 0 || index == 1);
			switch(index) {
			case 0: 
				return Vector2(mXX,mXY);
			case 1: 
				return Vector2(mYX,mYY);
			default:
				return Vector2(); //Should never get here due to assert
			}
		}
		inline Vector2 GetColumn(const int index) const {
			assert(index == 0 || index == 1);
			switch(index) {
			case 0: 
				return Vector2(mXX,mYX);
			case 1: 
				return Vector2(mXY,mYY);
			default: 
				return Vector2(); //Should never get here due to assert
			}
		}

		inline Mat22& operator+=(const Mat22& that) {
			mXX += that.mXX;
			mXY += that.mXY; 
			mYX += that.mYX;
			mYY += that.mYY;
			return *this;
		}
		inline Mat22& operator-=(const Mat22& that) {
			mXX -= that.mXX; 
			mXY -= that.mXY; 
			mYX -= that.mYX; 
			mYY -= that.mYY;
			return *this;
		} 
		inline Mat22& operator*=(const real scale) {
			mXX *= scale; 
			mXY *= scale;
			mYX *= scale; 
			mYY *= scale;
			return *this;
		}
		inline Mat22& operator=(const Mat22& that) {
			mXX = that.mXX;
			mXY = that.mXY; 
			mYX = that.mYX;
			mYY = that.mYY;
			return *this;
		}

		real mXX;
		real mXY;
		real mYX; 
		real mYY;
	};

	inline std::ostream& operator<<(std::ostream& os, Mat22& m) {
		os << m.mXX << " " << m.mXY << std::endl << m.mYX << " " << m.mYY;
		return os;
	}

} } // BAM::math

#endif // BAM_MAT22_H