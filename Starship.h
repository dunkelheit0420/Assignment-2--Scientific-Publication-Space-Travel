//	SEP101 - ASSIGNMENT 2
//	Starship.h - header file for the starships of the Star Fleet

//	Daryl Gonzales					Shay Symonette					Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			ssymonette@myseneca.ca			ykaraman1@myseneca.ca
//	111341251						148719248						110047255				

//	Task Log
//	5-Dec-25		S.Symonette		Created Starship.h file, finished the class

#include "Propulsion.h"
#include "Payload.h"
#include "Weapons.h"

#ifndef _STARSHIP_H_
#define _STARSHIP_H_

class Starship {
private:
	Propulsion propulsion1;
	Payload payload1;
	Weapons weapon1;
	double speed;
	double distance;
public:
	Starship(double fuel,
		double light,
		double massPassengers,
		double massCargo,
		double massWorkstations,
		int numTorpedoes,
		int numLasers);
	bool ChangeSpeed(double deltaSpeed);
	void Travel(double time, double light);
	bool FireTorpedo(int numTorpedoes);
	bool FireLaser(double time);
	void GenerateReport();
};

#endif