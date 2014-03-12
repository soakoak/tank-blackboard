#pragma once

#include <iostream>

class MovementExpert : public Expert {
	
	public:
		MovementExpert() {};

		virtual TankBlackboard::Insistence getInsistence(TankBlackboard* blackboard) {
			TankBlackboard::Insistence insistence;

			return TankBlackboard::NORMAL;
		}

		virtual void run(TankBlackboard* blackboard) {
			using std::cout;
			using std::endl;

			cout << "Liikutaan." << endl;

			blackboard->setFuelAmount( blackboard->getFuelAmount() - 80);

			cout << "Tankissa nyt :" << blackboard->getFuelAmount() << endl;
		}
};