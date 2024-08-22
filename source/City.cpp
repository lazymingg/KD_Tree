#include "../include/City.h"

City::City() {
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
City::~City() {
    // Destructor
}
