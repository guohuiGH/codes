/*************************************************************************
    > File Name: 119_pascal_triangle_2.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Thu 15 Oct 2015 03:25:39 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {

		vector<int> ve(rowIndex+1);
		if (rowIndex <0)
			return ve;
		for (int i = 0; i <= rowIndex; i++) {
			ve[i] = 1;
			for (int j = i-1;j >= 1; j--) {
				ve[j] += ve[j-1];
			}
		}
		
		return ve;
	}
};

int main () {
	Solution s;
	vector<int> ve;
	ve = s.getRow(3);
	for (int i = 0; i < ve.size(); i++) {

		cout << ve[i] << " ";
	}
	return 0;

}
