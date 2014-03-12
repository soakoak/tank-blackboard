#pragma once

#include "blackboard.h"

class Expert {
	public:
		Expert() {};

		virtual TankBlackboard::Insistence getInsistence(TankBlackboard* blackboard) {

			return TankBlackboard::NONE;
		}

		virtual void run(TankBlackboard* blackboard) {

		}
};