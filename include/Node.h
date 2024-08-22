#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "City.h"
// city,lat,lng,country,population
// essential information including latitude, longitude, and city names
// from the dataset.

class Node
{
public:
    Node();
    Node(City city, Node *left, Node *right);
    Node* createNode(City city);
    ~Node();

private:
    Node *left;
    Node *right;
    City data;
};

#endif // NODE_H