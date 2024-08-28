#ifndef UI_H
#define UI_H
#include "KD_tree.h"
#include <cstring>

using namespace std;

void interfaceMenu(KD_tree &Tree, int mode);
void showMenu();
int handleMode();
int handleOutputMode();

bool handleStringToDouble(string s, double &val);
bool handleStringToInt(string s, int &val);

vector<City> modeLoadCity();
void modeInsertNewCity(KD_tree &Tree);
void modeInsertMultiNewCity(KD_tree &Tree);
void modeNearestNeighborSearch(KD_tree &Tree);
void modeRangeSearch(KD_tree &Tree);

void outputRangeSearchConsole(vector<Node*> res, int resSize);
void outputRangeSearchCSV(vector<Node*> res, int resSize);


#endif // UI_H