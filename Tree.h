#pragma once

#include <vector>
#include <string>
using namespace std;

class Tree
{
public:
	Tree();
	~Tree();
	string name;
	string upperline;
	vector<Tree*> child;
	Tree* father;


};

