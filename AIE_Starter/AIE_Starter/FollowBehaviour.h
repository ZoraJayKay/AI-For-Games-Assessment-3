#pragma once
#include "Behaviour.h"
#include <glm/glm.hpp>

namespace AIForGames {

	// A derived Behaviour class to follow the player
	class FollowBehaviour : public Behaviour {
	private:
		glm::vec2 lastTargetPosition;
		Agent* targetAgent;

	public:
		FollowBehaviour();
		~FollowBehaviour();

		void SetTarget(Agent* target);

		// This is a virtual void Update to override the pure virtual void Update in the base abstract class.
		virtual void Update(Agent* agent, float deltaTime);
		
		// Improvised function for when the destructor doesn't call because I'm using an Agent object rather than an Agent* - ONLY USED FOR SelectorBehaviour
		virtual void DestroyPointers() {};
	};
}
