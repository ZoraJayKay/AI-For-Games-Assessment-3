#include "FollowBehaviour.h"
#include "Agent.h"

namespace AIForGames {
	FollowBehaviour::FollowBehaviour() {};
	FollowBehaviour::~FollowBehaviour() {};

	void FollowBehaviour::Update(Agent* agent, float deltaTime) {		
		// Retrieve the target agent
		Agent* target = agent->GetTarget();

		// Check the distance between the target agent's current position and the last position we pathed to
		float distance = glm::distance(target->GetPosition(), lastTargetPosition);

		// If the distance differs by more than one node, re-calculate the path
		if (distance > AIForGames::sizeOfCell) {
			// Print text
			agent->SetStateText("Following");

			lastTargetPosition = target->GetPosition();
			agent->GoTo(lastTargetPosition);
		}
	};
}