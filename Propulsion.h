//	SEP101 - ASSIGNMENT 2
//	Propulsion.h - header file for the propulsion of the spaceship

//	Daryl Gonzales					Shay Symonette					Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			ssymonette@myseneca.ca			ykaraman1@myseneca.ca
//	111341251						148719248						110047255				

//	Task Log
//	4-Dec-25		D. Gonzales		Created Propulsion.h file, finished the class

#ifndef _PROPULSION_H_
#define _PROPULSION_H_

class Propulsion {
private:
	double fuel;
	const double MAX_FUEL = 1000.00;
	const double SPEED_OF_LIGHT = 299792458.0;
	double light;
	double LightToFuel(double time);
public:
	Propulsion();
	Propulsion(double fuel, double light);
	bool ConsumeFuel(double energy);
	void AddFuel(double fuel);
	void GenerateFuel(double time);
	void SetLightLevel(double light);
	void Report() const;
};

#endif