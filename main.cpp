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
            break;
        }
        else if (mode < 1 || mode > 5)
        {
            cout << "Invalid mode!!!" << endl;
        }
        else
        {
            interfaceMenu(Tree, mode);
        }
    }

    return 0;
}