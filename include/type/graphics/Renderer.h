#ifndef BAM_GRAPHICS_RENDERER_H
#define BAM_GRAPHICS_RENDERER_H

#include <string>
#include <fstream>

#include "bam_math.h"
#include "type/graphics/material/Material.h"
#include "type/graphics/Camera.h"
#include "type/graphics/hitable/Hitable.h"

namespace BAM { namespace graphics {
	math::Vector3 background(const math::Vector3& unitD) {
		real t = REAL_HALF * unitD.mY + REAL_HALF;
		return (REAL_ONE - t)*math::Vector3(REAL_ONE, REAL_ONE, REAL_ONE) + t * math::Vector3(0.5, 0.7, 1.0);
	}

	class Renderer {
	public: 

		Renderer(int x, int y, int s, math::Vector3 lookFrom, math::Vector3 lookTo, real vFov, math::Vector3 viewUp = math::Vector3(REAL_ZERO,REAL_ONE,REAL_ZERO), real aperature = 0.0) {
			mX = x;
			mY = y;
			mS = s;

			real distToFocus = (lookFrom - lookTo).Magnitude();
			
			mCamera = new Camera(lookFrom, lookTo, viewUp, vFov, real(mX) / real(mY), aperature, distToFocus);

			mFrame = 0;
			mFileNameSuffix = "testRender";

			mBackground = background;

		}

		void GenerateFrame(Hitable* world) {
			std::string filename = "frames\\"+mFileNameSuffix + "_" + std::to_string(mFrame) + ".ppm";
			mOS.open(filename);
			mOS << "P3\n" << mX << " " << mY << "\n255\n";
			for (int j = mY - 1; j >= 0; --j) {
				for (int i = 0; i < mX; ++i) {
					math::Vector3 col = math::Vector3();
					for (int s = 0; s < mS; ++s) {
						real u = real(i + math::UniformRand()) / real(mX);
						real v = real(j + math::UniformRand()) / real(mY);
				
						Ray r = mCamera->RayAtUV(u, v);
						col += Color(r, world, 0);
					}
				
					col /= real(mS);
					col = math::Vector3(realSqrt(col[0]), realSqrt(col[1]), realSqrt(col[2]));
				
					int ir = int(255.99*col.mX);
					int ig = int(255.99*col.mY);
					int ib = int(255.99*col.mZ);
					
					mOS << ir << " " << ig << " " << ib << "\n";			
					}
				}
			mOS.close();
			mFrame++;
	}
	private:
		math::Vector3 Color(const Ray& ray, Hitable* world, int depth) {
			HitRecord rec;
			if (world->Hit(ray, real(0.001), REAL_MAX, rec)) {
				Ray scatteredRay;
				math::Vector3 attenuation;
				if (depth < 50 && rec.mMaterialPtr->Scatter(ray, rec, attenuation, scatteredRay)) {
					return attenuation * Color(scatteredRay, world, depth + 1);
				}
				else {
					return math::Vector3();
				}
			}
			else {
				math::Vector3 unitD = math::UnitVector(ray.Direction());
				return mBackground(unitD);
			}
		}
		
		int mX;
		int mY;
		int mS;
		
		std::string mFileNameSuffix;
		std::ofstream mOS;
		
		int mFrame;
		Camera* mCamera;
		
		math::Vector3(*mBackground)(const math::Vector3&);
	};

} } // BAM::graphics

#endif //BAM_RAY_H#pragma once
