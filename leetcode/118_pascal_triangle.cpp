/*************************************************************************
    > File Name: 118_pascal_triangle.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Thu 15 Oct 2015 12:29:36 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> >vec;
		vector<int>v;
		if (numRows == 0)
			return vec;
		if (numRows == 1) {	
			v.push_back(1);
			vec.push_back(v);
			return vec;
		}
		v.push_back(1);
		vec.push_back(v);
		for (int i = 1; i < numRows; i++) {
			vector<int>temp;
			for (int j = 0; j < i+1; j++) {
				if (j==0 || j == i)
					temp.push_back(1);
				else
					temp.push_back(v[j]+v[j-1]);
			}
			vec.push_back(temp);
			v.clear();
			v = temp;
		}
		return vec;


	}
};
int main () {
	vector<vector<int> > ve;
	Solution s;
	ve = s.generate(5);
	for (int i = 0; i < ve.size(); i++){
		for (int j = 0; j < ve[i].size(); j++) {
			cout << ve[i][j] << " ";			
		}
		cout << endl;
	}
}
