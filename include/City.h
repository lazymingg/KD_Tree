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

struct Point2D {
    double latitude;
    double longitude;
};

struct City
{
    string cityName;
    Point2D location;
    
    City();
    City(string name, Point2D location);
    ~City();
};

#endif // CITY_H