#ifndef SERIALIZE_H
#define SERIALIZE_H

// Include any necessary libraries or headers
#include "KD_tree.h"

using namespace std;

void serializeKDTree(string filePath, Node* root);
void serializeKDTreeNode(fstream &fs, Node* node);

Node* deserializeKDTreeNode(fstream &fs);
KD_tree deserializeKDTree(string filePath);

#endif // SERIALIZE_H