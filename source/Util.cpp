#include "../include/Util.h"

// Resolve Search Range's cases:

//  Case 1: Bottom-left point is to the left of the top-right point
void searchRangeUtil_case1(vector<Node*>& res, Node* root, Point2D bottom_left, Point2D top_right, int depth)
{
    if (!root)
        return;
    
    // root.data.location is inside the area of in − Rectangle
    if (root->data.location.longitude >= bottom_left.longitude && root->data.location.latitude >= bottom_left.latitude && 
        root->data.location.longitude <= top_right.longitude && root->data.location.latitude <= top_right.latitude)
        res.push_back(root);

    // root dividing the latitude
    if (depth % 2 == 0)
    {
        if (bottom_left.latitude <= root->data.location.latitude)
            searchRangeUtil_case1(res, root->left, bottom_left, top_right, depth + 1);
        if (top_right.latitude >= root->data.location.latitude)
            searchRangeUtil_case1(res, root->right, bottom_left, top_right, depth + 1);
    }
    // root dividing the longitude
    else 
    {
        if (bottom_left.longitude <= root->data.location.longitude)
            searchRangeUtil_case1(res, root->left, bottom_left, top_right, depth + 1);
        if (top_right.longitude >= root->data.location.longitude)
            searchRangeUtil_case1(res, root->right, bottom_left, top_right, depth + 1);
    }
}

//  Case 2: Bottom-left point is to the right of the top-right point
void searchRangeUtil_case2(vector<Node*>& res, Node* root, Point2D bottom_left, Point2D top_right, int depth)
{
    if (!root)
        return;
    
    // root.data.location is inside the area of out − Rectangle
    if (root->data.location.latitude >= bottom_left.latitude && root->data.location.latitude <= top_right.latitude && 
        (root->data.location.longitude <= top_right.longitude ||  root->data.location.longitude >= bottom_left.longitude))
        res.push_back(root);

    // root dividing the latitude
    if (depth % 2 == 0)
    {
        if (bottom_left.latitude <= root->data.location.latitude)
            searchRangeUtil_case2(res, root->left, bottom_left, top_right, depth + 1);
        if (top_right.latitude >= root->data.location.latitude)
            searchRangeUtil_case2(res, root->right, bottom_left, top_right, depth + 1);
    }
    // root dividing the longitude: search both children because we are not sure which child doesn't need to check
    else 
    {
        searchRangeUtil_case2(res, root->left, bottom_left, top_right, depth + 1);
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

    // root dividing the latitude
    if (cd == 0)
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
    // root dividing the longitude
    else
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

    // Calculate the distance to the opposite-side plane
    double PlaneDistance = (cd == 0)
        ? calHaversineDistance(point, {root->data.location.latitude, point.longitude})
        : calHaversineDistance(point, {point.latitude, root->data.location.longitude});

    // Check the opposite-side branch if PlaneDistance < minDistance because it might be possible that the is a shorter distance there.
    if (PlaneDistance < minDistance)
        searchNearestNeighborUtil(other, point, nearestCity, minDistance, depth + 1);
}