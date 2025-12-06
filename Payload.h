//	SEP101 - ASSIGNMENT 2
//	Payload.h - header file for the payload of the spaceship

//	Daryl Gonzales					Shay Symonette					Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			ssymonette@myseneca.ca			ykaraman1@myseneca.ca
//	111341251						148719248						110047255				

//	Task Log
//	4-Dec-25		S.Symonette		Created Payload.h file, finished the class

#ifndef _PAYLOAD_H_
#define _PAYLOAD_H_

class Payload {
private:
	double massPassengers;
	double massCargo;
	double massWorkstations;
public:
	Payload();
	Payload(double massPassengers, double massCargo, double massWorkstations);
	double GetMassPassengers() const;
	double GetMassCargo() const;
	double GetMassWorkstations() const;
	double GetTotalMass() const;
	void AddPassengers(double massPassengers);
	void AddCargo(double massCargo);
	void AddWorkstations(double massWorkstations);
	void Report() const;
};

#endif 