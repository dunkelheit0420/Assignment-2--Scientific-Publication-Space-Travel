//	SEP101 - ASSIGNMENT 2
//	Warbird.h - header file for the warbirds of the Star Fleet

//	Daryl Gonzales					Shay Symonette					Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			ssymonette@myseneca.ca			ykaraman1@myseneca.ca
//	111341251						148719248						110047255				

//	Task Log
//	4-Dec-25		D. Gonzales		Created Warbird.h file, finished the class

#include "Propulsion.h"
#include "Payload.h"
#include "Weapons.h"

#ifndef _WARBIRD_H_
#define _WARBIRD_H_

class Warbird {
private:
	Propulsion propulsion1, propulsion2;
	Payload payload;
	Weapons weapon1, weapon2;
	double speed;
	double distance;
public:
	Warbird(double fuel1,
			double light1,
			double massPassengers,
			double massCargo,
			double massWorkstations,
			int numTorpedoes1,
			int numLasers1);
	bool ChangeSpeed(double speed);
	void Travel(double time, double light);
	bool FireTorpedo(int numTorpedoes);
	bool FireLaser(double time);
	void GenerateReport();
};

#endif