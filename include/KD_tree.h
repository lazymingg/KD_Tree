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
    void search(City city);
    void preOrder();
    void inOrder();
    void postOrder();
    void deleteNode(City city);
    void nearestNeighbor(City city);
    void rangeSearch(City city1, City city2);
    void readFile(string fileName);

    // Destructor
    ~KD_tree();

private:
    // Member variables
    Node *root;

    void insertNode(Node* &pRoot, City city, int depth);
    void getPreOrder(Node* pRoot);
    void getInOrder(Node* pRoot);
    void getPostOrder(Node* pRoot);
    void deleteTree();
};
// Declare any member variables or functions

#endif // KD_TREE_H