//	SEP101 - ASSIGNMENT 2
//	Warbird.cpp - program containing the function definitions for the warbird class

//	Daryl Gonzales					Shay Symonette					Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			ssymonette@myseneca.ca			ykaraman1@myseneca.ca
//	111341251						148719248						110047255								

//	Task Log
//	4-Dec-25		D. Gonzales		Created Warbird.cpp file, finished the function definitions
//	5-Dec-25		D. Gonzales		Updated some function definitions, fixed bugs in logic
//	6-Dec-25		D. Gonzales		Added an initializer list, finished writing comments, fixing bugs.

#include "Warbird.h"
#include <iostream>

using namespace std;

Warbird::Warbird(double fuel,
		double light,
		double massPassengers,
		double massCargo,
		double massWorkstations,
		int numTorpedoes,
		int numLasers)
	: speed(0.0),
	  distance(0.0),
	  propulsion1(fuel, light),
	  propulsion2(fuel, light),
	  payload(massPassengers, massCargo, massWorkstations),
	  weapon1(numTorpedoes, numLasers),
	  weapon2(numTorpedoes, numLasers){}

bool Warbird::ChangeSpeed(double deltaSpeed) {
	bool ret = false;
	double energyRequired = 0.0;
	// Increment current speed with the change in speed
	// Allow for negative values for deceleration
	speed += deltaSpeed;
	// We're going to check for negative overall speed and 
	// set this value to 0.0 instead
	if (speed < 0.0) speed = 0.0;
	else {
		energyRequired = (0.5 * payload.GetTotalMass() * deltaSpeed * deltaSpeed);
		// Split the energy required into the two propulsion systems
		if (propulsion1.ConsumeFuel(energyRequired / 2.0) && propulsion2.ConsumeFuel(energyRequired / 2.0)) {
			ret = true;
		}
	}
	return ret;
}

void Warbird::Travel(double time, double light) {
	if (light >= 0.0 && light <= 1.0 && time >= 0) {
		propulsion1.SetLightLevel(light);
		propulsion2.SetLightLevel(light);
		propulsion1.GenerateFuel(time);
		propulsion2.GenerateFuel(time);
		distance = distance + speed * time;
	}
}

bool Warbird::FireTorpedo(int numTorpedoes) {
	bool ret1 = false;
	bool ret2 = false;
	if (numTorpedoes >= 0) {
		// Check for odd amount of numTorpedoes
		int remainder = 0;
		int halfNumTorpedoes = 0;
		remainder = numTorpedoes % 2;
		halfNumTorpedoes = numTorpedoes / 2;
		// Try to balance the amount of torpedoes fired:
		if (weapon1.GetNumTorpedoes() >= weapon2.GetNumTorpedoes()) {
			ret1 = weapon1.FireTorpedoes(halfNumTorpedoes + remainder);
			ret2 = weapon2.FireTorpedoes(halfNumTorpedoes);
		}
		else {
			ret1 = weapon1.FireTorpedoes(halfNumTorpedoes);
			ret2 = weapon2.FireTorpedoes(halfNumTorpedoes + remainder);
		}
	}
	// Return true only if both weapon systems are able to fire
	// which ensures total numTorpedoes are fired
	return ret1 && ret2;
}

bool Warbird::FireLaser(double time) {
	bool ret = false;
	double energyRequired1 = 0.0;
	double energyRequired2 = 0.0;
	// No need to check for time > 0 because FireLasers already handles this
	// and will return 0.0 energy required for negative time
	energyRequired1 = weapon1.FireLasers(time);
	energyRequired2 = weapon2.FireLasers(time);
	// Optionally we can have || instead of && so that in case one of the propulsion
	// system/weapon system doesn't work, the other one will still try to fire.
	if (propulsion1.ConsumeFuel(energyRequired1) && propulsion2.ConsumeFuel(energyRequired2)) ret = true;
	return ret;
}

void Warbird::GenerateReport() {
	cout.setf(ios::fixed); 
	cout.precision(2);
	cout << "The warbird is travelling at " << speed << " m/s and has travelled " << distance << " m." << endl;
	propulsion1.Report();
	propulsion2.Report();
	payload.Report();
	weapon1.Report();
	weapon2.Report();
	cout << endl;
}