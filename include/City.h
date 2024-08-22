#ifndef CITY_H
#define CITY_H



// Include any necessary libraries or headers
#include <iostream>
#include <string>
#include <vector>
using namespace std;


// Declare any necessary classes or structs
// city,lat,lng,country,population
// essential information including latitude, longitude, and city names
// from the dataset.
class City {
    public:
        // Constructor
        City();
        City(string name, double lat, double lng);
        // Destructor
        ~City();

        // Member functions
    private:
        // Member variables
        string CityName;
        double Latitude;
        double Longitude;    
};
#endif // CITY_H