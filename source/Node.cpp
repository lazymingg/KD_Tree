#include "../include/Node.h"

Node::Node()
{
    left = nullptr;
    right = nullptr;
}

Node::~Node()
{
    // Destructor
}

Node::Node(City city, Node *left, Node *right)
{
    this->data = city;
    this->left = left;
    this->right = right;
}

Node* createNode(City city)
{
    Node *newNode = new Node(city, nullptr, nullptr);
    return newNode;
}