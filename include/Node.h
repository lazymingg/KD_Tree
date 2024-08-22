#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// city,lat,lng,country,population
// essential information including latitude, longitude, and city names
// from the dataset.

class Node {
public:

    Node();

    ~Node();



private:
    Node* left;
    Node* right;
    // city data
};

#endif // NODE_H