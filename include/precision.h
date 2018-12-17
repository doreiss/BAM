#ifndef BAM_PRECISION_H
#define BAM_PRECISION_H

#include <cmath>

namespace BAM {
	#define FLOAT_PRECISION

	#ifdef DOUBLE_PRECISION
	typedef double real;
	typedef long long magic_int;
	#define REAL_MAX		 DBL_MAX
	#define REAL_SQRT_MAGIC  0x5fe6ec85e7de30daLL 
	#define PI				 3.14159265358979323846
    #define realSqrt		 sqrt
	#define realAbs			 abs
	#define realSin			 sin
	#define realCos			 cos
	#define realTan			 tan
	#define realACos		 acos
	#define realASin		 asin
	#define realATan		 atan
	#define realATan2		 atan2
	#define realPow			 pow
	#define REAL_ZERO		 0.0
	#define REAL_ONE		 1.0
	#define REAL_TWO		 2.0
	#define REAL_THREE		 3.0
	#define REAL_FOUR		 4.0
	#define REAL_FIVE		 5.0
	#define REAL_HALF		 0.5
	#define REAL_THREEHALVES 1.5
	#define REAL_FIVEHALVES  2.5
	#define REAL_SEVENHALVES 3.5
	#define REAL_NINEHALVES  4.5
	#define REAL_MINUS_ONE  -1.0
	#define REAL_MINUS_TWO  -2.0
	#define REAL_HUNDRED_EIGHTY 180.0
	#define REAL_THOUSAND    1000.0
	#endif

	#ifdef FLOAT_PRECISION
	typedef float real;
	typedef long magic_int;
	#define REAL_MAX		 FLT_MAX
	#define REAL_SQRT_MAGIC  0x5f375a86 
	#define PI				 3.14159265358979323846f
	#define realSqrt		 sqrtf
	#define realAbs			 fabsf
	#define realSin			 sinf
	#define realCos			 cosf
	#define realTan			 tanf
	#define realACos		 acosf
	#define realASin		 asinf
	#define realATan		 atanf
	#define realATan2		 atan2f
	#define realPow			 powf
	#define realExp          expf
	#define REAL_ZERO		 0.0f
	#define REAL_ONE		 1.0f
	#define REAL_TWO		 2.0f
	#define REAL_THREE		 3.0f
	#define REAL_FOUR		 4.0f
	#define REAL_FIVE		 5.0f
	#define REAL_HALF		 0.5f
	#define REAL_THREEHALVES 1.5f
	#define REAL_FIVEHALVES  2.5f
	#define REAL_SEVENHALVES 3.5f
	#define REAL_NINEHALVES  4.5f
	#define REAL_MINUS_ONE  -1.0f
	#define REAL_MINUS_TWO  -2.0f
	#define REAL_HUNDRED_EIGHTY 180.0f
	#define REAL_THOUSAND    1000.f
	#endif

} //BAM

#endif //BAM_PRECISION_H