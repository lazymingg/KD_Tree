#ifndef UTIL_H
#define UTIL_H
#include "Node.h"

struct point2D {
    float x, y;
};

Node* createNode(City city);
void insertUtil(Node* &pRoot, City city, int depth = 0);
void preOrderUtil(Node *root, int& order);
void inOrderUtil(Node *root, int& order);
void postOrderUtil(Node *root, int& order);
void deleteNodeUtil(Node *root, City city);
Node** RangeSearchUtil(Node* root, point2D bottom_left, point2D top_right);

#endif // UTIL_H