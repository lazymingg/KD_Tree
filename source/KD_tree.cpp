#include "../include/KD_tree.h"

KD_tree::KD_tree()
{
    root = nullptr;
}

KD_tree::~KD_tree()
{
    // Destructor
}

void KD_tree::insert(City city){
    insertNode(root, city, 0);
}

void KD_tree::preOrder(){
    getPreOrder(root);
}

void KD_tree::inOrder(){
    getInOrder(root);
}

void KD_tree::postOrder(){
    getPostOrder(root);
}

void KD_tree::insertNode(Node* &pRoot, City city, int depth)
{
    if (pRoot == nullptr)
    {
        pRoot = new Node(city, nullptr, nullptr);
        return;
    }
    else
    {
        int cd = depth % 2;
        if (cd == 0)
        {
            if (city.getLatitude() < pRoot->data.getLatitude())
            {
                insertNode(pRoot->left, city, depth + 1);
            }
            else
            {
                insertNode(pRoot->right, city, depth + 1);
            }
        }
        else
        {
            if (city.getLongitude() < pRoot->data.getLongitude())
            {
                insertNode(pRoot->left, city, depth + 1);
            }
            else
            {
                insertNode(pRoot->right, city, depth + 1);
            }
        }
    }
}

void KD_tree::getPreOrder(Node* pRoot)
{
    if (pRoot != nullptr)
    {
        cout << "City Name: " << pRoot->data.getCityName() << endl;
        cout << "Latitude: " << pRoot->data.getLatitude() << endl;
        cout << "Longitude: " << pRoot->data.getLongitude() << endl;
        getPreOrder(pRoot->left);
        getPreOrder(pRoot->right);
    }
}

void KD_tree::getInOrder(Node* pRoot)
{
    if (pRoot != nullptr)
    {
        getInOrder(pRoot->left);
        cout << "City Name: " << pRoot->data.getCityName() << endl;
        cout << "Latitude: " << pRoot->data.getLatitude() << endl;
        cout << "Longitude: " << pRoot->data.getLongitude() << endl;
        getInOrder(pRoot->right);
    }
}

void KD_tree::getPostOrder(Node* pRoot)
{
    if (pRoot != nullptr)
    {
        getPostOrder(root->left);
        getPostOrder(root->right);
        cout << "City Name: " << pRoot->data.getCityName() << endl;
        cout << "Latitude: " << pRoot->data.getLatitude() << endl;
        cout << "Longitude: " << pRoot->data.getLongitude() << endl;
    }
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
        insert(getCity);
    }
    fs.close();
}

// void KD_tree::deleteTree()
// {
//     deleteTreeUtil(root);
// }
