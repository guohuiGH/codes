/*************************************************************************
    > File Name: 101_symmetric_tree.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Fri 09 Oct 2015 10:22:18 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}

};

class Solution {
public:
	bool isSy(TreeNode *left, TreeNode *right) {
		if (left==NULL && right == NULL)
			return true;
		if (left==NULL || right == NULL)
			return false;
		if (left->val== right->val && isSy(left->left, right->right) && isSy(left->right,right->left))
			return true;
		return false;
		
	}
	bool isSymmetric(TreeNode* root) {
		if (root==NULL)
			return true;
		return isSy(root->left, root->right);
	}
};

int main () {
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t3 = new TreeNode(2);
	TreeNode *t4 = new TreeNode(3);
	TreeNode *t5 = new TreeNode(3);
	Solution s;
	t1->left = t2;
	t1->right = t3;
	cout << s.isSymmetric(t1);
	return 1;
}
