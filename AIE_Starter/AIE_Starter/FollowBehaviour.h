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
	};
}
