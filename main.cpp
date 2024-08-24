#include "include/KD_tree.h"

int main()
{
    KD_tree tree;
    tree.readFile("data.csv");
    tree.preOrder();
    return 0;
}