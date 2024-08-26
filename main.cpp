#include "include/KD_tree.h"

int main()
{
    KD_tree tree;
    readFile(tree.root, "data.csv");
    preOrder(tree.root);

    Point2D bottom_left = inputPoint2D("bottom_left point"),
            top_right = inputPoint2D("top_right point");

    vector<Node*> Range = searchRange(tree.root, bottom_left, top_right);

    for (int i = 0; i < Range.size(); i++)
        cout << i + 1 << ". " << Range[i]->data.cityName << ": " << Range[i]->data.location.latitude << " - " << Range[i]->data.location.longitude << endl;

    deleteTree(tree.root);

    return 0;
}