/*************************************************************************
    > File Name: 104_maximum_depth_of_binary_tree.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Fri 18 Sep 2015 12:07:30 AM PDT
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL),right(NULL){}
	
};

class Solution {
public:
	int maxDepth(TreeNode *root){
		if (root == NULL)
			return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return max(left, right) + 1;
	}
};

int main() 
{
	TreeNode *treeNode;
	treeNode = new TreeNode(0);
	TreeNode *ri;
	ri = new TreeNode(1);
	treeNode->val = 0;
	treeNode->left = NULL;
	ri->val = 1;
	ri->left = NULL;
	ri->right = NULL;
	treeNode->right = ri;
	Solution so;
/*	printf("%d", so.maxDepth(treeNode));
*/
	cout << so.maxDepth(treeNode);
	return 0;
}

