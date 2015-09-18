#include "ginicompute.h"
#include <iostream>
#include <math.h>
#include <vector>



using namespace std;

int compute3(vector<MyCell>original, vector<vector<string>>&ds, vector<vector<double>> &dscnt, vector<vector<string>> &sub, string &chattri)    //to choose the biggest infomation value of attribute
{
	double info_D = 0;
	for (int col = 0; col < original[0].attriValue.size(); col++)
	{
		vector<string> d; //different name of the every attributes
		vector<double> cnt;  //correspoding to d counter
		d.push_back(original[1].attriValue[col]);
		cnt.push_back(1);

		for (size_t row = 2; row < original.size(); row++)
		{
			string compare = original[row].attriValue[col];

			for (size_t n = 0; n < d.size(); n++)
			{
				if (compare == d[n])
				{
					cnt[n] += 1;

					break;
				}
				else
				{
					if (n == d.size() - 1)
					{
						d.push_back(compare);
						cnt.push_back(1);
						break;
					}
					
				}
			}
		}

		ds.push_back(d);
		dscnt.push_back(cnt);
	}
	vector<vector<vector<string>>> subset;

	getSubsets(ds, subset);


	vector<double> gini_x;
	vector<vector<string>> gini_value;
	for (size_t i = 0; i < subset.size(); i++)
	{
		for (size_t j = 0; j < subset[i].size(); j++)
		{
			if (subset[i][j].size() != ds[i].size())
			{
				vector<string> yn;
				for (size_t m = 0; m < subset[i][j].size(); m++)
				{

					string temp = subset[i][j][m];
					
					
						for (size_t row = 1; row < original.size(); row++)
						{
							if (temp == original[row].attriValue[i])
							{
								yn.push_back(original[row].attriValue[original[row].attriValue.size() - 1]);
							}

						}
					
				}
				
				double ctasub = yn.size();
				vector<string> na;
				vector<double> number;
				na.push_back(yn[0]);
				number.push_back(1);
				if (yn.size() != 1)
				{
					for (size_t y = 1; y < yn.size(); y++)
					{
						string temp2 = yn[y];
						for (size_t j = 0; j < na.size(); j++)
						{
							if (temp2 == na[j])
							{
								number[j] += 1;
								break;
							}
							else
							{
								if (j == na.size() - 1)
								{
									na.push_back(temp2);
									number.push_back(1);
									break;
								}

							}
						}
					}
				}
				
				double size = original.size() - 1;
				double gini_a = 0;
				double v1 = ctasub / size;
				for (size_t n = 0; n < number.size(); n++)
				{
					double gi = number[n];
					double v2 = gi / ctasub;
					gini_a = gini_a - pow(v2, 2.0);
				}
				double latter = 1 + gini_a;
				double gin = ctasub / size;
				double pre = gin*latter;
				double down = size - ctasub;
				double gini_b = 0;
				for (size_t m = 0; m < na.size(); m++)
				{
					int nu = location(na, ds[ds.size() - 1], m);
					double up = dscnt[dscnt.size() - 1][nu] - number[m];
					double v2 = up / down;
					gini_b = gini_b - pow(v2, 2.0);
				}
				double latter_2 = 1 + gini_b;
				double latter_gini = down / size;
				double lat = latter_gini*latter_2;
				double gini_one = pre + lat;
				gini_x.push_back(gini_one);
				gini_value.push_back(subset[i][j]);
			}

		}

	}
	for (size_t i = 0; i < gini_x.size(); i++)
	{
		cout << gini_x[i] << endl;
	}
	double min = gini_x[0];
	int num = 0;
	int nuu = 0;
	for (size_t q = 1; q < gini_x.size(); q++)
	{
		if (gini_x[q]<min)
		{
			min = gini_x[q];
			nuu = q;
			for (size_t r = 0; r < ds.size() - 1; r++)
			{
				for (size_t c = 1; c < ds[r].size(); c++)
				{
					if (gini_value[q][0] == ds[r][c])
					{
						num = r;
					}
				}
			}
		}

	}
	sub.push_back(gini_value[nuu]);
	vector<string> rest;
	for (int i = 0; i<original.size(); i++)
	{
		rest.push_back(original[i].attriValue[num]);
	}

	for (size_t m = 0; m<gini_value[nuu].size(); m++)
	{
		string com = gini_value[nuu][m];
		for (int r = 0; r<rest.size(); r++)
		{
			if (com == rest[r])
			{
				rest.erase(rest.begin() + r);
				r--;
			}
		}
	}
	vector<string> restsub;
	restsub.push_back(rest[1]);
	
	
		for (int j = 2; j<rest.size(); j++)
		{
			if (restsub[0] != rest[j])
			{
				
					restsub.push_back(rest[j]);
				
			}
		}
	
	sub.push_back(restsub);
	chattri = original[0].attriValue[num];
	return num;
	


}


void getSubsets(vector<vector<string>> out, vector<vector<vector<string>>> &subset)
{
	for (int cnt = 0; cnt < out.size()-1; cnt++)
	{
		vector<bool> line(out[cnt].size(), true);
		vector<vector<bool>> container;
		container.push_back(line);
		for (int i = 0; i < container.size(); i++)
		{
			for (int j = 0; j < container[0].size(); j++)
			{
				vector<bool> newSubset = container[i];
				if (newSubset[j] == true)
				{
					newSubset[j] = false;
				}
				else
				{
					continue;
				}
				for (int n = 0; n < container.size(); n++)
				{
					if (container[n] == newSubset)
					{
						break;
					}
					if (n == container.size() - 1)
					{
						container.push_back(newSubset);
						n++;
					}
				}
			}
		}
		container.pop_back();
		vector<vector<string>> subsets;
		for (int i = 0; i < container.size(); i++)
		{
			vector<string> str;

			for (int j = 0; j < container[i].size(); j++)
			{
				if (container[i][j] == true)
				{
					str.push_back(out[cnt][j]);

				}
			}
			//str.pop_back();
			subsets.push_back(str);
		}
		subset.push_back(subsets);
	}

}

int location(vector<string>data, vector<string>name, int m)
{


	for (size_t n = 0; n < name.size(); n++)
	{
		if (data[m] == name[n])
		{
			return n;
		}
		else
		{
			continue;
		}

	}
	cerr << "location error" << endl;
	exit(-1);
	//return -1;
}
