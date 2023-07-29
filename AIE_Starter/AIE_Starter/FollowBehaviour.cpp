#include "FollowBehaviour.h"
#include "Agent.h"

namespace AIForGames {
	FollowBehaviour::FollowBehaviour() {};
	FollowBehaviour::~FollowBehaviour() {};

	void FollowBehaviour::Update(Agent* agent, float deltaTime) {		
		// Retrieve the target agent
		Agent* target = agent->GetTarget();

		// Check the distance between our position and the target agent's current position
		float distance = glm::distance(agent->GetPosition(), target->GetPosition());

		// If the distance differs by more than one node, re-calculate the path
		if (distance > AIForGames::sizeOfCell) {
			// Print text
			agent->SetStateText("Following");

			lastTargetPosition = target->GetPosition();
			agent->GoTo(lastTargetPosition);
		}
	};
}