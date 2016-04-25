/*************************************************************************
    > File Name: 108_convert_sorted_array_to_BST.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年04月25日 星期一 14时02分06秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x): val(x), left(NULL), right(NULL){};
};

class Solution {
public:
	TreeNode * generateBST(vector<int>&nums, int left, int right) {
		if (left == right)
			return NULL;
		if (right-left == 1)
			return new TreeNode(nums[left]);

		int mid = (left+right)/2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = generateBST(nums,left, mid);
		root->right = generateBST(nums, mid+1,right);
		return root;

	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int size = nums.size();
		return generateBST(nums,0, size);
	}
};

int main () {
	int a[5] = {1,2,3,4,5};
	Solution s;
	vector<int> v(a,a+5);
	s.sortedArrayToBST(v);
}
