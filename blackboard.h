#pragma once

class TankBlackboard {
	public:
		TankBlackboard() {};

		enum Insistence { 
			HIGH, NORMAL, LOW, NONE 
		};

		void setFuelAmount( double fuel) {
			_fuel = fuel;
		}

		int getFuelAmount() {
			return _fuel;
		}

	private:
		double _fuel;
};