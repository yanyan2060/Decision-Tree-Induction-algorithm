#pragma once
#include <string>
#include <vector>

using namespace std;

class MyCell
{
public:
	MyCell();
	~MyCell();
	bool operator==(const MyCell&cell);

	int attriNum;
	vector<string> attriValue;

};

