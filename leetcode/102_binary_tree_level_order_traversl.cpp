/*************************************************************************
    > File Name: 102_binary_tree_level_order_traversl.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sun 11 Oct 2015 02:27:14 PM CST
 ************************************************************************/


#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	
	vector<vector<int> >levelOrderBottom(TreeNode *root) {
		vector<vector<int> > ve,result;
		vector<vector<int> >::iterator it;
		vector<int>v;
		queue<TreeNode*>q;
		if (root == NULL)
			return ve;
		q.push(root);
		TreeNode *flag = NULL;
		q.push(flag);
		while (!q.empty()) {
			TreeNode *t = q.front();
			q.pop();

			if (!t && !v.empty()) {
				ve.push_back(v);
				v.clear();
				q.push(flag);
			}
			if (t) {
				if (t->left)
					q.push(t->left);
				if (t->right)
					q.push(t->right);
				v.push_back(t->val);
			}
			
		}

		return ve;
	}
};

int main () {
	TreeNode *t1 = new TreeNode(3);
	TreeNode *t2 = new TreeNode(9);
	TreeNode *t3 = new TreeNode(20);
	TreeNode *t4 = new TreeNode(15);
	TreeNode *t5 = new TreeNode(7);
	t1->left = t2;
	t1->right = t3;
	t3->left = t4;
	t3->right = t5;
	Solution s;
	vector<vector<int> > ve = s.levelOrderBottom(t1);
	for (int i = 0; i < ve.size(); i++) {
		cout << ve[i][0] <<" " << ve[i][1] << endl;

	}
	return 0;
}
