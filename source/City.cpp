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

double calHaversineDistance(Point2D point1, Point2D point2)
{
    const double R = 6371; // (km)

    double lat1 = point1.latitude * PI / 180.0;
    double lon1 = point1.longitude * PI / 180.0;
    double lat2 = point2.latitude * PI / 180.0;
    double lon2 = point2.longitude * PI / 180.0;

    double a = pow(sin((lat2 - lat1) / 2), 2)  + cos(lat1) * cos(lat2) * pow(sin((lon2 - lon1) / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R * c;
}