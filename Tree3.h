#pragma once

#include <vector>
#include <string>
using namespace std;

class Tree3
{
public:
	Tree3();
	~Tree3();
	string name;
	vector<string> upperline;
	vector<Tree3*> child;
	Tree3* father;


};
