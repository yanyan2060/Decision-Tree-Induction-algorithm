#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Tree.h"
#include "Tree3.h"
#include "compute.h"
#include "compute2.h"
#include "newtable.h"
using namespace std;

void generate_tree(Tree* R, vector<MyCell>&original, int &num, vector<vector<string>> &ds, vector<vector<int>> &dscnt,string retrunmostname);
void  tree_3(Tree3* D, vector<MyCell>&original, int &num, vector<vector<string>> &ds, vector<vector<string>> &sub, vector<vector<double>> &dscnt, string retrunmostname);