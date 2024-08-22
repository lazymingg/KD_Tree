#include "KD_tree.h"

KD_tree::KD_tree()
{
    root = NULL;
}

KD_tree::~KD_tree()
{

}

void KD_tree::readFile(string fileName)
{
    fstream fs;
    string filePath = "data/" + fileName;
    fs.open(filePath, ios::in);
    if (!fs.is_open())
    {
        cout << "Cannot open file!" << endl;
        return;
    }
    
    string title;
    getline(fs, title);
    string line;
    while (getline(fs, line))
    {
        stringstream ss(line);
        string cityName;
        string cityLat;
        string cityLng;
        double lat;
        double lng;

        getline(fs, cityName, ',');
        getline(fs, cityLat, ',');
        getline(fs, cityLng, ',');

        if (cityLat == "")
        {
            lat = 0;
            continue;
            // There is an error where the getline somehow still read the last line???
        }
        else
        {
            lat = stod(cityLat);
        }

        if (cityLng == "")
        {
            lng = 0;
            continue;
        }
        else
        {
            lng = stod(cityLng);
        }

        City getCity(cityName, lat, lng);
        // insert(getCity);
    }

    fs.close();
}