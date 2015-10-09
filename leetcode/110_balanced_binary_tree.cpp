/*************************************************************************
    > File Name: 110_balanced_binary_tree.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Fri 09 Oct 2015 08:58:40 AM CST
 ************************************************************************/

#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {

public:
	int dfs(TreeNode * root) {
		if (root == NULL)
			return 1;
		int left = dfs(root->left);
		int right = dfs(root->right);
		if (!(left&&right))
			return 0;

		if (abs(left-right) <=1 )
			return max(left,right) + 1;
		return 0;
	}
	bool isBalanced(TreeNode * root) {
		return dfs(root);
		
	}
};

int main () {
	Solution s;
	TreeNode *t1 = new TreeNode(1);
	
	TreeNode *t2 = new TreeNode(1);
	TreeNode *t3 = new TreeNode(1);
	TreeNode *t4 = new TreeNode(1);
	t1->left = t2;
	t2->left = t3;
	t3->left = t4;
	cout << s.isBalanced(t1);
	return 1;
}
