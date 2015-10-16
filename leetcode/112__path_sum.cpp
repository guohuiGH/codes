/*************************************************************************
    > File Name: 112__path_sum.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Fri 16 Oct 2015 10:14:26 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x),left(NULL),right(NULL){}
};

class Solution {
    int flag = 0;
    void pathSum(TreeNode *root, int value, int sum) {
		if (root!=NULL) {
			value += root->val;
			pathSum(root->left, value, sum);
		    pathSum(root->right, value, sum);
		    if (!root->left && !root->right && value == sum) {
		        flag = 1;
		    }
		}
		
		
	}
	bool hasPathSum(TreeNode *root, int sum) {

		if (!root)
			return false;
		
		pathSum(root, 0, sum);
		if (flag)
			return true;
		return false;
	}
};

int main () {
	
	cout << "hi";
	TreeNode *t1 = new TreeNode(5);
	TreeNode *t2 = new TreeNode(5);
	TreeNode *t3 = new TreeNode(5);
	TreeNode *t4 = new TreeNode(5);
	TreeNode *t5 = new TreeNode(5);
	t1->left = t2;
	t1->right = t3;
	t2->left = t4;
	t3->right = t5;
	Solution s;
	cout << s.hasPathSum(t1,15);
	return 0;
}
