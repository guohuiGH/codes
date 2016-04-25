/*************************************************************************
    > File Name: 106_construct_binary_tree_from_Inorder_Postorder_traversal.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年04月25日 星期一 16时05分42秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL),right(NULL) {};
};

class Solution {
public:

	
	TreeNode* build2(vector<int>&inorder, int inl, int inr, vector<int>postorder, int pol, int por) {
		if (inl == inr)
			return new TreeNode(inorder[inl]);
		TreeNode* root = new TreeNode(inorder[inl]);

		int leftpor = por, leftpol = pol;
		int rightpor = por, rightpol = pol;
		for (int i = pol; i <= por; i++) {
			if (postorder[i] == inorder[inl]) {
				leftpor = i-1;
				rightpol = i+1;
				break;
			}
		}
		int leftinr = leftpor-leftpol + 1+ inl, leftinl = inl + 1;
		int rightinr = leftinr, rightinl = inli + 1;
		/*
		for (int i = pol; i <= leftpor; i++) {

			for (int j = inl; j<= inr; j++) {
				if (leftpor >= 0 && postorder[i] == inorder[j]) {
					leftinr = max(leftinr,j);
					rightinl = max(rightinl,j+1);
					break;
				}
			}
		}
		*/
		if (leftpor < pol)
			root->left = NULL;
		else
			root->left = build(inorder,leftinl,leftinr,postorder,leftpol, leftpor);
		if (rightpol>por)
			root->right =NULL;
		else
			root->right = build(inorder,rightinl, rightinr,postorder, rightpol, rightpor);
		return root;
	}

	map<int,int>hash;
	TreeNode* build(vector<int>&preorder, int inl, int inr, vector<int>inorder, int pol, int por) {
		if (inl < 0 || inl > inr || pol > por)
			return NULL;
		if (inl == inr)
			return new TreeNode(preorder[inl]);
		int value = preorder[inl];
		int inroot = hash[value];
		TreeNode* root = new TreeNode(value);
		int prer = inl + root-pol ;
		root->left = build(preorder, inl+1, prer, inorder, pol, inroot-1);
		root->right = build(preorder, prer+1, inr, inorder, inroot+1, por);
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>inorder) {
		int size = inorder.size();
		if (size == 0)
			return NULL;
		for (int i = 0; i < size; i++)
			hash[inorder[i]] = i;
		return build(preorder,0,size-1, inorder,0,size-1);
	}
};

int main () {
	return 0;
}
