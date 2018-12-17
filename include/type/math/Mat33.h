#ifndef BAM_MAT33_H
#define BAM_MAT33_H

#include <assert.h>

#include "type\math\Vector3.h"


namespace BAM { namespace math {
	class Mat33 {
	public: 
		Mat33(void) 
			: mXX(REAL_ZERO), mXY(REAL_ZERO), mXZ(REAL_ZERO), 
			  mYX(REAL_ZERO), mYY(REAL_ZERO), mYZ(REAL_ZERO), 
			  mZX(REAL_ZERO), mZY(REAL_ZERO), mZZ(REAL_ZERO) {}

		Mat33(const real xxDef, const real xyDef, const real xzDef,     
			  const real yxDef, const real yyDef, const real yzDef,
			  const real zxDef, const real zyDef, const real zzDef) 
			: mXX(xxDef), mXY(xyDef), mXZ(xzDef), 
		 	  mYX(yxDef), mYY(yyDef), mYZ(yzDef),
		      mZX(zxDef), mZY(zyDef), mZZ(zzDef) {}

		Mat33(const Vector3& row0, const Vector3& row1, const Vector3& row2) 
			: mXX(row0.mX), mXY(row0.mY), mXZ(row0.mZ),
			  mYX(row1.mX), mYY(row1.mY), mYZ(row1.mZ), 
		      mZX(row2.mX), mZY(row2.mY), mZZ(row2.mZ) {}

		inline void	SetRow(const int index, const Vector3& that) {
			assert(index == 0 || index == 1 || index == 2);
			switch (index) {
			case 0:
				mXX = that.mX;
				mXY = that.mY; 
				mXZ = that.mZ; 
				break;
			case 1: 
				mYX = that.mX; 
				mYY = that.mY; 
				mYZ = that.mZ; 
				break;
			case 2: 
				mZX = that.mX;
				mZY = that.mY; 
				mZZ = that.mZ;
				break;
			default: 
				break;
			}
		}
		inline void SetColumn(const int index, const Vector3& that) {
			assert(index == 0 || index == 1 || index == 2);
			switch (index) {
			case 0:
				mXX = that.mX;
				mYX = that.mY; 
				mZX = that.mZ; 
				break;
			case 1: 
				mXY = that.mX; 
				mYY = that.mY; 
				mZY = that.mZ; 
				break;
			case 2: 
				mXZ = that.mX;
				mYZ = that.mY; 
				mZZ = that.mZ;
				break;
			default: 
				break;
			}
		}

		inline Vector3 GetRow(const int index) const {
			assert(index == 0 || index == 1 || index == 2);
			switch(index) {
			case 0: 
				return Vector3(mXX,mXY,mXZ);
			case 1: 
				return Vector3(mYX,mYY,mYZ);
			case 2: 
				return Vector3(mZX,mZY,mZZ);
			default:
				return Vector3(); //Should never get here due to assert
			}
		}
		inline Vector3 GetColumn(const int index) const {
			assert(index == 0 || index == 1 || index == 2);
			switch(index) {
			case 0: 
				return Vector3(mXX,mYX,mZX);
			case 1: 
				return Vector3(mXY,mYY,mZY);
			case 2: 
				return Vector3(mXZ,mYZ,mZZ);
			default: 
				return Vector3(); //Should never get here due to assert
			}
		}

		inline Mat33&    operator+=(const Mat33& that) {
			mXX += that.mXX;
			mXY += that.mXY; 
			mXZ += that.mXZ; 
			mYX += that.mYX;
			mYY += that.mYY;
			mYZ += that.mYZ; 
			mZX += that.mZX; 
			mZY += that.mZY; 
			mZZ += that.mZZ;
			return *this;
		}
		inline Mat33&   operator-=(const Mat33& that) {
			mXX -= that.mXX; 
			mXY -= that.mXY;
			mXZ -= that.mXZ; 
			mYX -= that.mYX; 
			mYY -= that.mYY;
			mYZ -= that.mYZ; 
			mZX -= that.mZX; 
			mZY -= that.mZY; 
			mZZ -= that.mZZ;
			return *this;
		} 
		inline Mat33&  operator*=(const real scale) {
			mXX *= scale; 
			mXY *= scale;
			mXZ *= scale; 
			mYX *= scale; 
			mYY *= scale;
			mYZ *= scale; 
			mZX *= scale; 
			mZY *= scale; 
			mZZ *= scale;
			return *this;
		}
		inline Mat33&  operator=(const Mat33& that) {
			mXX = that.mXX;
			mXY = that.mXY; 
			mXZ = that.mXZ; 
			mYX = that.mYX;
			mYY = that.mYY;
			mYZ = that.mYZ; 
			mZX = that.mZX; 
			mZY = that.mZY; 
			mZZ = that.mZZ;
			return *this;
		}

		real mXX;
		real mXY;
		real mXZ; 
		real mYX; 
		real mYY;
		real mYZ; 
		real mZX; 
		real mZY; 
		real mZZ; 
	};
} } // BAM::math

#endif // BAM_MAT33_H