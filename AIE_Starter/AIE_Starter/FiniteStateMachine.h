#pragma once
#include <vector>
#include "Behaviour.h"

// The FSM stores a lists of all possible States

namespace AIForGames {
	class State;
	class Agent;

	class FiniteStateMachine : public Behaviour {
	public:
		FiniteStateMachine();
		~FiniteStateMachine();

	private:
		// The collection of all possible States
		std::vector<State*> m_states;

		// The current State of the Finite State Machine
		State* m_currentState;

		// 
		State* m_newState;

		// This is a virtual void Update so the State's Behaviours can override the pure virtual void Update in the base abstract Behaviour class.
		virtual void Update(Agent* agent, float deltaTime);
	};
}