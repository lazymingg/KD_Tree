#include "include/UI.h"

int main()
{
    KD_tree Tree;

    while (true)
    {
        showMenu();
        int mode = handleMode();
        if (mode == 0)
        {
            cout << "Closing program..." << endl;
            break;
        }
        else if (mode < 1 || mode > 7)
        {
            cout << "Invalid mode!!!" << endl;
        }
        else
        {
            interfaceMenu(Tree, mode);
        }
    }

    deleteTree(Tree.root);
    return 0;
}