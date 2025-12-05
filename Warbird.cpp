//	SEP101 - ASSIGNMENT 2
//	Warbird.cpp - program containing the function definitions for the warbird class

//	Daryl Gonzales					Shay Symonette					Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			ssymonette@myseneca.ca			ykaraman1@myseneca.ca
//	111341251						148719248						110047255								

//	Task Log
//	4-Dec-25		D. Gonzales		Created Warbird.cpp file, finished the function definitions

#include "Warbird.h"
#include <iostream>

using namespace std;

Warbird::Warbird(double fuel,
		double light,
		double massPassengers,
		double massCargo,
		double massWorkstations,
		int numTorpedoes,
		int numLasers) {
	speed = 0.0;
	distance = 0.0;
	Propulsion propulsion1(fuel, light), propulsion2(fuel, light);
	Payload payload(massPassengers, massCargo, massWorkstations);
	Weapons weapon1(numTorpedoes, numLasers), weapon2(numTorpedoes, numLasers);
}

bool Warbird::ChangeSpeed(double speed) {
	bool ret = false;
	double energyRequired = 0.0;
	double totalMass = 0.0;
	if (speed >= 0) {
		totalMass = payload.GetMassPassengers() + payload.GetMassCargo() + payload.GetMassWorkstations();
	}
	energyRequired = (0.5 * totalMass * speed * speed);
	if (propulsion1.ConsumeFuel(energyRequired) && propulsion2.ConsumeFuel(energyRequired)) ret = true;
	return ret;
}

void Warbird::Travel(double time, double light) {
	if (light >= 0.0 && light < 1.0 && time >= 0) {
		propulsion1.SetLightLevel(light);
		propulsion2.SetLightLevel(light);
		propulsion1.GenerateFuel(time);
		propulsion2.GenerateFuel(time);
	}
}

bool Warbird::FireTorpedo(int numTorpedoes) {
	bool ret = false;
	if (weapon1.FireTorpedoes(numTorpedoes) && weapon2.FireTorpedoes(numTorpedoes)) ret = true;
	return ret;
}

bool Warbird::FireLaser(double time) {
	bool ret = false;
	if (weapon1.FireLasers(time) && weapon2.FireLasers(time)) ret = true;
	return ret;
}

void Warbird::GenerateReport() {
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "The war bird is travelling at " << speed << " m / s and has travelled " << distance << " m." << endl;
	propulsion1.Report();
	propulsion2.Report();
	payload.Report();
	weapon1.Report();
	weapon2.Report();
}