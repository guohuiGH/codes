/*************************************************************************
    > File Name: 113_path_sum2.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Mon 26 Oct 2015 03:37:36 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int> > vec;

	void path(TreeNode *root, string str, int value, int sum) {
		char temp[100];
		sprintf(temp, "%d", root->val);
		str += string(temp);

		value += root->val;
		if (!root->left && !root->right && value == sum) {
			int j = 0;
			vector<int>v;
			for (int i = 0; i < str.size(); i++) {
				if (str[i]=='@') {
					string s = str.substr(j,i-j);
					v.push_back(atoi(s.c_str()));
					j = i+1;
				}
			}

			string s = str.substr(j,str.size()-j);
			v.push_back(atoi(s.c_str()));
			vec.push_back(v);
		}
		if (root->left || root->right)
			str += "@";
		if (root->left) {
			
			path(root->left,str,value, sum);
		}
		if (root->right) {
			path(root->right, str, value, sum);
		}

	}
	vector<vector<int> > binaryTreePahts(TreeNode *root, int sum) {
		vector<vector<int> > v;
		if (!root)
			return v;

		path(root,"", 0, sum);
		return vec;
	}
};

int main () {
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(-52);
	TreeNode *t3 = new TreeNode(3);
	TreeNode *t4 = new TreeNode(5);
	t1->left = t2; t1->right = t3; t2->right = t4;
	Solution s;
	vector<vector<int> > ve;
	ve = s.binaryTreePahts(t1, -46);
	for (int i = 0; i < ve.size(); i++) {
		for (int j = 0; j < ve[i].size(); j++) {
			cout << ve[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
