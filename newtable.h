#pragma once

#include <vector>
#include <string>
#include "MyCell.h"
using namespace std;

vector<MyCell> newtable(int num,string dsname,vector<MyCell>&original, vector<vector<string>> &ds);
vector<MyCell> newtable3(int num, vector<vector<string>> &sub, vector<MyCell>&original, vector<vector<string>> &ds);