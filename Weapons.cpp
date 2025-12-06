//	SEP101 - ASSIGNMENT 2
//	Weapons.cpp - program containing the function definitions for the weapons class

//	Daryl Gonzales					Shay Symonette					Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			ssymonette@myseneca.ca			ykaraman1@myseneca.ca
//	111341251						148719248						110047255								

//	Task Log
//	4-Dec-25		E. Karaman		Created Weapons.cpp file, finished the function definitions
//	6-Dec-25		E. Karaman		Updated functions, fixed bugs

#include "Weapons.h"
#include <iostream>

using namespace std;

Weapons::Weapons() {
	numTorpedoes = 0;
	numLasers = 0;
}

Weapons::Weapons(int numTorpedoes, int numLasers) {
	if (numTorpedoes >= 0) {
		if (numTorpedoes <= MAX_TORPEDOES) {
			this->numTorpedoes = numTorpedoes;
		}
		else this->numTorpedoes = MAX_TORPEDOES;
	}
	else this->numTorpedoes = 0;

	if (numLasers >= 0) {
		if (numLasers <= MAX_LASERS) {
			this->numLasers = numLasers;
		}
		else this->numLasers = MAX_LASERS;
	}
	else this->numLasers = 0;
}

bool Weapons::FireTorpedoes(int numTorpedoes) {
	bool ret = false;
	if (numTorpedoes <= MAX_TORPEDOES && numTorpedoes >= 0 && numTorpedoes <= this->numTorpedoes) {
		this->numTorpedoes -= numTorpedoes;
		ret = true;
	}
	return ret;
}

double Weapons::FireLasers(double time) {
	double energyConsumed = 0.0;
	if (time >= 0.0) {
		energyConsumed = LASER_ENERGY_PER_SECOND * time * numLasers;
	}
	return energyConsumed;
}

void Weapons::AddTorpedoes(int numTorpedoes) {
	int totalTorpedoes = 0;
	if (numTorpedoes >= 0) {
		totalTorpedoes = this->numTorpedoes + numTorpedoes;
		if (totalTorpedoes <= MAX_TORPEDOES) {
			this->numTorpedoes = totalTorpedoes;
		}
		else this->numTorpedoes = MAX_TORPEDOES;
	}
}

void Weapons::AddLasers(int numLasers) {
	int totalLasers = 0;
	if (numLasers >= 0) {
		totalLasers = this->numLasers + numLasers;
		if (totalLasers <= MAX_LASERS) {
			this->numLasers = totalLasers;
		}
		else this->numLasers = MAX_LASERS;
	}
}

void Weapons::Report() const {
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "Weapon: number of laser cannons: " << numLasers << ", number of torpedoes : " << numTorpedoes << "." << endl;
}