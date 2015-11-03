/*************************************************************************
    > File Name: 257_binary_tree_path.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sun 25 Oct 2015 11:16:15 AM CST
 ************************************************************************/

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
	vector<string> vec;


	void path(TreeNode *root, string str) {
		char temp[100];

		sprintf(temp, "%d", root->val);
		str += string(temp);
		if (!root->left && !root->right) {

			vec.push_back(str);

		}
		if (root->left || root->right)
			str += "->";
		if (root->left) {
			
			path(root->left,str);
		}
		if (root->right) {
			path(root->right, str);
		}

	}
	vector<string> binaryTreePahts(TreeNode *root) {
		vector<string> v;
		if (!root)
			return v;

		path(root,"");
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
	vector<string> ve;
	ve = s.binaryTreePahts(t1);
	for (int i = 0; i < ve.size(); i++) {
		cout << ve[i] << endl;
	}
	return 0;
}
