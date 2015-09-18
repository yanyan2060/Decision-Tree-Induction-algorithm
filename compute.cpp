#include "compute.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include "MyCell.h"

using namespace std;
int compute(vector<MyCell>original, vector<vector<string>>&ds, vector<vector<int>> &dscnt)    //to choose the biggest infomation value of attribute
{
	double info_D = 0;
	for (int col = 0; col < original[0].attriValue.size(); col++)
	{
		vector<string> d; //different name of the every attributes
		vector<int> cnt;  //correspoding to d counter
		d.push_back(original[0].attriValue[col]);
		cnt.push_back(1);

		for (size_t row = 1; row < original.size(); row++)
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
					else
					{
						continue;
					}
				}
			}
		}

		ds.push_back(d);
		dscnt.push_back(cnt);
	}
	for (size_t r = 1; r < dscnt[dscnt.size() - 1].size(); r++)       //compute the Info(D)
	{
		double up = dscnt[dscnt.size() - 1][r];
		double down = original.size() - 1;
		double temp = up / down;
		info_D = info_D - (temp)*log2(temp);

	}
	cout << info_D << endl;   //test for Info(D)
	
	vector<double> information;
	vector<vector<vector<string>>> Dname;
	for (size_t r = 0; r < ds.size() - 1; r++)
	{
		double inf1 = 0;
		vector<vector<string>> dsline;
		for (size_t c = 1; c < ds[r].size(); c++)
		{

			vector<string> yn;
			string temp = ds[r][c];
			for (int col = 0; col < original[0].attriValue.size() - 1; col++)
			{
				for (size_t row = 1; row < original.size(); row++)
				{
					if (temp == original[row].attriValue[col])
					{
						yn.push_back(original[row].attriValue[original[row].attriValue.size() - 1]);
					}

				}
			}
			dsline.push_back(yn);

		}
		Dname.push_back(dsline);

		vector<vector<int>> nums;
		for (size_t m = 0; m < dsline.size(); m++)
		{
			vector<string> na;
			vector<int> number;
			na.push_back(dsline[m][0]);
			number.push_back(1);
			for (size_t n = 1; n < dsline[m].size(); n++)
			{
				string temp2 = dsline[m][n];
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

			for (size_t a = 0; a < number.size(); a++)
			{
				double d1 = original.size() - 1;
				double u2 = number[a];
				double d2 = dscnt[r][m + 1];
				double v1 = d2 / d1;
				double v2 = u2 / d2;

				inf1 = inf1 - v1*(v2*log2(v2));
			}

			nums.push_back(number);


		}
		information.push_back(inf1);
	}

	vector<double> gain;                                 //attribute gains
	for (size_t p = 0; p < information.size(); p++)
	{
		double t = info_D - information[p];
		gain.push_back(t);
	}
	for (size_t p = 0; p < information.size(); p++)
	{
		
		cout << ds[p][0] << " " << "gain: " << gain[p] << endl;
	}
	double max = gain[0];
	int num = 0;
	for (size_t q = 1; q < gain.size(); q++)
	{
		if (gain[q]>max)
		{
			max = gain[q];
			num = q;
		}
	}
	cout << num << endl;
	return num;                                    // num:the same as the index of the chosen attribute in the original data table
	
	
}

string most(vector<vector<string>>ds, vector<vector<int>>dscnt)
{
	int com = dscnt[dscnt.size() - 1][0];
	int a = 0;
	for (size_t c =0; c < dscnt[dscnt.size() - 1].size(); c++)
	{
		if (dscnt[dscnt.size() - 1][c]>com)
		{
			com = dscnt[dscnt.size() - 1][c];
			a = c;
		}
	}
	return ds[ds.size() - 1][a];
}

string most3(vector<vector<string>>ds, vector<vector<double>>dscnt)
{
	int com = dscnt[dscnt.size() - 1][0];
	int a = 0;
	for (size_t c = 0; c < dscnt[dscnt.size() - 1].size(); c++)
	{
		if (dscnt[dscnt.size() - 1][c]>com)
		{
			com = dscnt[dscnt.size() - 1][c];
			a = c;
		}
	}
	return ds[ds.size() - 1][a];
}