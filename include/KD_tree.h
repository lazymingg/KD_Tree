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
    void readFile(string fileName);
    vector<Node*> RangeSearch(const point2D& bottom_left, const point2D& top_right);
    void remove();
    // Destructor
    ~KD_tree();

private:
    // Member variables
    Node *root;

    void insertNode(Node* &pRoot, City city, int depth);
    Node* searchNode(Node* pRoot, City &city, int depth);
    void getPreOrder(Node* pRoot, int& order);
    void getInOrder(Node* pRoot, int& order);
    void getPostOrder(Node* pRoot, int& order);
    void deleteTree(Node* &pRoot);
};
// Declare any member variables or functions

#endif // KD_TREE_H