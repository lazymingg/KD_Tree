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

class Node
{
public:
    Node();
    Node(City city, Node *left, Node *right);
    ~Node();

    Node* getLeft();
    Node* getRight();
    City getData();

    void setLeft(Node *node);
    void setRight(Node *node);
    void setData(City city);

    friend class KD_tree;
    Node *left;
    Node *right;
    City data;
private:

};

#endif // NODE_H