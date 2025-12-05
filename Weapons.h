//	SEP101 - ASSIGNMENT 2
//	Weapons.h - header file for the weapons of the spaceship

//	Daryl Gonzales					Shay Symonette					Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			ssymonette@myseneca.ca			ykaraman1@myseneca.ca
//	111341251						148719248						110047255				

//	Task Log
//	4-Dec-25		E. Karaman		Created Weapons.h file, finished the class

#ifndef _WEAPONS_H_
#define _WEAPONS_H_

class Weapons {
private:
	int numTorpedoes;
	int numLasers;
	const int MAX_TORPEDOES = 100;
	const int MAX_LASERS = 8;
	const double LASER_ENERGY_PER_SECOND = 1000000000000.0;
public:
	Weapons();
	Weapons(int numTorpedoes, int numLasers);
	bool FireTorpedoes(int numTorpedoes);
	double FireLasers(double time);
	void AddTorpedoes(int numTorpedoes);
	void AddLasers(int numLasers);
	void Report() const;
};

#endif