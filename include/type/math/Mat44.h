#ifndef BAM_MAT44_H
#define BAM_MAT44_H

#include <iostream>
#include <assert.h>

#include "precision.h"

namespace BAM { namespace math {
	class Mat44 {
	public: 
		Mat44(void) 
			: mXX(REAL_ZERO), mXY(REAL_ZERO), mXZ(REAL_ZERO), mXW(REAL_ZERO),
			mYX(REAL_ZERO), mYY(REAL_ZERO), mYZ(REAL_ZERO), mYW(REAL_ZERO),
			mZX(REAL_ZERO), mZY(REAL_ZERO), mZZ(REAL_ZERO), mZW(REAL_ZERO),
			mWX(REAL_ZERO), mWY(REAL_ZERO), mWZ(REAL_ZERO), mWW(REAL_ZERO) {}

		Mat44(const real xxDef, const real xyDef, const real xzDef, const real xwDef,     
			  const real yxDef, const real yyDef, const real yzDef, const real ywDef,
			  const real zxDef, const real zyDef, const real zzDef, const real zwDef,
			  const real wxDef, const real wyDef, const real wzDef, const real wwDef)
			: mXX(xxDef), mXY(xyDef), mXZ(xzDef), mXW(xwDef),
		 	  mYX(yxDef), mYY(yyDef), mYZ(yzDef), mYW(ywDef),
		      mZX(zxDef), mZY(zyDef), mZZ(zzDef), mZW(zwDef),
			  mWX(wxDef), mWY(wyDef), mWZ(wzDef), mWW(wwDef) {}


		inline Mat44&    operator+=(const Mat44& that) {
			mXX += that.mXX;
			mXY += that.mXY; 
			mXZ += that.mXZ; 
			mXW += that.mXW;
			mYX += that.mYX;
			mYY += that.mYY;
			mYZ += that.mYZ;
			mYW += that.mYW;
			mZX += that.mZX; 
			mZY += that.mZY; 
			mZZ += that.mZZ;
			mZW += that.mZW;
			mWX += that.mWX;
			mWY += that.mWY;
			mWZ += that.mWZ;
			mWW += that.mWW;
			return *this;
		}
		
		inline Mat44&    operator-=(const Mat44& that) {
			mXX -= that.mXX;
			mXY -= that.mXY;
			mXZ -= that.mXZ;
			mXW -= that.mXW;
			mYX -= that.mYX;
			mYY -= that.mYY;
			mYZ -= that.mYZ;
			mYW -= that.mYW;
			mZX -= that.mZX;
			mZY -= that.mZY;
			mZZ -= that.mZZ;
			mZW -= that.mZW;
			mWX -= that.mWX;
			mWY -= that.mWY;
			mWZ -= that.mWZ;
			mWW -= that.mWW;
			return *this;
		}
		
		inline Mat44&    operator*=(const real scale) {
			mXX *= scale;
			mXY *= scale;
			mXZ *= scale;
			mXW *= scale;
			mYX *= scale;
			mYY *= scale;
			mYZ *= scale;
			mYW *= scale;
			mZX *= scale;
			mZY *= scale;
			mZZ *= scale;
			mZW *= scale;
			mWX *= scale;
			mWY *= scale;
			mWZ *= scale;
			mWW *= scale;
			return *this;
		}

		inline Mat44&  operator=(const Mat44& that) {
			mXX = that.mXX;
			mXY = that.mXY;
			mXZ = that.mXZ;
			mXW = that.mXW;
			mYX = that.mYX;
			mYY = that.mYY;
			mYZ = that.mYZ;
			mYW = that.mYW;
			mZX = that.mZX;
			mZY = that.mZY;
			mZZ = that.mZZ;
			mZW = that.mZW;
			mWX = that.mWX;
			mWY = that.mWY;
			mWZ = that.mWZ;
			mWW = that.mWW;
			return *this;
		}

		real mXX;
		real mXY;
		real mXZ;
		real mXW;
		real mYX; 
		real mYY;
		real mYZ;
		real mYW;
		real mZX; 
		real mZY; 
		real mZZ;
		real mZW;
		real mWX;
		real mWY;
		real mWZ;
		real mWW;
	};

	inline std::ostream& operator<<(std::ostream& os, Mat44& m) {
		os << m.mXX << " " << m.mXY << " " << m.mXZ << " " << m.mXW << std::endl
		   << m.mYX << " " << m.mYY << " " << m.mYZ << " " << m.mYW << std::endl
		   << m.mZX << " " << m.mZY << " " << m.mZZ << " " << m.mZW << std::endl
		   << m.mWX << " " << m.mWY << " " << m.mWZ << " " << m.mWW;
		return os;
	}


} } // BAM::math

#endif // BAM_MAT44_H