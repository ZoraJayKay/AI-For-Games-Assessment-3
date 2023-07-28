#pragma once
#include <vector>
#include "Behaviour.h"

// The State has a collection of Behaviours, and a collection of Transitions. An example state might be a follow state, which holds a FollowBehaviour from last lab, and Conditions for when to switch to other states. We will not need to inherit from this class, but will put our game-specific logic into the Behaviours it references.

namespace AIForGames {
	class State {
	private:
		// A vector of Behaviour pointers (the base, abstract class) so that the collection can polymorphically hold its various derived classes of specific behaviours. The State owns these behaviours.
		std::vector<Behaviour*> m_behaviours;

	public:
		State();
		~State();

		// This is a virtual void Update to override the pure virtual void Update in the base abstract Behaviour class.
		virtual void Update(Agent* agent, float deltaTime);
	}
}