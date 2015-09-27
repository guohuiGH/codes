/*************************************************************************
    > File Name: 226_invert_binary_tree.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Tue 22 Sep 2015 07:24:08 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
			return NULL;
		TreeNode *temp;
		//temp = new TreeNode(root->val);
		//int temp;
		temp = root->right;
		
		root->right = root->left;
		root->left = temp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

int main() {
	Solution so;
	TreeNode *t1, *t2, *t3, *t4;
	t1 = new TreeNode(2);
	t2 = new TreeNode(1);
	t3 = new TreeNode(3);
	t1->left = t2;
	t1->right = t3;
	//cout << so.invertTree(t1)->val << endl;
	t4 = so.invertTree(t1);
	cout << t4->left->val << t4->right->val << endl;
}
