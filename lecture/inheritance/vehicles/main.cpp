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
    // Car(model, brand, year) inherited from Vehicle
    Car(string = "", string = "", int = 0);
};

class Hybrid : public Car {
    private:
    string _type;

    public:
    // Hybrid(string type, string model, string brand, int year) : Car(model, brand, year)
    Hybrid(string = "", string = "", string = "", int = 0);
};

int main(int argc, char* argv[])
{
    Hybrid newHybrid("electric", "Prius", "Toyota", 2024);
    // Hybrid h2("electric", "")

    newHybrid.showInfo();
    return 0;
}

/* This is the constructor for Hybrid
   Takes in 3 strings and one int of the following names:
   Hybrid(string type, string model, string brand, int year)
   pass to Car(model, brand, year)
*/
Hybrid::Hybrid(string type, string model, string brand, int year) : Car(model, brand, year)
{
    _type = type;
}

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