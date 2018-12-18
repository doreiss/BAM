// testProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <vector>
#include <random>

#include "precision.h"
#include "type/graphics/Ray.h"
#include "type/graphics/material/Material.h"
#include "type/graphics/material/Lambertian.h"
#include "type/graphics/material/Dielectric.h"
#include "type/graphics/material/Metal.h"
#include "type/graphics/hitable/BVHNode.h"
#include "type/graphics/hitable/hitableobject/Sphere.h"
#include "type/graphics/Renderer.h"
#include "type/physics/body/Particle.h"
#include "type/physics/body/ParticleWorld.h"
#include "type/physics/force/ParticleForceGenerator.h"
#include "type/physics/force/ParticleGravity.h"

#include "bam_math.h"

using namespace BAM;
using namespace BAM::math;
using namespace BAM::graphics;
using namespace std;
using namespace BAM::physics;


//Hitable* randomScene() {
//	vector<Hitable*> list;
//	list.push_back(new Sphere(Vector3(0, -1000, 0), 1000, new Lambertian(Vector3(0.5, 0.5, 0.5))));
//	for (int a = -11; a < 11; ++a) {
//		for (int b = -11; b < 11; ++b) {
//			real choose_mat = UniformRand();
//			Vector3 center(a + 0.9*UniformRand(), 0.2, b + 0.9*UniformRand());
//			if ((center - Vector3(4, 0.2, 0)).Magnitude() > 0.9) {
//				if (choose_mat < 0.8) {
//					list.push_back(new Sphere(center, 0.2, new Lambertian(Vector3(UniformRand()*UniformRand(), UniformRand()*UniformRand(), UniformRand()*UniformRand()))));
//				}
//				else if (choose_mat < 0.95) {
//					list.push_back(new Sphere(center, 0.2, new Metal(Vector3(0.5*(1.0 + UniformRand()), 0.5*(1.0 + UniformRand()), 0.5*(1.0 + UniformRand())), 0.5*UniformRand())));
//				}
//				else {
//					list.push_back(new Sphere(center, 0.2, new Dielectric(1.5)));
//				}
//			}
//		}
//	}
//	
//	list.push_back(new Sphere(Vector3(0, 1, 0), 1.0, new Dielectric(1.5)));
//	list.push_back(new Sphere(Vector3(-4, 1, 0), 1.0, new Lambertian(Vector3(0.4, 0.2, 0.1))));
//	list.push_back(new Sphere(Vector3(4, 1, 0), 1.0, new Metal(Vector3(0.7, 0.6, 0.5), 0.0)));
//	return new BVHNode(list,0.0,0.0);
//}

int main() {

	math::Vector3 lookFrom(13, 2, 3);
	math::Vector3 lookAt(0, 0, 0);
	real fov = 20;

	Renderer r = Renderer(600,300,150,lookFrom,lookAt,fov);
	vector<Hitable*> list;
	list.push_back(new Sphere(Vector3(0, -1000, 0), 1000, new Lambertian(Vector3(0.5, 0.5, 0.5))));
	list.push_back(new Sphere(Vector3(4, 1, 0), 1.0, new Metal(Vector3(0.7, 0.6, 0.5), 0.0)));
	
	Vector3 initialPosition = Vector3(8, 6, 0);
	Vector3 initialVelocity = Vector3(0.0, 0.0, 0.0);
	Vector3 initialAcceleration = Vector3(0.0, 0.0, 0.0);

	Sphere* movingSphere = new Sphere(initialPosition, 0.5, new Lambertian(Vector3(1.0, 0.0, 0.0)));
	list.push_back(movingSphere);

	Particle* movingParticle = new Particle(initialPosition, initialVelocity, initialAcceleration,1.0,1.0);
	ParticleForceGenerator* pg = new ParticleGravity(Vector3(0.0, -9.8, 0.0));

	ParticleForceRegistry reg;
	reg.Add(movingParticle, pg);
	
	std::vector<Particle*> particles;
	particles.push_back(movingParticle);

	ParticleWorld particleWorld = ParticleWorld(particles, reg);
	for (int i = 0; i < 70; ++i) {
		Hitable* world = new BVHNode(list);
		particleWorld.startFrame();
		particleWorld.runPhysics(0.016);
		movingSphere->FollowParticle(movingParticle);
		r.GenerateFrame(world);
		delete world;
		cout << real(i) / real(69) << "%" << endl;
	}

	return 0;
}
