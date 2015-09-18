#include "newtable.h"
#include "MyCell.h"
using namespace std;
vector<MyCell> newtable(int num, string dsname,vector<MyCell>&original,vector<vector<string>> &ds)
{
	vector<MyCell> newdata;
	vector<int> index;
	newdata.push_back(original[0]);
	
		for (size_t r = 0; r < original.size();r++)
		{
			string temp3 = dsname;
			if (original[r].attriValue[num]== temp3)
			{
				MyCell* cell = new MyCell();
				cell->attriValue=original[r].attriValue;
				cell->attriNum = original[r].attriValue.size();
				newdata.push_back(*cell);
				delete cell;
			}
		}
		
	
	for (size_t row = 0; row < newdata.size(); row++)
	{
		newdata[row].attriValue.erase( newdata[row].attriValue.begin() + (num));
	}
	return newdata;
}

vector<MyCell> newtable3(int num, vector<vector<string>> &sub, vector<MyCell>&original, vector<vector<string>> &ds)
{
	vector<MyCell> newdata;
	vector<int> index;
	newdata.push_back(original[0]);

	for (size_t r = 0; r < original.size(); r++)
	{
		for (size_t i = 0; i < sub[0].size(); i++)
		{
			string temp3 = sub[0][i];
			if (original[r].attriValue[num] == temp3)
			{
				MyCell* cell = new MyCell();
				cell->attriValue = original[r].attriValue;
				cell->attriNum = original[r].attriValue.size();
				newdata.push_back(*cell);
				delete cell;
			}
		}
		
	}


	for (size_t row = 0; row < newdata.size(); row++)
	{
		newdata[row].attriValue.erase(newdata[row].attriValue.begin() + (num));
	}
	return newdata;
}