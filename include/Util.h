#ifndef UTIL_H
#define UTIL_H
#include "Node.h"
#include <vector>

void insertUtil(Node* &pRoot, City city, int depth = 0);
void preOrderUtil(Node *root);
void inOrderUtil(Node *root);
void postOrderUtil(Node *root);
void deleteTreeUtil(Node *root);
void deleteNodeUtil(Node *root, City city);
// void RangeSearchUtil(vector<Node*>& res, Node* root, const Point2D& bottom_left, const Point2D& top_right, int depth);
Node* searchNodeUtil(Node* pRoot, City city, int depth);

#endif // UTIL_H