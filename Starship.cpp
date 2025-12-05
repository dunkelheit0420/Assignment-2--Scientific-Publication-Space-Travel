//	SEP101 - ASSIGNMENT 2
//	Starship.cpp - program containing the function definitions for the starship class

//	Daryl Gonzales					Shay Symonette					Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			ssymonette@myseneca.ca			ykaraman1@myseneca.ca
//	111341251						148719248						110047255								

//	Task Log
//	5-Dec-25		S.Symonette		Created Starship.cpp file, finished the function definitions

#include "Starship.h"
#include <iostream>

using namespace std;

Starship::Starship(double fuel,
	double light,
	double massPassengers,
	double massCargo,
	double massWorkstations,
	int numTorpedoes,
	int numLasers) {
	speed = 0.0;
	distance = 0.0;
	Propulsion propulsion1(fuel, light);
	Payload payload1(massPassengers, massCargo, massWorkstations);
	Weapons weapon1(numTorpedoes, numLasers);

}
bool Starship::ChangeSpeed(double speed) {
	bool ret = false;
	double energyRequired = 0.0;
	double totalMass = 0.0;
	totalMass = payload1.GetMassCargo() + payload1.GetMassPassengers() + payload1.GetMassWorkstations();
	energyRequired = 0.5 * totalMass * (speed * speed);
	//propulsion1.ConsumeFuel(energyRequired); TO DO ret = true if condition is met 
	return ret;
}
void Starship::Travel(double time, double light) {
	propulsion1.SetLightLevel(light);
	propulsion1.GenerateFuel(time);
	// TO DO Update distance
}
bool Starship::FireTorpedoes(int numTorpedoes) {
	//TO DO check if numTorpedoes
	bool ret = false;
	ret = weapon1.FireTorpedoes(numTorpedoes);
	return ret;
}
bool Starship::FireLasers(double time) {
	//TO DO check for stuff
	bool ret = false;
	double energyRequired = 0.0;
	energyRequired = weapon1.FireLasers(time);
	ret = propulsion1.ConsumeFuel(energyRequired);
	return ret;
}
void Starship::GenerateReport() {
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "The star ship is travelling at " << speed << "m/s and has travelled " << distance << "m." << endl;
	propulsion1.Report();
	payload1.Report();
	weapon1.Report();
}