#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <vector>
#include "City.h"

using namespace std;

// city,lat,lng,country,population
// essential information including latitude, longitude, and city names
// from the dataset.

struct Node
{
    Node *left;
    Node *right;
    City data;

    Node();
    Node(City city, Node *left, Node *right);
    ~Node();
};

Node* createNode(City city);

#endif // NODE_H