#ifndef KD_TREE_H
#define KD_TREE_H
#include "Util.h"
#include <fstream>
#include <sstream>

using namespace std;
// Include any necessary libraries or headers

// Define your class or struct here
class KD_tree
{
public:
    // Constructor
    KD_tree();

    void insert(City city);
    Node* search(City city);

    void preOrder();
    void inOrder();
    void postOrder();

    void deleteTree();
    void deleteNode(City city);
    void nearestNeighbor(City city);
    void readFile(string fileName);
    vector<Node*> RangeSearch(const point2D& bottom_left, const point2D& top_right);

    // Destructor
    ~KD_tree();

private:
    // Member variables
    Node *root;

    void insertNode(Node* &pRoot, City city, int depth);
    void deleteTree();
};
// Declare any member variables or functions

#endif // KD_TREE_H