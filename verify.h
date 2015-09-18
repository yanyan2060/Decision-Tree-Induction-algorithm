#pragma once
#include <iostream>
#include "Tree.h"
#include "MyCell.h"
#include <vector>
#include <string>
#include "generate_tree.h"

using namespace std;
vector<MyCell> testing(vector<MyCell> &data);

void  verify(Tree* N, vector<MyCell> data, int m, vector<double> &count);
void  verify3(Tree3* N, vector<MyCell> data, int m, vector<double> &count);

