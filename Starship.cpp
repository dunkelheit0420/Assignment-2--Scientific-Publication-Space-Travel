//	SEP101 - ASSIGNMENT 2
//	Starship.cpp - program containing the function definitions for the starship class

//	Daryl Gonzales					Shay Symonette					Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			ssymonette@myseneca.ca			ykaraman1@myseneca.ca
//	111341251						148719248						110047255								

//	Task Log
//	5-Dec-25		S.Symonette		Created Starship.cpp file, finished the function definitions
//	6-Dec-25		S.Symonette		Updated function definitions to be consistent with Warbird.cpp, fixed bugs

#include "Starship.h"
#include <iostream>

using namespace std;

Starship::Starship(double fuel,
	double light,
	double massPassengers,
	double massCargo,
	double massWorkstations,
	int numTorpedoes,
	int numLasers) 
	: speed(0.0),
	distance(0.0),
	propulsion1(fuel, light),
	payload1(massPassengers, massCargo, massWorkstations),
	weapon1(numTorpedoes, numLasers) {}

bool Starship::ChangeSpeed(double speed) {
	bool ret = false;
	double energyRequired = 0.0;
	if (speed >= 0.0) {
		energyRequired = 0.5 * payload1.GetTotalMass() * (speed * speed);
		if (propulsion1.ConsumeFuel(energyRequired)) {
			this->speed = speed;
			ret = true;
		}
	}
	return ret;
}

void Starship::Travel(double time, double light) {
	if (light >= 0.0 && light <= 1.0 && time >= 0) {
		propulsion1.SetLightLevel(light);
		propulsion1.GenerateFuel(time);
		distance = distance + speed * time;
	}
}

bool Starship::FireTorpedo(int numTorpedoes) {
	bool ret = false;
	ret = weapon1.FireTorpedoes(numTorpedoes);
	return ret;
}

bool Starship::FireLaser(double time) {
	bool ret = false;
	double energyRequired = 0.0;
	// No need to check for time > 0 because FireLasers already handles this
	// and will return 0.0 energy required for negative time
	energyRequired = weapon1.FireLasers(time);
	ret = propulsion1.ConsumeFuel(energyRequired);
	return ret;
}

void Starship::GenerateReport() {
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "The starship is travelling at " << speed << "m/s and has travelled " << distance << " m." << endl;
	propulsion1.Report();
	payload1.Report();
	weapon1.Report();
}