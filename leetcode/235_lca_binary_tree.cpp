/*************************************************************************
    > File Name: 235_lca_binary_tree.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Wed 23 Sep 2015 03:22:48 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)
			return NULL;
		if (root->val > p->val && root->val > q->val)
			lowestCommonAncestor(root->left, p, q);
		else if (root->val < p->val && root->val < q->val)
			lowestCommonAncestor(root->right, p, q);
		else
			return root;
	}
};

int main () {
	Solution s;

}
