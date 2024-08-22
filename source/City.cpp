#include "../include/City.h"
#include "City.h"

City::City()
{
    CityName = "";
    Latitude = 0.0;
    Longitude = 0.0;
}
City::City(string name, double lat, double lng)
{
    CityName = name;
    Latitude = lat;
    Longitude = lng;
}

string City::getCityName()
{
    return string();
}

double City::getLat()
{
    return this->Latitude;
}

double City::getIng()
{
    return this->Longitude;
}

City::~City()
{
    // Destructor
}
