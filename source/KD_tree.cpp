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

void readFile(Node* &root, string fileName)
{
    fstream fs;
    string filePath = "../data/" + fileName;
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

        City getCity(cityName, {lat, lng});
        insert(root, getCity, 0);
    }
    fs.close();
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
vector<Node*> searchRange(Node* root, const Point2D& bottom_left, const Point2D& top_right)
{
    vector<Node*> res;
    if (bottom_left.latitude > top_right.latitude)
    {
        cout << "Bottom-left point's latitude must be less than top-right point's latitude!\n";
        return res;
    }

    if (bottom_left.longitude < top_right.longitude)
        searchRangeUtil_case1(res, root, bottom_left, top_right, 0);
    else
        searchRangeUtil_case2(res, root, bottom_left, top_right, 0);
    
    return res;
}

// Nearest Neighbor Search
Node* searchNearestNeighbor(Node* root, vector<Point2D> Point2Ds)
{

    
    return nullptr;
}