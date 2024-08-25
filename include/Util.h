#ifndef UTIL_H
#define UTIL_H
#include "Node.h"

Node* createNode(City city);
void insertUtil(Node* &pRoot, City city, int depth = 0);
void preOrderUtil(Node *root, int& order);
void inOrderUtil(Node *root, int& order);
void postOrderUtil(Node *root, int& order);
void deleteNodeUtil(Node *root, City city);

#endif // UTIL_H