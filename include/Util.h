#ifndef UTIL_H
#define UTIL_H
#include "Node.h"
#include <vector>
#include <algorithm>

const int START_DEPTH = 1;

void searchRangeUtil_case1(vector<Node*>& res, Node* root, Point2D bottom_left, Point2D top_right, int depth);
void searchRangeUtil_case2(vector<Node*>& res, Node* root, Point2D bottom_left, Point2D top_right, int depth);
void searchNearestNeighborUtil(Node* root, Point2D point, Node*& nearestCity, double& minDistance, int depth);

#endif // UTIL_H