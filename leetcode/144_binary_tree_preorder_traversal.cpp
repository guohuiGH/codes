/*************************************************************************
    > File Name: 144_binary_tree_preorder_traversal.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Tue 03 Nov 2015 05:17:14 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:


	vector<int> preorderTraversal (TreeNode *root) {
		vector<int> ve;
		stack<TreeNode *> st;
		st.push(root);
		while(!st.empty()) {
			TreeNode *t = st.top();
			st.pop();
			if (t) {
				ve.push_back(t->val);
				st.push(t->right);
				st.push(t->left);
			}
		}
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
