#include "Verify.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<MyCell> testing(vector<MyCell> &data)
{
	ifstream infile;
	infile.open("F:\\588\\588_project3\\Audiology data test.txt", std::ifstream::in);//Audiology data test

	while (infile.eof() != true)
	{

		string str;
		getline(infile, str);
		if (str == "")
		{
			break;
		}

		//cout << str << endl;//test
		vector<string>attri;
		int position = 0;
		int n = -1;
		while (position != string::npos)
		{
			position = n + 1;
			n = str.find(",", position);
			if (n == string::npos)
			{
				attri.push_back(str.substr(position));
				break;
			}
			attri.push_back(str.substr(position, n - position));

		}
		MyCell *cell = new MyCell();
		cell->attriValue = attri;
		cell->attriNum = attri.size();
		data.push_back(*cell);
		delete cell;
	}
	return data;
}

void verify(Tree* N, vector<MyCell> data,int m,vector<double> &count)             //Tree* N for 12 and Tree3* N for 3
{
	
	
		for (size_t c = 0; c < data[0].attriValue.size(); c++)
		{
			if (N->child.size() == 0)
			{
				if (data[m].attriValue[data[m].attriValue.size() - 1] == N->name)
				{
					count.push_back(1);
					break;
				}
				else
				{
					count.push_back(0);
					break;
				}
			}
			else
			{
				if (data[0].attriValue[c] == N->name)
				{
					for (int i = 0; i < N->child.size(); i++)
					{
						if (data[m].attriValue[c] == N->child[i]->upperline)
						{
							verify(N->child[i], data,m,count);
							break;
						}

					}
				}
			}

		}

		
	
	
	
}

void verify3(Tree3* N, vector<MyCell> data, int m, vector<double> &count)             //Tree* N for 12 and Tree3* N for 3
{


	for (size_t c = 0; c < data[0].attriValue.size(); c++)
	{
		if (N->child.size() == 0)
		{
			if (data[m].attriValue[data[m].attriValue.size() - 1] == N->name)
			{
				count.push_back(1);
				break;
			}
			else
			{
				count.push_back(0);
				break;
			}
		}
		else
		{
			if (data[0].attriValue[c] == N->name)
			{
				for (int i = 0; i < N->child.size(); i++)
				{
					for (size_t j = 0; j < N->child[i]->upperline.size(); j++)
					{
						if (data[m].attriValue[c] == N->child[i]->upperline[j])
						{
							verify3(N->child[i], data, m, count);
							break;
						}
					}
					
				}
			}
		}

	}





}