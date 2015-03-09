#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
public:
	Vehicle(int wl, double wt):wheel(wl), weight(wt){}
	~Vehicle(){};
	void DisplayInfo();
private:
	int wheel;
	double weight;
};

void Vehicle::DisplayInfo()
{
	cout << "Its wheel number is: " << wheel << endl;
	cout << "The weight of itself is: " << weight << endl;
}

class Car: public Vehicle
{
public:
	Car(int wl, double wt, int pn):Vehicle(wl, wt), passenger_num(pn){}
	~Car(){};
	void DisplayInfo();
private:
	int passenger_num;
};

void Car::DisplayInfo()
{
	Vehicle::DisplayInfo();
	cout << "This car can totally load " << passenger_num << " passengers" << endl;
}

class Truck: public Vehicle
{
public:
	Truck(int wl, double wt, double lc):Vehicle(wl, wt), LoadCapacity(lc){}
	~Truck(){};
	void DisplayInfo();
private:
	double LoadCapacity;
};

void Truck::DisplayInfo()
{
	Vehicle::DisplayInfo();
	cout << "The truck's load capacity is: " << LoadCapacity << endl;
}

int main(int argc, char const *argv[])
{
	//testing Vehicle class
	Vehicle V(2, 100);
	V.DisplayInfo();
	cout << "-----------------------------------------\n" << endl;

	//testing Car class
	Car C(4, 1000, 4);
	C.DisplayInfo();
	cout << "-----------------------------------------\n" << endl;

	//testing Truck class
	Truck T(12, 12000, 30000);
	T.DisplayInfo();
	cout << "-----------------------------------------\n" << endl;

	return 0;
}
