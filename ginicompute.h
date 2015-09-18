#pragma once
#include <string>
#include <vector>
#include "MyCell.h"

using namespace std;

int compute3(vector<MyCell>original, vector<vector<string>>&ds, vector<vector<double>> &dscnt, vector<vector<string>> &sub, string &chattri);    //to choose the biggest infomation value of attribute
void getSubsets(vector<vector<string>> out, vector<vector<vector<string>>> &subset);
int location(vector<string>data, vector<string>name, int m);