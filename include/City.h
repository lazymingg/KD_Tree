#ifndef CITY_H
#define CITY_H



// Include any necessary libraries or headers
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
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
    ~City();
};

Point2D inputPoint2D(string PointName);
double calHaversineDistance(const Point2D& point1, const Point2D& point2);
float calSumDistance(const Point2D& target, const vector<Point2D> points);

#endif // CITY_H