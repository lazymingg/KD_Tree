#include "include/KD_tree.h"

int main()
{
    KD_tree tree;
    readFile(tree.root, "data.csv");
    preOrder(tree.root);

    Point2D bottom_left, top_right;
    cout << "Input bottom_left's latitude: ";
    cin >> bottom_left.latitude;
    cout << "Input bottom_left's longitude: ";
    cin >> bottom_left.longitude;
    cout << "Input top_right's latitude: ";
    cin >> top_right.latitude;
    cout << "Input top_right's longitude: ";
    cin >> top_right.longitude;
    vector<Node*> Range = searchRange(tree.root, bottom_left, top_right);

    for (int i = 0; i < Range.size(); i++)
        cout << i + 1 << ". " << Range[i]->data.cityName << ": " << Range[i]->data.location.latitude << " - " << Range[i]->data.location.longitude << endl;

    deleteTree(tree.root);

    return 0;
}