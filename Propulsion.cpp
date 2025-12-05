//	SEP101 - ASSIGNMENT 2
//	Propulsion.cpp - program containing the function definitions for the propulsion class

//	Daryl Gonzales					Shay Symonette					Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			ssymonette@myseneca.ca			ykaraman1@myseneca.ca
//	111341251						148719248						110047255								

//	Task Log
//	4-Dec-25		D. Gonzales		Created Propulsion.cpp file, finished the function definitions

#include "Propulsion.h"
#include <iostream>

using namespace std;

Propulsion::Propulsion() {
	fuel = 0.0;
	light = 0.0;
}

Propulsion::Propulsion(double fuel, double light) {
	if (fuel >= 0 && fuel <= MAX_FUEL) this->fuel = fuel;
	if (light >= 0.0 && light < 1.0) this->light = light;
}

double Propulsion::LightToFuel(double time) { 
	return light * time;
}

bool Propulsion::ConsumeFuel(double energy) {
	bool ret = false;
	double fuelRequired = 0.0;
	if (energy >= 0) fuelRequired = energy / (SPEED_OF_LIGHT * SPEED_OF_LIGHT);
	// Accept the case where fuelRequired == fuel, we would have JUST enough
	// fuel to get there
	if (fuelRequired <= fuel) {
		ret = true;
		fuel -= fuelRequired;
	}
	return ret;
}

void Propulsion::AddFuel(double fuel) {
	double totalFuel = 0.0;
	if (fuel >= 0) {
		totalFuel = this->fuel + fuel;
		if (totalFuel >= MAX_FUEL) this->fuel = MAX_FUEL;
		else this->fuel = totalFuel;
	}
}

void Propulsion::GenerateFuel(double time) {
	double fuelGenerated = 0.0;
	if (time >= 0) {
		fuelGenerated = LightToFuel(time);
		AddFuel(fuelGenerated);
	}
}

void Propulsion::SetLightLevel(double light) {
	if (light >= 0.0 && light <= 1.0) this->light = light;
}

void Propulsion::Report() const {
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "Propulsion: fuel level : " << fuel << " kg of matter / anti - matter, light level : " << light << "." <<endl;
}