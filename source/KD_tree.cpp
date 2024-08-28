#include "../include/KD_tree.h"

KD_tree::KD_tree()
{
    root = nullptr;
}

KD_tree::~KD_tree()
{
    // Destructor
}

void insert(Node* &root, City city, int depth)
{
    if (root == nullptr)
    {
        root = createNode(city);
    }
    else
    {
        int cd = depth % 2;
        if (cd == 0)
        {
            if (city.location.latitude < root->data.location.latitude)
            {
                insert(root->left, city, depth + 1);
            }
            else
            {
                insert(root->right, city, depth + 1);
            }
        }
        else
        {
            if (city.location.longitude < root->data.location.longitude)
            {
                insert(root->left, city, depth + 1);
            }
            else
            {
                insert(root->right, city, depth + 1);
            }
        }
    }
}

void preOrder(Node* root)
{
    if (root != nullptr)
    {
        cout << "City Name: " << root->data.cityName << endl;
        cout << "Latitude: " << root->data.location.latitude << endl;
        cout << "Longitude: " << root->data.location.longitude << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        cout << "City Name: " << root->data.cityName << endl;
        cout << "Latitude: " << root->data.location.latitude << endl;
        cout << "Longitude: " << root->data.location.longitude << endl;
        inOrder(root->right);
    }
}

void postOrder(Node* root)
{
    if (root != nullptr)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << "City Name: " << root->data.cityName << endl;
        cout << "Latitude: " << root->data.location.latitude << endl;
        cout << "Longitude: " << root->data.location.longitude << endl;
    }
}

Node* search(Node* root, City city, int depth)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data.location.latitude == city.location.latitude && root->data.location.latitude == city.location.latitude)
    return root;

    if (depth % 2 == 0)
    {
        if (city.location.latitude < root->data.location.latitude)
        {
            return search(root->left, city, depth + 1);
        }
        else 
        {
            return search(root->right, city, depth + 1);
        }
        
    }
    else
    {
        if (city.location.latitude < root->data.location.latitude)
        {
            return search(root->left, city, depth + 1);
        }
        else 
        {
            return search(root->right, city, depth + 1);
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

        City getCity(cityName, {lat, lng});
        listCity.push_back(getCity);
    }
    fs.close();
    return listCity;
}

void deleteTree(Node* &root)
{
    if (root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

// Range Search for KD_Tree

Node* searchNearestNeighbor(Node* root, Point2D point)
{
    Node* neareastCity = nullptr;
    double minDistance = DBL_MAX;

    searchNearestNeighborUtil(root, point, neareastCity, minDistance, START_DEPTH);

    return neareastCity;
}