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
    insertNode(root, city, 0);
}

void KD_tree::preOrder()
{
    int start = 0;
    getPreOrder(root, start);
}

void KD_tree::inOrder()
{
    int start = 0;
    getInOrder(root, start);
}

void KD_tree::postOrder(){
    int start = 0;
    getPostOrder(root, start);
}

void KD_tree::remove()
{
    deleteTree(root);
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
        int cd = depth % 2; // Tại sao tạo thêm biến cd?
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

void KD_tree::getPreOrder(Node* pRoot, int& order)
{
    if (pRoot != nullptr)
    {
        cout << order << ".City Name: " << pRoot->data.getCityName() << endl;
        cout << "Latitude: " << pRoot->data.getLatitude() << " - ";
        cout << "Longitude: " << pRoot->data.getLongitude() << "\n\n";
        order++;
        getPreOrder(pRoot->left, order);
        getPreOrder(pRoot->right, order);
    }
}

void KD_tree::getInOrder(Node* pRoot, int& order)
{
    if (pRoot != nullptr)
    {
        getInOrder(pRoot->left, order);
        cout << order << ".City Name: " << pRoot->data.getCityName() << endl;
        cout << "Latitude: " << pRoot->data.getLatitude() << " - ";
        cout << "Longitude: " << pRoot->data.getLongitude() << "\n\n";
        order++;
        getInOrder(pRoot->right, order);
    }
}

void KD_tree::getPostOrder(Node* pRoot, int& order)
{
    if (pRoot != nullptr)
    {
        getPostOrder(root->left, order);
        getPostOrder(root->right, order);
        cout << order << ".City Name: " << pRoot->data.getCityName() << endl;
        cout << "Latitude: " << pRoot->data.getLatitude() << " - ";
        cout << "Longitude: " << pRoot->data.getLongitude() << "\n\n";
        order++;
    }
}

void KD_tree::deleteTree(Node *&pRoot)
{
    if (pRoot == NULL)
        return;

    deleteTree(pRoot->right);
    deleteTree(pRoot->left);
    delete pRoot;

    pRoot = NULL;
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

vector<Node*> KD_tree::RangeSearch(const point2D& bottom_left, const point2D& top_right)
{
    vector<Node*> res;
    RangeSearchUtil(res, root, bottom_left, top_right, 0);
    return res;
}