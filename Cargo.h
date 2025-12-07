//	SEP101 - ASSIGNMENT 2
//	Cargo.h - header file for the cargo ships of the Star Fleet

//	Daryl Gonzales					Shay Symonette					Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			ssymonette@myseneca.ca			ykaraman1@myseneca.ca
//	111341251						148719248						110047255				

//	Task Log
//	5-Dec-25		E.Karaman		Created Cargo.h file, finished the class
//	6-Dec-25	    E.Karaman		Added methods and member variables

#ifndef _CARGO_H_
#define _CARGO_H_

#include "Propulsion.h"
#include "Payload.h"

class Cargo {
private:
	double speed;
	double distance;
	Propulsion propulsion;
	Payload payload1;
	Payload payload2;

public:
	Cargo(double fuel,
		double light,
		double massPassengers,
		double massCargo,
		double massWorkstations)
		: propulsion(fuel, light), 
		payload1(massPassengers, massCargo, massWorkstations), 
		payload2(massPassengers, massCargo, massWorkstations),
		speed(0.0), 
		distance(0.0)
	{}
	Cargo(double fuel,
		double light,
		double massPassengers1,
		double massCargo1,
		double massWorkstations1,
		double massPassengers2,
		double massCargo2,
		double massWorkstations2);
	bool ChangeSpeed(double deltaSpeed);
	void Travel(double time, double light);
	void GenerateReport();
};

#endif