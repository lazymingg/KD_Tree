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
            if (city.getLatitude() < pRoot->data.getLatitude())
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
            if (city.getLongitude() < pRoot->data.getLongitude())
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
        cout << "City Name: " << root->data.getCityName() << endl;
        cout << "Latitude: " << root->data.getLatitude() << endl;
        cout << "Longitude: " << root->data.getLongitude() << endl;
        preOrderUtil(root->left);
        preOrderUtil(root->right);
    }
}
void inOrderUtil(Node *root)
{
    if (root != nullptr)
    {
        inOrderUtil(root->left);
        cout << "City Name: " << root->data.getCityName() << endl;
        cout << "Latitude: " << root->data.getLatitude() << endl;
        cout << "Longitude: " << root->data.getLongitude() << endl;
        inOrderUtil(root->right);
    }
}
void postOrderUtil(Node *root)
{
    if (root != nullptr)
    {
        postOrderUtil(root->left);
        postOrderUtil(root->right);
        cout << "City Name: " << root->data.getCityName() << endl;
        cout << "Latitude: " << root->data.getLatitude() << endl;
        cout << "Longitude: " << root->data.getLongitude() << endl;
    }
}