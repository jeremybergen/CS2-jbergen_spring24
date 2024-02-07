#include <iostream>
#include <string>

using namespace std;

class Vehicle {
    private:
    string _brand;
    int _year;

    public:
    Vehicle(string = "", int = 0);
    void showInfo();
};

class Car : public Vehicle {
    private:
    string _model;

    public:
    Car(string = "", string = "", int = 0);
};

class Hybrid : public Car {
    private:
    string _type;

    public:
    Hybrid(string = "", string = "", string = "", int = 0);
};

int main(int argc, char* argv[])
{
    return 0;
}

Hybrid(string = "", string = "", string = "", int = 0) : Car()

Car::Car(string model, string brand, int year) : Vehicle(brand, year)
{
    _model = model;
}

Vehicle::Vehicle(string brand, int year)
{
    _brand = brand;
    _year = year;
}
void Vehicle::showInfo()
{
    cout << "Brand: " << _brand << ", Year: " << _year << endl;
}