#ifndef KD_TREE_H
#define KD_TREE_H
#include "Node.h"
// Include any necessary libraries or headers

// Define your class or struct here
class KD_tree
{
public:
    // Constructor
    KD_tree();
    void insert(City city);
    void search(City city);
    void preOrder();
    void inOrder();
    void postOrder();
    void deleteNode(City city);
    void nearestNeighbor(City city);
    void rangeSearch(City city1, City city2);
    // Destructor
    ~KD_tree();

    // Member functions
private:
    // Member variables
    Node *root;
};
// Declare any member variables or functions

#endif // KD_TREE_H