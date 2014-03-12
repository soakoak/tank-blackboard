#pragma once

#include <iostream>

class FuelExpert : public Expert {
	
	public:
		FuelExpert() {};

		virtual TankBlackboard::Insistence getInsistence(TankBlackboard* blackboard) {
			TankBlackboard::Insistence insistence;

			if( blackboard->getFuelAmount() < 75) {
				insistence = TankBlackboard::HIGH;
			} else if( blackboard->getFuelAmount() < 150) {
				insistence = TankBlackboard::NORMAL;
			} else if( blackboard->getFuelAmount() < 300) {
				insistence = TankBlackboard::LOW;
			} else {
				insistence = TankBlackboard::NONE;
			}

			return insistence;
		}

		virtual void run(TankBlackboard* blackboard) {
			using std::cout;
			using std::endl;

			cout << "Tankataan" << endl;

			blackboard->setFuelAmount( blackboard->getFuelAmount() + 100);

			cout << "Tankissa nyt :" << blackboard->getFuelAmount() << endl;
		}
};