#ifndef CITY_H
#define CITY_H



// Include any necessary libraries or headers
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cfloat>

using namespace std;

// Declare any necessary classes or structs
// city,lat,lng,country,population
// essential information including latitude, longitude, and city names
// from the dataset.

const double PI = 2 * acos(0.0); 

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
};

double calHaversineDistance(Point2D point1, Point2D point2);

#endif // CITY_H