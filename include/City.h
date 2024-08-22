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

        //Get data
        string getCityName();
        double getLat();
        double getIng();
        // Destructor
        ~City();
        //getters
        string getCityName();
        double getLatitude();
        double getLongitude();
        //setters
        void setCityName(string name);
        void setLatitude(double lat);
        void setLongitude(double lng);

        // Member functions
    private:
        // Member variables
        string CityName;
        double Latitude;
        double Longitude;    
};
#endif // CITY_H