//	SEP101 - ASSIGNMENT 2
//	Cargo.cpp - program containing the function definitions for the cargo class

//	Daryl Gonzales					Shay Symonette					Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			ssymonette@myseneca.ca			ykaraman1@myseneca.ca
//	111341251						148719248						110047255								

//	Task Log
//	5-Dec-25		E. Karaman		Created Cargo.cpp file, finished the function definitions
//	6-Dec-25		E. Karaman		Finished methods to working condition

#include "Cargo.h"
#include <iostream>

using namespace std;

Cargo::Cargo(double fuel,
	double light,
	double massPassengers1,
	double massCargo1,
	double massWorkstations1,
	double massPassengers2,
	double massCargo2,
	double massWorkstations2)
	: speed(0.0),
	distance(0.0),
	propulsion(fuel, light),
	payload1(massPassengers1, massCargo1, massWorkstations1),
	payload2(massPassengers2, massCargo2, massWorkstations2) {
}

bool Cargo::ChangeSpeed(double deltaSpeed) {
	bool ret = false;
	double energyRequired = 0.0;

	double newSpeed = speed + deltaSpeed;

	if (newSpeed >= 0.0) {
		double totalMass = payload1.GetTotalMass() + payload2.GetTotalMass();
		
		// ?E = 0.5 * m * (v_final² - v_initial²)
		energyRequired = 0.5 * totalMass * ((newSpeed * newSpeed) - (speed * speed)); 

		if (energyRequired > 0) {
			if (propulsion.ConsumeFuel(energyRequired)) {
				speed = newSpeed;
				ret = true;
			}
		}
		else {
			speed = newSpeed;
			ret = true;
		}
	}

	return ret;
}

void Cargo::Travel(double time, double light) {
	if (light >= 0.0 && light <= 1.0 && time >= 0) {
		propulsion.SetLightLevel(light);
		propulsion.GenerateFuel(time);
		distance = distance + speed * time;
	}
}

void Cargo::GenerateReport() {
	cout.precision(2);
	cout.setf(ios::fixed);

	double distanceInKm = distance / 1000.0;

	cout << "The cargo ship is travelling at " << speed << "m/s and has travelled "
		<< distanceInKm << " km." << endl;

	propulsion.Report();
	payload1.Report();
	payload2.Report();
}