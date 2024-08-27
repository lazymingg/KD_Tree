#include "include/KD_tree.h"

int main()
{
    KD_tree tree;
    tree.readFile("data.csv");
    tree.preOrder();

    point2D bottom_left, top_right;
    cout << "Input bottom_left's latitude: ";
    cin >> bottom_left.latitude;
    cout << "Input bottom_left's longitude: ";
    cin >> bottom_left.longitude;
    cout << "Input top_right's latitude: ";
    cin >> top_right.latitude;
    cout << "Input top_right's longitude: ";
    cin >> top_right.longitude;
    vector<Node*> Range = tree.RangeSearch(bottom_left, top_right);

    for (int i = 0; i < Range.size(); i++)
        cout << i + 1 << ". " << Range[i]->getData().getCityName() << ": " << Range[i]->getData().getLatitude() << " - " << Range[i]->getData().getLongitude() << endl;

    tree.deleteTree();

    return 0;
}