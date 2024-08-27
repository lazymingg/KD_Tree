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
Node* searchNodeUtil(Node* pRoot, City city, int depth);

void searchRangeUtil_case1(vector<Node*>& res, Node* root, Point2D bottom_left, Point2D top_right, int depth);
void searchRangeUtil_case2(vector<Node*>& res, Node* root, Point2D bottom_left, Point2D top_right, int depth);


#endif // UTIL_H