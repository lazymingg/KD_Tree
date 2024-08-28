#include "../include/KD_tree.h"

KD_tree::KD_tree()
{
    root = nullptr;
}

bool insert(Node* &root, City city, int depth)
{
    if (city.location.latitude == 90 || city.location.latitude == -90)
    {
        // To ensure one point only existed once in a map
        city.location.longitude = 0;
    }

    if (city.location.longitude == 180)
    {
        // To ensure one point only existed once in a map
        // -180 because if the longitude is equal to some, it will mostly be inserted to the right
        city.location.longitude = -180;
    }

    if (root == nullptr)
    {
        root = createNode(city);
        return true;
    }
    else
    {
        int cd = depth % 2;
        if (cd == 0)
        {
            // Using latitude to divide, imagine a horizontal line at given point
            if (city.location.latitude < root->data.location.latitude)
            {
                if (insert(root->left, city, depth + 1))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if (city.location.latitude == root->data.location.latitude && city.location.longitude == root->data.location.longitude)
            {
                cout << "Location has existed, cannot insert \"" << city.cityName << "\"" << endl;
                return false;
            }
            else
            {
                if (insert(root->right, city, depth + 1))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            // Using longitude to divide, imagine a vertical line at given point
            if (city.location.longitude < root->data.location.longitude)
            {
                if (insert(root->left, city, depth + 1))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if (city.location.longitude == root->data.location.longitude && city.location.latitude == root->data.location.latitude)
            {
                cout << "Location has existed, cannot insert \"" << city.cityName << "\"" << endl;
                return false;
            }
            else
            {
                if (insert(root->right, city, depth + 1))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
}

vector<City> readFile(string filePath)
{
    fstream fs;
    vector<City> listCity;
    fs.open(filePath, ios::in);
    if (!fs.is_open())
    {
        cout << "Cannot open file!" << endl;
        return listCity;
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

        // Getting data
        getline(ss, cityName, ',');
        getline(ss, cityLat, ',');
        getline(ss, cityLng, ',');

        // Checking valid data
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

        City getCity(cityName, {lat, lng});
        listCity.push_back(getCity);
    }
    fs.close();
    return listCity;
}

void deleteTree(Node* &root)
{
    // Tree deletion
    if (root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

Node* searchNearestNeighbor(Node* root, Point2D point)
{
    Node* nearestCity = nullptr;
    double minDistance = DBL_MAX;

    searchNearestNeighborUtil(root, point, nearestCity, minDistance, START_DEPTH);

    if (!nearestCity)
        cout << "No nearest city to (" << point.latitude << ',' << point.longitude << ")\n";
    return nearestCity;
}

vector<Node*> searchRange(Node* root, Point2D bottom_left, Point2D top_right)
{
    vector<Node*> res;
    if (bottom_left.latitude > top_right.latitude)
    {
        cout << "Bottom-left point's latitude must be less than top-right point's latitude!\n";
        return res;
    }

    if (bottom_left.longitude < top_right.longitude)
        searchRangeUtil_case1(res, root, bottom_left, top_right, START_DEPTH);
    else
        searchRangeUtil_case2(res, root, bottom_left, top_right, START_DEPTH);
    
    return res;
}
