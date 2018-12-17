// testProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <vector>
#include <random>

#include "precision.h"
#include "type/math/Vector3.h"
#include "type/graphics/Ray.h"
#include "type/graphics/material/Material.h"
#include "type/graphics/material/Lambertian.h"
#include "type/graphics/material/Dielectric.h"
#include "type/graphics/material/Metal.h"
#include "type/graphics/hitable/HitableList.h"
#include "type/graphics/hitable/BVHNode.h"
#include "type/graphics/hitable/Sphere.h"
#include "type/graphics/Camera.h"

#include "bam_math.h"

using namespace BAM;
using namespace BAM::math;
using namespace BAM::graphics;
using namespace std;

Hitable* randomScene() {
	vector<Hitable*> list;
	list.push_back(new Sphere(Vector3(0, -1000, 0), 1000, new Lambertian(Vector3(0.5, 0.5, 0.5))));
	for (int a = -11; a < 11; ++a) {
		for (int b = -11; b < 11; ++b) {
			real choose_mat = UniformRand();
			Vector3 center(a + 0.9*UniformRand(), 0.2, b + 0.9*UniformRand());
			if ((center - Vector3(4, 0.2, 0)).Magnitude() > 0.9) {
				if (choose_mat < 0.8) {
					list.push_back(new Sphere(center, 0.2, new Lambertian(Vector3(UniformRand()*UniformRand(), UniformRand()*UniformRand(), UniformRand()*UniformRand()))));
				}
				else if (choose_mat < 0.95) {
					list.push_back(new Sphere(center, 0.2, new Metal(Vector3(0.5*(1.0 + UniformRand()), 0.5*(1.0 + UniformRand()), 0.5*(1.0 + UniformRand())), 0.5*UniformRand())));
				}
				else {
					list.push_back(new Sphere(center, 0.2, new Dielectric(1.5)));
				}
			}
		}
	}
	
	list.push_back(new Sphere(Vector3(0, 1, 0), 1.0, new Dielectric(1.5)));
	list.push_back(new Sphere(Vector3(-4, 1, 0), 1.0, new Lambertian(Vector3(0.4, 0.2, 0.1))));
	list.push_back(new Sphere(Vector3(4, 1, 0), 1.0, new Metal(Vector3(0.7, 0.6, 0.5), 0.0)));
	return new BVHNode(list,0.0,0.0);
}

Vector3 color(const Ray& ray, Hitable* world, int depth) {
	HitRecord rec;
	if (world->Hit(ray, real(0.001), REAL_MAX, rec)) {
		Ray scatteredRay;
		Vector3 attenuation;
		if (depth < 50 && rec.mMaterialPtr->Scatter(ray, rec, attenuation, scatteredRay)) {
			return attenuation * color(scatteredRay, world, depth + 1);
		}
		else {
			return Vector3();
		}
	}
	else {
		Vector3 unitD = UnitVector(ray.Direction());
		real t = REAL_HALF * unitD.mY + REAL_HALF;
		return (REAL_ONE - t)*Vector3(REAL_ONE, REAL_ONE, REAL_ONE) + t * Vector3(0.5, 0.7, 1.0);
	}
}

int main()
{
	int nx = 200;
	int ny = 100;
	int ns = 100;

	ofstream os = ofstream("outfile.ppm");

	os << "P3\n" << nx << " " << ny << "\n255\n";

	Hitable* world = randomScene();

	Vector3 lookFrom(15, 2, 3);
	Vector3 lookTo(2, 0, 0);
	real distToFocus = (lookFrom - lookTo).Magnitude();
	real aperature = 0.0;

	Camera cam = Camera(lookFrom, lookTo, Vector3(0, 1, 0), 20, real(nx) / real(ny), aperature, distToFocus);

	for (int j = ny - 1; j >= 0; --j) {
		for (int i = 0; i < nx; ++i) {
			Vector3 col = Vector3();
			for (int s = 0; s < ns; ++s) {
				real u = real(i + UniformRand()) / real(nx);
				real v = real(j + UniformRand()) / real(ny);

				Ray r = cam.RayAtUV(u, v);
				col += color(r, world, 0);
			}

			col /= real(ns);
			col = Vector3(realSqrt(col[0]), realSqrt(col[1]), realSqrt(col[2]));

			int ir = int(255.99*col.mX);
			int ig = int(255.99*col.mY);
			int ib = int(255.99*col.mZ);

			os << ir << " " << ig << " " << ib << "\n";

		}
	}

	return 0;
}
