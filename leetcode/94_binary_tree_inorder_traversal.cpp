/*************************************************************************
    > File Name: 94_binary_tree_inorder_traversal.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Tue 03 Nov 2015 06:41:38 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	void traversal (TreeNode *root, vector<int> &v) {
		if (root) {
			traversal(root->left, v);
			v.push_back(root->val);
			
			traversal(root->right,v);
		}
		return;
	}

	vector<int> preorderTraversal (TreeNode *root) {
		vector<int> ve;
		if (root==NULL)
			return ve;
		traversal(root, ve);
		return ve;
	}
};

int main () {
	Solution s;
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t3 = new TreeNode(3);
	t1->right = t2; t2->left = t3;
	vector<int> ve;
	ve = s.preorderTraversal(t1);
	for (int i = 0; i < ve.size(); i++) {
		cout << ve[i] << endl;
	}
	return 0;
}

