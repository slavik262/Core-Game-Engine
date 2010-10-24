#pragma once

#include <irrlicht.h>
using namespace irr;
using namespace core;
using namespace scene;

#include <btBulletDynamicsCommon.h>

namespace GameCore 
{
	//Thre base object for all game entities
	//Massive TODO: Chuck all the custom physics stuff and put in Bullet stuff.
	class GameEntity : public IReferenceCounted
	{
	public:

		GameEntity(ISceneNode* sceneNode,  btCollisionShape* cShape,
			const btTransform& trans = btTransform(), GameEntity* parentEnt = nullptr,
			s32 entId = -1, const stringc& entName = stringc());

		void SetParent(GameEntity* newParent);
		GameEntity* GetParent() const { return parent; }
		//Throws an exception if the pointer is null or
		//the child was already in the list
		void AddChild(GameEntity* newChild);
		//Throws an exception if the pointer is null or
		//the child was not in the list
		void RemoveChild(GameEntity* toRemove);
		void RemoveAllChildren();
		void RemoveFromParent(bool updateHD = true);
		//TODO: Get/Set Type?
		//TODO: Get/Set Motion controller
		//TODO: Get thrusterlist
		f32 getMass() const { return mass; }
		f32 getAbsoluteMass() const { return absoluteMass; }
		const vector3df& GetCOG() const { return cog; }
		const vector3df& GetAbsoluteCOG() const { return absoluteCOG; }
		const list<vector3df>& GetExternalForces() const { return externalForces; }
		list<vector3df>& GetExternalForces() { return externalForces; }
		const btTransform& getTransform() const { return transform; }
		btTransform& getTransform() { return transform; }
		void SetMass(f32 newMass) { mass = newMass; } 
		void SetCOG(const vector3df& newCOG) { cog = newCOG; }
		void SetTransform(const btTransform& newTransform) { transform = newTransform; }

		// Updates hierarchical data based on children.
		void UpdateHierarchicalData();

	protected:
		//Scene node we're attached to.
		ISceneNode* sNode;
		btCollisionShape* cShape;
		btCollisionShape* absoluteCShape;
		btTransform transform;

		GameEntity* parent;
		list<GameEntity*> children;
		//TODO: Add type field?
		//TODO: Add motion controller
		//TODO: Add thruster list
		f32 mass;
		//Mass of object plus any child entities
		f32 absoluteMass;
		//Center of gravity in local coordinates
		vector3df cog;
		//Center of gravity of entity with all children
		vector3df absoluteCOG;
		//Forces which would affect the velocity of the entity
		list<vector3df> externalForces;

		s32 id;
		stringc name;
	};
} //end namespace GameCore