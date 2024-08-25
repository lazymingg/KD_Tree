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

// bỏ hàm này sang util nhé
Node* KD_tree::searchNode(Node *pRoot, City &city, int depth)
{
    if (pRoot == nullptr)
    {
        return nullptr;
    }
    if (pRoot->data.getLatitude() == city.getLatitude() && pRoot->data.getLongitude() == city.getLongitude())
    return pRoot;

    if (depth % 2 == 0)
    {
        if (city.getLatitude() < pRoot->data.getLatitude())
        {
            return searchNode(pRoot->left, city, depth + 1);
        }
        else 
        {
            return searchNode(pRoot->right, city, depth + 1);
        }
        
    }
    else
    {
        if (city.getLongitude() < pRoot->data.getLongitude())
        {
            return searchNode(pRoot->left, city, depth + 1);
        }
        else 
        {
            return searchNode(pRoot->right, city, depth + 1);
        }
        
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

void KD_tree::deleteTree()
{
    deleteTreeUtil(root);
}

vector<Node*> KD_tree::RangeSearch(const point2D& bottom_left, const point2D& top_right)
{
    vector<Node*> res;
    RangeSearchUtil(res, root, bottom_left, top_right, 0);
    return res;
}