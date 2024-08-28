#include "../include/Util.h"

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
    Node* next = nullptr;
    Node* other = nullptr;

    if (cd == 0) // latitude division
    {
        // In bound
        if (fabs(point.latitude - root->data.location.latitude) <= 90)
        {
            if (root->data.location.latitude > point.latitude)
            {
                next = root->left;
                other = root->right;
            }
            else
            {
                next = root->right;
                other = root->left;
            }
        }
        else // Cross bound
        {
            if (root->data.location.latitude > point.latitude)
            {
                next = root->right;
                other = root->left;
            }
            else
            {
                next= root->left;
                other = root->right;
            }
        }

    }
    else // longitude division
    {
        // In bound
        if (fabs(point.longitude - root->data.location.longitude) <= 180)
        {
            if (root->data.location.longitude > point.longitude)
            {
                next = root->left;
                other = root->right;
            }
            else
            {
                next = root->right;
                other = root->left;
            }
        }
        else // Cross bound
        {
            if (root->data.location.longitude > point.longitude)
            {
                next = root->right;
                other = root->left;
            }
            else
            {
                next = root->left;
                other = root->right;
            }
        }   
    }
    
    searchNearestNeighborUtil(next, point, nearestCity, minDistance, depth + 1);

    //Calculate the distance to the opposite-side plane
    double PlaneDistance = (cd == 0)
        ? calHaversineDistance(point, {root->data.location.latitude, point.longitude})
        : calHaversineDistance(point, {point.latitude, root->data.location.longitude});

    if (PlaneDistance < minDistance)
        searchNearestNeighborUtil(other, point, nearestCity, minDistance, depth + 1);
}