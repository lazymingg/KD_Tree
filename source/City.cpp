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
//getters
string City::getCityName() {
    return CityName;
}
double City::getLatitude() {
    return Latitude;
}
double City::getLongitude() {
    return Longitude;
}
//setters
void City::setCityName(string name) {
    CityName = name;
}
void City::setLatitude(double lat) {
    Latitude = lat;
}
void City::setLongitude(double lng) {
    Longitude = lng;
}

