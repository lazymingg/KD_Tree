#include "../include/KD_tree.h"

KD_tree::KD_tree()
{
    root = nullptr;
}
KD_tree::~KD_tree()
{
    // Destructor
}
void KD_tree::insert(City city)
{
    insertUtil(root, city, 0);
}
void KD_tree::preOrder()
{
    preOrderUtil(root);
}
void KD_tree::inOrder()
{
    inOrderUtil(root);
}
void KD_tree::postOrder()
{
    postOrderUtil(root);
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

        getline(ss, cityName, ',');
        getline(ss, cityLat, ',');
        getline(ss, cityLng, ',');

        if (cityLat == "")
        {
            lat = 0;
        }
        else
        {
            lat = stod(cityLat);
        }

        if (cityLng == "")
        {
            lng = 0;
        }
        else
        {
            lng = stod(cityLng);
        }

        City getCity(cityName, lat, lng);
        insertUtil(root, getCity);
    }

    fs.close();
}