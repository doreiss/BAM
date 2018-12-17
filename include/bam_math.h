#ifndef BAM_MATH_H
#define BAM_MATH_H

#include <assert.h>
#include <cmath>
#include <random>

#include <precision.h>
#include <type/math/Vector2.h>
#include <type/math/Vector3.h>
#include <type/math/Mat22.h>
#include <type/math/Mat33.h>


namespace BAM {
	namespace math {

		inline real SqrtFast(const real&, const unsigned int& = 1);
		inline real RSqrtFast(const real& r, const unsigned int& it = 1) {
			assert(it <= 3);
			magic_int i;
			real x2, y;
			x2 = r * REAL_HALF;
			y = r;
			i = *(magic_int *)(&y);				// evil floating point bit level hacking
			i = REAL_SQRT_MAGIC - (i >> 1);         // what the fuck?
			y = *(real *)&i;
			for (unsigned int iteration = 0; iteration < it; ++iteration) {
				y = y * (REAL_THREEHALVES - (x2 * y * y));
			}
			return y;
		}


		// Vector2 operators and common functions

		inline Vector2 operator+(const Vector2& v1, const Vector2& v2) {
			return Vector2(v1.mX + v2.mX, v1.mY + v2.mY);
		}
		inline Vector2 operator-(const Vector2& v1, const Vector2& v2) {
			return Vector2(v1.mX - v2.mX, v1.mY - v2.mY);
		}
		inline Vector2 operator*(const Vector2& v1, const Vector2& v2) {
			return Vector2(v1.mX * v2.mX, v1.mY * v2.mY);
		}
		inline Vector2 operator/(const Vector2& v1, const Vector2& v2) {
			return Vector2(v1.mX / v2.mX, v1.mY / v2.mY);
		}
		inline Vector2 operator*(const real& scale, const Vector2& v) {
			return Vector2(scale*v.mX, scale*v.mY);
		}
		inline Vector2 operator*(const Vector2& v, const real& scale) {
			return Vector2(scale*v.mX, scale*v.mY);
		}
		inline Vector2 operator/(const Vector2& v, const real& scale) {
			return Vector2(v.mX / scale, v.mY / scale);
		}

		inline Vector2 UnitVector(const Vector2& v) {
			return v / v.Magnitude();
		}

		inline real Dot(const Vector2& v1, const Vector2& v2) {
			return (v1.mX*v2.mX
				+ v1.mY*v2.mY);
		}
		inline real Cross(const Vector2& v1, const Vector2& v2) {
			return (v1.mX*v2.mY
				- v1.mY*v2.mX);
		}

		// Vector3 operators and common functions

		inline Vector3 operator+(const Vector3& v1, const Vector3& v2) {
			return Vector3(v1.mX + v2.mX, v1.mY + v2.mY, v1.mZ + v2.mZ);
		}
		inline Vector3 operator-(const Vector3& v1, const Vector3& v2) {
			return Vector3(v1.mX - v2.mX, v1.mY - v2.mY, v1.mZ - v2.mZ);
		}
		inline Vector3 operator*(const Vector3& v1, const Vector3& v2) {
			return Vector3(v1.mX * v2.mX, v1.mY * v2.mY, v1.mZ * v2.mZ);
		}
		inline Vector3 operator/(const Vector3& v1, const Vector3& v2) {
			return Vector3(v1.mX / v2.mX, v1.mY / v2.mY, v1.mZ / v2.mZ);
		}
		inline Vector3 operator*(const real& scale, const Vector3& v) {
			return Vector3(scale*v.mX, scale*v.mY, scale*v.mZ);
		}
		inline Vector3 operator*(const Vector3& v, const real& scale) {
			return Vector3(scale*v.mX, scale*v.mY, scale*v.mZ);
		}
		inline Vector3 operator/(const Vector3& v, const real& scale) {
			return Vector3(v.mX / scale, v.mY / scale, v.mZ / scale);
		}

		inline Vector3 UnitVector(const Vector3& v3) {
			return v3 / v3.Magnitude();
		}

		inline real Dot(const Vector3& v1, const Vector3& v2) {
			return (v1.mX*v2.mX
				+ v1.mY*v2.mY
				+ v1.mZ*v2.mZ);
		}
		inline Vector3 Cross(const Vector3& v1, const Vector3& v2) {
			return Vector3(v1.mY*v2.mZ
				- v1.mZ*v2.mY, v1.mZ*v2.mX
				- v1.mX*v2.mZ, v1.mX*v2.mY
				- v1.mY*v2.mX);
		}

		// Mat22 operators and common functions

		inline Mat22 operator+(const Mat22& m1, const Mat22& m2) { return Mat22(m1.mXX + m2.mXX, m1.mXY + m2.mXY, m1.mYX + m2.mYX, m1.mYY + m2.mYY); }
		inline Mat22 operator-(const Mat22& m1, const Mat22& m2) { return Mat22(m1.mXX - m2.mXX, m1.mXY - m2.mXY, m1.mYX - m2.mYX, m1.mYY - m2.mYY); }
		inline Mat22 operator*(const Mat22& m, const real& scale) { return Mat22(m.mXX*scale, m.mXY*scale, m.mYX*scale, m.mYY*scale); }
		inline Mat22 operator*(const real& scale, const Mat22& m) { return Mat22(m.mXX*scale, m.mXY*scale, m.mYX*scale, m.mYY*scale); }

		inline Mat22   operator*(const Mat22& m1, const Mat22& m2) {
			return Mat22(m1.mXX * m2.mXX + m1.mXY * m2.mYX,
				m1.mXX * m2.mXY + m1.mXY * m2.mYY,
				m1.mYX * m2.mXX + m1.mYY * m2.mYX,
				m1.mYX * m2.mXY + m1.mYY * m2.mYY);
		}
		inline Vector2 operator*(const Mat22& m, const Vector2& that) {
			return Vector2(m.mXX * that.mX + m.mXY * that.mY, m.mYX * that.mX + m.mYY * that.mY);
		}


		// Mat33 operators and common functions

		inline Mat33   operator+(const Mat33& m1, const Mat33& m2) {
			return Mat33(m1.mXX + m2.mXX, m1.mXY + m2.mXY, m1.mXZ + m2.mXZ,
				m1.mYX + m2.mYX, m1.mYY + m2.mYY, m1.mYZ + m2.mYZ,
				m1.mZX + m2.mZX, m1.mZY + m2.mZY, m1.mZZ + m2.mZZ);
		}
		inline Mat33   operator-(const Mat33& m1, const Mat33& m2) {
			return Mat33(m1.mXX - m2.mXX, m1.mXY - m2.mXY, m1.mXZ - m2.mXZ,
				m1.mYX - m2.mYX, m1.mYY - m2.mYY, m1.mYZ - m2.mYZ,
				m1.mZX - m2.mZX, m1.mZY - m2.mZY, m1.mZZ - m2.mZZ);
		}

		inline Mat33   operator*(const Mat33& m, const real& scale) {
			return Mat33(m.mXX*scale, m.mXY*scale, m.mXZ*scale,
				m.mYX*scale, m.mYY*scale, m.mYZ*scale,
				m.mZX*scale, m.mZY*scale, m.mZZ*scale);
		}
		inline Mat33   operator*(const real& scale, const Mat33& m) {
			return Mat33(m.mXX*scale, m.mXY*scale, m.mXZ*scale,
				m.mYX*scale, m.mYY*scale, m.mYZ*scale,
				m.mZX*scale, m.mZY*scale, m.mZZ*scale);
		}
		inline Mat33   operator*(const Mat33& m1, const Mat33& m2) {
			return Mat33(m1.mXX *m2.mXX + m1.mXY *m2.mYX + m1.mXZ *m2.mZX,
				m1.mXX *m2.mXY + m1.mXY *m2.mYY + m1.mXZ *m2.mZY,
				m1.mXX *m2.mXZ + m1.mXY *m2.mYZ + m1.mXZ *m2.mZZ,
				m1.mYX *m2.mXX + m1.mYY *m2.mYX + m1.mYZ *m2.mZX,
				m1.mYX *m2.mXY + m1.mYY *m2.mYY + m1.mYZ *m2.mZY,
				m1.mYX *m2.mXZ + m1.mYY *m2.mYZ + m1.mYZ *m2.mZZ,
				m1.mZX *m2.mXX + m1.mZY *m2.mYX + m1.mZZ *m2.mZX,
				m1.mZX *m2.mXY + m1.mZY *m2.mYY + m1.mZZ *m2.mZY,
				m1.mZX *m2.mXZ + m1.mZY *m2.mYZ + m1.mZZ *m2.mZZ);
		}
		inline Vector3 operator*(const Mat33& m, const Vector3& that) {
			return Vector3(m.mXX * that.mX + m.mXY * that.mY + m.mXZ * that.mZ,
				m.mYX * that.mX + m.mYY * that.mY + m.mYZ * that.mZ,
				m.mZX * that.mX + m.mZY * that.mY + m.mZZ * that.mZ);
		}

		// Random functions

		inline real UniformRand() {
			thread_local static std::random_device rd;
			thread_local static std::mt19937 mt(rd());
			thread_local static std::uniform_real_distribution<real> dist(REAL_ZERO, REAL_ONE);

			return dist(mt);
		}

		Vector3 RandomWithinUnitDisc();
		Vector3 RandomWithinUnitSphere();


		// Reflection

		inline Vector2 Reflect(const Vector2& v, const Vector2& n) {
			return v - 2 * Dot(v, n)*n;
		}
		inline Vector3 Reflect(const Vector3& v, const Vector3& n) {
			return v - 2 * Dot(v, n)*n;
		}


		// Min and max - exception free

		inline real realMin(real a, real b) {
			return a < b ? a : b;
		}

		inline real realMax(real a, real b) {
			return a > b ? a : b;
		}


} } //BAM::math

#endif // BAM_MATH_H
