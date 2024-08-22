#ifndef UTIL_H
#define UTIL_H
#include "Node.h"

Node* createNode(City city);
void insertUtil(Node* &pRoot, City city, int depth = 0);
void preOrderUtil(Node *root);
void inOrderUtil(Node *root);
void postOrderUtil(Node *root);
void deleteNodeUtil(Node *root, City city);

#endif // UTIL_H