#ifndef UTIL_H
#define UTIL_H
#include "Node.h"
#include <vector>

struct point2D {
    float latitude, longitude;
};

Node* createNode(City city);
void insertUtil(Node* &pRoot, City city, int depth = 0);
void preOrderUtil(Node *root);
void inOrderUtil(Node *root);
void postOrderUtil(Node *root);
void deleteTreeUtil(Node *root);
void deleteNodeUtil(Node *root, City city);
void RangeSearchUtil(vector<Node*>& res, Node* root, const point2D& bottom_left, const point2D& top_right, int depth);

#endif // UTIL_H