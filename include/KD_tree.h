#ifndef KD_TREE_H
#define KD_TREE_H
#include "Util.h"
#include <fstream>
#include <sstream>

using namespace std;
// Include any necessary libraries or headers

struct KD_tree
{
    Node* root;
    KD_tree();
    ~KD_tree();
};

void insert(Node* &root, City city, int depth);
Node* search(Node* root, City city, int depth);

void preOrder(Node* root);
void inOrder(Node* root);
void postOrder(Node* root);

void deleteTree(Node* &root);
vector<City> readFile(string filePath);
vector<Node*> searchRange(Node* root, Point2D bottom_left, Point2D top_right);
Node* searchNearestNeighbor(Node* root, Point2D point);

#endif // KD_TREE_H