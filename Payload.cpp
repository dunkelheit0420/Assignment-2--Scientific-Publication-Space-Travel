//	SEP101 - ASSIGNMENT 2
//	Payload.cpp - program containing the function definitions for the payload class

//	Daryl Gonzales					Shay Symonette					Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			ssymonette@myseneca.ca			ykaraman1@myseneca.ca
//	111341251						148719248						110047255								

//	Task Log
//	4-Dec-25		S.Symonette		Created Payload.cpp file, finished the function definitions

#include "Payload.h"
#include <iostream>

using namespace std;

Payload::Payload() {
	massPassengers = 0.0;
	massCargo = 0.0;
	massWorkstations = 0.0;
}

Payload::Payload(double massPassengers, double massCargo, double massWorkstations) {
	// Set negative mass to zero instead
	if (massPassengers >= 0) this->massPassengers = massPassengers;
	else this->massPassengers = 0.0;
	if (massCargo >= 0) this->massCargo = massCargo;
	else this->massCargo = 0.0;
	if (massWorkstations >= 0) this->massWorkstations = massWorkstations;
	else this->massWorkstations = 0.0;

}

double Payload::GetMassPassengers() const {
	return massPassengers;
}

double Payload::GetMassCargo() const {
	return massCargo;
}

double Payload::GetMassWorkstations() const {
	return massWorkstations;
}

void Payload::Report() const {
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "Payload: mass of passengers: " << massPassengers << " kg, mass of cargo : " << massCargo << " kg, mass of workstations : " << massWorkstations << " kg." << endl;
}