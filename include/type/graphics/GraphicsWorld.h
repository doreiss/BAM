#ifndef BAM_GRAPHICS_GRAPHICS_WORLD_H
#define BAM_GRAPHICS_GRAPHICS_WORLD_H

#include <vector>

#include "type/graphics/hitable/hitableobject/HitableObject.h"
#include "type/graphics/hitable/HitableList.h"
#include "type/graphics/hitable/BVHNode.h"
#include "type/physics/body/Particle.h"

namespace BAM { namespace graphics {
		
	class GraphicsParticleRegistry {
	protected:
		struct GraphicsParticleRegistration {
			GraphicsParticleRegistration(HitableObject* hitable, physics::Particle* particle) :
				mHitable(hitable), mParticle(particle) {}
			HitableObject* mHitable;
			physics::Particle* mParticle;
		};
		typedef std::vector<GraphicsParticleRegistration*> GPRegistry;
		GPRegistry mRegistrations;
	public:
		GraphicsParticleRegistry() {}
		void Add(HitableObject* hitable, physics::Particle* particle) {
			mRegistrations.push_back(new GraphicsParticleRegistration(hitable, particle));
		}
		void Clear() {
			mRegistrations.clear();
		}
		void UpdateHitables() {
			GPRegistry::iterator it = mRegistrations.begin();
			for (; it != mRegistrations.end(); ++it) {
				(*it)->mHitable->Update((*it)->mParticle->mPosition);
			}
		}
	};

	class GraphicsWorld {
	public:
		GraphicsWorld(std::vector<Hitable*> hitables, GraphicsParticleRegistry reg) :
			mHitableList(hitables), mRegistry(reg), mBVH(new BVHNode(hitables)) {}
		void Update() {
			UpdateHitables();
			UpdateBVH();
		}
		Hitable* GetWorld() {
			return mBVH;
		}
	protected:
		void UpdateHitables() {
			mRegistry.UpdateHitables();
		}
		void UpdateBVH() {
			delete mBVH;
			mBVH = new BVHNode(mHitableList);
		}
		BVHNode* mBVH;
		std::vector<Hitable*> mHitableList;
		GraphicsParticleRegistry mRegistry;
	};

} } // BAM::physics

#endif //BAM_GRAPHICS_GRAPHICS_WORLD_H
