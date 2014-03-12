#include <iostream>
#include <vector>

#include "blackboard.h"
#include "expert.h"
#include "gas_expert.h"
#include "move_expert.h"

int main() {
	using std::cout;
	using std::endl;
	using std::cin;

	TankBlackboard blackboard;

	FuelExpert fuelExp;
	MovementExpert moveExp;

	std::vector<Expert*> experts;
	experts.push_back( &fuelExp);
	experts.push_back( &moveExp);

	Expert* bestExpert;
	TankBlackboard::Insistence highestInsistence;

	bool cont = true;
	char retval;
	int i;

	cout << "Tervetuloa liitutauludemoon." << endl;

	while( cont) {
		bestExpert = NULL;
		highestInsistence = TankBlackboard::NONE;

		for( i = 0; i < experts.size(); i++) {
			TankBlackboard::Insistence insistence = experts[i]->getInsistence( &blackboard);

			if( insistence < highestInsistence) {
				highestInsistence = insistence;
				bestExpert = experts[i];
			}
		}

		if( bestExpert != NULL) {
			bestExpert->run( &blackboard);
		}

		cout << "Jatketaanko k/e?" << endl;
		cin >> retval;

		if( retval == 'e') {
			cont = false;
		}
	}

	return 0;
}