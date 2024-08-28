#include "../include/Util.h"

// void insertUtil(Node* &pRoot, City city, int depth)
// {
//     if (pRoot == nullptr)
//     {
//         pRoot = createNode(city);
//     }
//     else
//     {
//         int cd = depth % 2;
//         if (cd == 0)
//         {
//             if (city.location.latitude < pRoot->data.location.latitude)
//             {
//                 insertUtil(pRoot->left, city, depth + 1);
//             }
//             else
//             {
//                 insertUtil(pRoot->right, city, depth + 1);
//             }
//         }
//         else
//         {
//             if (city.location.latitude < pRoot->data.location.latitude)
//             {
//                 insertUtil(pRoot->left, city, depth + 1);
//             }
//             else
//             {
//                 insertUtil(pRoot->right, city, depth + 1);
//             }
//         }
//     }
// }

// void preOrderUtil(Node *root)
// {
//     if (root != nullptr)
//     {
//         cout << "City Name: " << root->data.cityName << endl;
//         cout << "Latitude: " << root->data.location.latitude << endl;
//         cout << "Longitude: " << root->data.location.longitude << endl;
//         preOrderUtil(root->left);
//         preOrderUtil(root->right);
//     }
// }

// void inOrderUtil(Node *root)
// {
//     if (root != nullptr)
//     {
//         inOrderUtil(root->left);
//         cout << "City Name: " << root->data.cityName << endl;
//         cout << "Latitude: " << root->data.location.latitude << endl;
//         cout << "Longitude: " << root->data.location.latitude << endl;
//         inOrderUtil(root->right);
//     }
// }

// void postOrderUtil(Node *root)
// {
//     if (root != nullptr)
//     {
//         postOrderUtil(root->left);
//         postOrderUtil(root->right);
//         cout << "City Name: " << root->data.cityName << endl;
//         cout << "Latitude: " << root->data.location.latitude << endl;
//         cout << "Longitude: " << root->data.location.latitude << endl;
//     }
// }

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

// Resolve Search Range's cases:

// bottom_left.longitude < top_right.longitude
void searchRangeUtil_case1(vector<Node*>& res, Node* root, Point2D bottom_left, Point2D top_right, int depth)
{
    if (!root)
        return;
    
    if (root->data.location.longitude >= bottom_left.longitude && root->data.location.latitude >= bottom_left.latitude && 
        root->data.location.longitude <= top_right.longitude && root->data.location.latitude <= top_right.latitude)
        res.push_back(root);


    if (depth % 2 == 0)
    {
        if (bottom_left.latitude <= root->data.location.latitude)
            searchRangeUtil_case1(res, root->left, bottom_left, top_right, depth + 1);
        if (top_right.latitude >= root->data.location.latitude)
            searchRangeUtil_case1(res, root->right, bottom_left, top_right, depth + 1);
    }

    else 
    {
        if (bottom_left.longitude <= root->data.location.longitude)
            searchRangeUtil_case1(res, root->left, bottom_left, top_right, depth + 1);
        if (top_right.longitude >= root->data.location.longitude)
            searchRangeUtil_case1(res, root->right, bottom_left, top_right, depth + 1);
    }
}

// bottom_left.longitude >= top_right.longitude
void searchRangeUtil_case2(vector<Node*>& res, Node* root, Point2D bottom_left, Point2D top_right, int depth)
{
    if (!root)
        return;
    
    if (root->data.location.latitude >= bottom_left.latitude && root->data.location.latitude <= top_right.latitude && 
        (root->data.location.longitude <= top_right.longitude ||  root->data.location.longitude >= bottom_left.longitude))
        res.push_back(root);


    if (depth % 2 == 0)
    {
        if (bottom_left.latitude <= root->data.location.latitude)
            searchRangeUtil_case2(res, root->left, bottom_left, top_right, depth + 1);
        if (top_right.latitude >= root->data.location.latitude)
            searchRangeUtil_case2(res, root->right, bottom_left, top_right, depth + 1);
    }

    else 
    {
        //if (bottom_left.longitude <= root->data.location.longitude)
            searchRangeUtil_case2(res, root->left, bottom_left, top_right, depth + 1);
        //if (top_right.longitude >= root->data.location.longitude)
            searchRangeUtil_case2(res, root->right, bottom_left, top_right, depth + 1);
    }
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

// Nearest Neighbor Search

void searchNearestNeighborUtil(Node* root, Point2D point, Node*& nearestCity, double& minDistance, int depth)
{
    if (!root)
        return;

    double distance = calHaversineDistance(root->data.location, point);
    if (distance < minDistance)
    {
        minDistance = distance;
        nearestCity = root;
    }

    int cd = depth % 2;
    Node *nextBranch = nullptr, *oppositeBranch = nullptr;
    
    if (cd == 0) // Latitude division
    {
        if (point.latitude < root->data.location.latitude)
        {
            nextBranch = root->left;
            oppositeBranch = root->right;
        }
        else
        {
            nextBranch = root->right;
            oppositeBranch = root->left;
        }
    }
    else // Longitude division
    {
        if (point.longitude < root->data.location.longitude)
        {
            nextBranch = root->left;
            oppositeBranch = root->right;
        }
        else
        {
            nextBranch = root->right;
            oppositeBranch = root->left;
        }
    }

    cout << distance << endl;
    searchNearestNeighborUtil(nextBranch, point, nearestCity, minDistance, depth + 1);

    //Calculate the distance to the opposite-side plane
    double DistanceToPlane = (cd == 0)
        ? calHaversineDistance(point, {root->data.location.latitude, point.longitude})
        : calHaversineDistance(point, {point.latitude, root->data.location.longitude});

    cout << DistanceToPlane << " - " << minDistance << endl;
    if (DistanceToPlane < minDistance)
        searchNearestNeighborUtil(oppositeBranch, point, nearestCity, minDistance, depth + 1);
}
