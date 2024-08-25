#include "../include/Util.h"

// void preOrderUtil(Node *root)
// {
//     if (root != nullptr)
//     {
//         cout << "City Name: " << root->data.getCityName() << endl;
//         cout << "Latitude: " << root->data.getLatitude() << endl;
//         cout << "Longitude: " << root->data.getLongitude() << endl;
//         preOrderUtil(root->left);
//         preOrderUtil(root->right);
//     }
// }

// void inOrderUtil(Node *root)
// {
//     if (root != nullptr)
//     {
//         inOrderUtil(root->left);
//         cout << "City Name: " << root->data.getCityName() << endl;
//         cout << "Latitude: " << root->data.getLatitude() << endl;
//         cout << "Longitude: " << root->data.getLongitude() << endl;
//         inOrderUtil(root->right);
//     }
// }

// void postOrderUtil(Node *root)
// {
//     if (root != nullptr)
//     {
//         postOrderUtil(root->left);
//         postOrderUtil(root->right);
//         cout << "City Name: " << root->data.getCityName() << endl;
//         cout << "Latitude: " << root->data.getLatitude() << endl;
//         cout << "Longitude: " << root->data.getLongitude() << endl;
//     }
// }

void RangeSearchUtil(vector<Node*>& res, Node* root, const point2D& bottom_left, const point2D& top_right, int depth)
{
    if (!root)
        return;
    
    if (root->getData().getLongitude() >= bottom_left.longitude && root->getData().getLatitude() >= bottom_left.latitude && 
        root->getData().getLongitude() <= top_right.longitude && root->getData().getLatitude() <= top_right.latitude)
        res.push_back(root);


    if (depth % 2 == 0)
    {
        if (bottom_left.latitude <= root->getData().getLatitude())
            RangeSearchUtil(res, root->getLeft(), bottom_left, top_right, depth + 1);
        if (top_right.latitude >= root->getData().getLatitude())
            RangeSearchUtil(res, root->getRight(), bottom_left, top_right, depth + 1);
    }

    else 
    {
        if (bottom_left.longitude <= root->getData().getLongitude()) {
            RangeSearchUtil(res, root->getLeft(), bottom_left, top_right, depth + 1);
        }
        if (top_right.longitude >= root->getData().getLongitude()) {
            RangeSearchUtil(res, root->getRight(), bottom_left, top_right, depth + 1);
        }
    }
}