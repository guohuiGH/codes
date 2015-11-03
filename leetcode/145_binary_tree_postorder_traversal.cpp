/*************************************************************************
    > File Name: 145_binary_tree_postorder_traversal.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Tue 03 Nov 2015 06:48:35 PM CST
 ************************************************************************/

#include<iostream>
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
		    traversal(root->right,v);
			v.push_back(root->val);
			
			
		}
		return;
	}
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ve;
		if (root==NULL)
			return ve;
		traversal(root, ve);
		return ve;
    }
};
