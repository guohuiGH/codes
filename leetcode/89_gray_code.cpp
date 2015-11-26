/*************************************************************************
    > File Name: 89_gray_code.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Wed 18 Nov 2015 10:21:17 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int>ve;
		if (n < 0)
			return ve;
		ve.push_back(0);
		for (int i = 0; i < n; i++) {
			int a = 1<<i;
			int size = ve.size();
			vector<int> temp = ve;
			for (int j = size-1; j >= 0; j--) {
				ve.push_back(a^temp[j]);
			}
		}
		return ve;
	}
};

int main () {
	Solution s;
	vector<int> ve;
	ve = s.grayCode(2);
	for (int i = 0; i < ve.size(); i++) {
		cout << ve[i] << endl;
	}
}


