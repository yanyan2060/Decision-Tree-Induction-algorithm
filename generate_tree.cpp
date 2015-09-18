#include "Tree.h"
#include "generate_tree.h"
#include "newtable.h"
#include "ginicompute.h"


using namespace std;
void  generate_tree(Tree* R, vector<MyCell>&original, int &num, vector<vector<string>> &ds, vector<vector<int>> &dscnt,  string retrunmostname)
{
	if (dscnt[dscnt.size()-1].size()==2)       // dscnt the last line is the different number of the each class the first one is the class name so the size would be 2 if there is only one class
	{
		R->name = ds[ds.size() - 1][1];
		
		
	}
	else
	{
	
	
			for (size_t m = 1; m < ds[num].size(); m++)
			{
				string upperedge = ds[num][m];
			    vector<MyCell>newdata=newtable(num, ds[num][m], original, ds);
				/*for (size_t r = 0; r < newdata.size(); r++)
				{
					for (size_t c = 0; c < newdata[r].attriValue.size(); c++)
					{
						cout << newdata[r].attriValue[c]<<" ";
					}
					cout << endl;
				}*/
				if (newdata[0].attriValue.size() == 1)      // newdata is the new table after delete the chosen attribute the class attribute would not be delete so the size would be 1
				{
					R->name = retrunmostname;
					R->upperline = upperedge;
					break;
				}
				if (newdata.size() == 1)     //the firs line of newdata is the attribute name
				{
					Tree* child = new Tree;
					child->name = retrunmostname;
					child->upperline = upperedge;
					child->father = R;
					R->child.push_back(child);
					break;
				}
				else
				{
					vector<vector<string>> ds;
					vector<vector<int>> dscnt;
					int numm = compute(newdata, ds, dscnt);   // can choose way 1 2 3 to compute the chosen attribute
					string chname = newdata[0].attriValue[numm];
					//cout <<"choose attribute: "<< chname << endl;
					Tree* child = new Tree();
					child->name = chname;
					child->upperline = upperedge;
					child->father = R;
					R->child.push_back(child);
					generate_tree(child, newdata, numm, ds, dscnt, retrunmostname);
				}
			}
		
	}
}

void  tree_3(Tree3* R, vector<MyCell>&original, int &num, vector<vector<string>> &ds,vector<vector<string>> &sub, vector<vector<double>> &dscnt, string retrunmostname)
{
	if (dscnt[dscnt.size()-1].size()==1)       // dscnt the last line is the different number of the each class the first one is the class name so the size would be 2 if there is only one class
	{
		R->name = ds[ds.size() - 1][1];
		
		
	}
	else
	{
	
	
			for (size_t m = 0; m < sub.size(); m++)
			{
				
				vector<MyCell>newdata = newtable3(num,  sub, original,ds);
				vector<string> upperedge = sub[m];
				if (sub[m].size() == 1)
				{
					Tree3* child = new Tree3;
					child->name = retrunmostname;
					child->upperline = upperedge;
					child->father = R;
					R->child.push_back(child);
					break;
				}
				if (newdata[0].attriValue.size() == 1)      // newdata is the new table after delete the chosen attribute the class attribute would not be delete so the size would be 1
				{
					R->name = retrunmostname;
					//R->upperline = upperedge;
					break;
				}
				if (newdata.size() == 1)     //the firs line of newdata is the attribute name
				{
					Tree3* child = new Tree3;
					child->name = retrunmostname;
					child->upperline = upperedge;
					child->father = R;
					R->child.push_back(child);
					break;
				}
				else
				{
					vector<vector<string>> ds;
					vector<vector<double>> dscnt;
					vector<vector<string>> sub;
					string chattri;
					int numm = compute3(newdata, ds, dscnt, sub, chattri);   // can choose way 1 2 3 to compute the chosen attribute
					string chname = newdata[0].attriValue[numm];
					Tree3* child = new Tree3();
					child->name = chname;
					child->upperline = upperedge;
					child->father = R;
					R->child.push_back(child);
					tree_3(child, newdata, numm, ds,sub, dscnt, retrunmostname);
					
				}
			}
		
	}
}