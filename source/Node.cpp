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

Node* Node::getLeft()
{
    return this->left;
}

Node* Node::getRight()
{
    return this->right;
}

City Node::getData()
{
    return this->data;
}

void Node::setLeft(Node *node)
{
    left = node;
}

void Node::setRight(Node *node)
{
    right = node;
}

void Node::setData(City city)
{
    data = city;
}