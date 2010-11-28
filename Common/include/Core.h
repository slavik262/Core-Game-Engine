#pragma once

#include <CollisionDetector.h>
#include <ComponentManager.h>
#include <CoreBase.h>
#include <CoreConstants.h>
#include <CoreConversions.h>
#include <CoreTransform.h>
#include <CoreTypes.h>
#include <DeviceContext.h>
#include <ErrorHandling.h>
#include <GameComponent.h>
#include <GameMotionState.h>
#include <GameObject.h>
#include <GameObjectManager.h>
#include <GlobalContext.h>
#include <IterativeManifoldCollisionDetector.h>
#include <LibraryPragmas.h>
#include <LogicComponent.h>
#include <MapPhysicsManager.h>
#include <NamedClass.h>
#include <Paths.h>
#include <PhysicsComponent.h>
#include <PhysicsManager.h>
#include <PointerKey.h>
#include <RefCountedTreeNode.h>
#include <Scene.h>
#include <ScreenQuad.h>
#include <ThrusterData.h>

#ifdef CORE_DLL
#define DLL_LINKAGE __declspec(dllexport)
#else
#define DLL_LINKAGE __declspec(dllimport)
#endif

#define CORE_DLL_CALLCONV __cdecl

namespace Core
{
	extern "C" DLL_LINKAGE CoreBase* CORE_DLL_CALLCONV CreateCoreBase();
}