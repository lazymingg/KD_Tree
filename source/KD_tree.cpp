#include "../include/KD_tree.h"

KD_tree::KD_tree()
{
    root = nullptr;
}
KD_tree::~KD_tree()
{
    // Destructor
}
void KD_tree::insert(City city)
{
    insertUtil(root, city, 0);
}
void KD_tree::preOrder()
{
    preOrderUtil(root);
}
void KD_tree::inOrder()
{
    inOrderUtil(root);
}
void KD_tree::postOrder()
{
    postOrderUtil(root);
}