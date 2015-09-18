#pragma once
#include <string>
#include <vector>
#include "MyCell.h"

using namespace std;
int compute(vector<MyCell>original, vector<vector<string>>&ds, vector<vector<int>> &dscnt);
string most(vector<vector<string>>ds, vector<vector<int>>dscnt);
string most3(vector<vector<string>>ds, vector<vector<double>>dscnt);


