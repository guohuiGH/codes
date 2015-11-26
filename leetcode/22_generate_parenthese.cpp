/*************************************************************************
    > File Name: 22_generate_parenthese.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Wed 18 Nov 2015 02:21:36 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

class Solution {
public:

	void dfs(vector<string> &vec, int left, int right, int n, string str) {
		if (left == right && left == n) {
			vec.push_back(str);
			return;
		}else if (left < right || left > n) {
			return;
		}
		string leftp = str, rightp = str;
		leftp.push_back('(');
		rightp.push_back(')'); 
		dfs(vec, left+1, right, n, leftp);
		dfs(vec, left, right+1, n, rightp);
	}

	vector<string> generateParenthesis(int n) {
		vector<string> ve;
		dfs(ve, 0, 0, n, "");
		return ve;
	}
};

int main () {
	Solution s;
	vector<string> v;
	string ss = "";
	ss.push_back('0');
	v = s.generateParenthesis(1);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
