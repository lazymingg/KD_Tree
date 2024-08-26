#include "../include/City.h"

City::City()
{
    cityName = "";
    location.latitude = 0.0;
    location.longitude = 0.0;
}

City::City(string name, Point2D location)
{
    cityName = name;
    this->location.latitude = location.latitude;
    this->location.longitude = location.longitude;
}

City::~City()
{
    // Destructor
}
