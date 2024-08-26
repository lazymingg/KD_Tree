#include "../include/Util.h"

void insertUtil(Node* &pRoot, City city, int depth)
{
    if (pRoot == nullptr)
    {
        pRoot = createNode(city);
    }
    else
    {
        int cd = depth % 2;
        if (cd == 0)
        {
            if (city.location.latitude < pRoot->data.location.latitude)
            {
                insertUtil(pRoot->left, city, depth + 1);
            }
            else
            {
                insertUtil(pRoot->right, city, depth + 1);
            }
        }
        else
        {
            if (city.location.latitude < pRoot->data.location.latitude)
            {
                insertUtil(pRoot->left, city, depth + 1);
            }
            else
            {
                insertUtil(pRoot->right, city, depth + 1);
            }
        }
    }
}

Node* createNode(City city)
{
    Node *newNode = new Node(city, nullptr, nullptr);
    return newNode;
}

void preOrderUtil(Node *root)
{
    if (root != nullptr)
    {
        cout << "City Name: " << root->data.cityName << endl;
        cout << "Latitude: " << root->data.location.latitude << endl;
        cout << "Longitude: " << root->data.location.longitude << endl;
        preOrderUtil(root->left);
        preOrderUtil(root->right);
    }
}

void inOrderUtil(Node *root)
{
    if (root != nullptr)
    {
        inOrderUtil(root->left);
        cout << "City Name: " << root->data.cityName << endl;
        cout << "Latitude: " << root->data.location.latitude << endl;
        cout << "Longitude: " << root->data.location.latitude << endl;
        inOrderUtil(root->right);
    }
}

void postOrderUtil(Node *root)
{
    if (root != nullptr)
    {
        postOrderUtil(root->left);
        postOrderUtil(root->right);
        cout << "City Name: " << root->data.cityName << endl;
        cout << "Latitude: " << root->data.location.latitude << endl;
        cout << "Longitude: " << root->data.location.latitude << endl;
    }
}

void deleteTreeUtil(Node *root)
{
    if (root != nullptr)
    {
        deleteTreeUtil(root->left);
        deleteTreeUtil(root->right);
        delete root;
    }
}

Node* searchNodeUtil(Node* pRoot, City city, int depth)
{
    if (pRoot == nullptr)
    {
        return nullptr;
    }
    if (pRoot->data.location.latitude == city.location.latitude && pRoot->data.location.latitude == city.location.latitude)
    return pRoot;

    if (depth % 2 == 0)
    {
        if (city.location.latitude < pRoot->data.location.latitude)
        {
            return searchNodeUtil(pRoot->left, city, depth + 1);
        }
        else 
        {
            return searchNodeUtil(pRoot->right, city, depth + 1);
        }
        
    }
    else
    {
        if (city.location.latitude < pRoot->data.location.latitude)
        {
            return searchNodeUtil(pRoot->left, city, depth + 1);
        }
        else 
        {
            return searchNodeUtil(pRoot->right, city, depth + 1);
        }
        
    }
}