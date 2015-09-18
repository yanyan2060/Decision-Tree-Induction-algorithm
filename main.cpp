#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include "MyCell.h"
#include "compute.h"
#include "Tree.h"
#include "Tree3.h"
#include "generate_tree.h"
#include "compute2.h"
#include "ginicompute.h"
#include "verify.h"
#include <time.h>


using namespace std;

int main()
{

	ifstream infile;
	infile.open("F:\\588\\588_project3\\Audiology data training.txt", std::ifstream::in);//Audiology data training
	vector<MyCell> original;
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
		original.push_back(*cell);
		delete cell;
	}
	/*for (size_t i = 0; i < original.size(); i++)        //test reading file
	{
	for (int j = 0; j < original[i].attriNum; j++)
	{
	cout << original[i].attriValue[j]<<",";
	}
	cout << endl;
	}*/
	clock_t start_time = clock();   //time begin
	double info_D = 0;
	vector<vector<string>> ds;

//	vector<vector<int>> dscnt;            // way1 and way2
	vector<vector<double>> dscnt;         //way3
	vector<vector<string>> sub;
	string chattri;
//    int num = compute(original, ds, dscnt);    // can choose compute 1 2 3 	int num = compute3(original, ds, dscnt,sub,chattri);
	int num = compute3(original, ds, dscnt, sub, chattri);
	string choose = original[0].attriValue[num];
	cout << "choose attribute: " << choose << endl;
	//vector<MyCell> newdata;

//	string retrunmostname=most(ds, dscnt);            //way1 and way2
	string retrunmostname = most3(ds, dscnt);            //way3
//	Tree* N = new Tree();  //the root of the decision tree    for compute 12 build decision tree
//	N->name = choose;
    Tree3* D = new Tree3();
	D->name = choose;
//		generate_tree(N, original, num, ds, dscnt, retrunmostname);       //way1 and way2
    tree_3(D, original, num, ds, sub, dscnt, retrunmostname);
	vector<MyCell> data;
	testing(data);
	vector<double> count;
	for (int m = 1; m < data.size(); m++)
	{
	//	verify(N, data, m, count);   
		verify3(D, data, m, count); 

	}
			double rate = 0;
		double sum = 0;
		for (int i = 0; i < count.size(); i++)
		{
			sum = sum + count[i];
		}
		rate = sum / count.size();
		cout << "accurate rate is: " << rate << endl;

		clock_t end_time = clock();
		cout << "Running time is: " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;


	
}

