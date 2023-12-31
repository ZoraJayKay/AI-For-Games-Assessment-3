#include "WanderBehaviour.h"
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "Agent.h"

namespace AIForGames {
	WanderBehaviour::WanderBehaviour() {};
	WanderBehaviour::~WanderBehaviour() {};

	// An Update function to set an Agent and its PathAgent wandering the map randomly
	void WanderBehaviour::Update(Agent* agent, float deltaTime) {
		// If the Agent's PathAgent has navigated to the end of its path, pick another random node and go there.
		if (agent->PathComplete()) {
			// Print text
			agent->SetStateText("Wandering");

			// Record a random node in the NodeMap
			Node* randomNode = agent->GetMap()->GetRandomNode();
			// Instruct the agent to move to the coordinates of the random node
			agent->GoTo(glm::vec2(randomNode->position.x, randomNode->position.y));
		}
	};
}