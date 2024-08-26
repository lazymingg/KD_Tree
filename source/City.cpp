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

Point2D inputPoint2D(string PointName)
{
    Point2D point;
    
    cout << "Input " << PointName << "'s latitude: ";
    cin >> point.latitude;
    cout << "Input " << PointName << "'s longitude: ";
    cin >> point.longitude;


    while (point.latitude < -90 || point.latitude > 90 || point.longitude < -180 || point.longitude > 180)
    {
        cout << "Invalide range!\n";
        cout << "Latitude must be in [-90,90]\n";
        cout << "Longitude must be in [-180,180]\n";

        cout << "Input " << PointName << "'s latitude: ";
        cin >> point.latitude;
        cout << "Input " << PointName << "'s longitude: ";
        cin >> point.longitude;
    }

    return point;
}