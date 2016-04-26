/*************************************************************************
    > File Name: 103_binary_tree_zigzag_level_order_traversal.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年04月26日 星期二 10时07分01秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {};
};

class Solution {
public:


	vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
		vector<vector<int> >ve;
		if (root == NULL)
			return ve;
		vector<int> temp;
		queue<TreeNode *> qu;
		qu.push(root);
		qu.push(new TreeNode(INT_MIN));
		int tag = 0;
		while (!qu.empty()) {
			TreeNode *head = qu.front();
			qu.pop();
			if (head == NULL) {

				continue;
			}
			if (head->val == INT_MIN) {
				if (!qu.empty()){
					qu.push(new TreeNode(INT_MIN));
					if (tag == 0) 
						ve.push_back(temp);
					else {
						vector<int> t;
						int size = temp.size();
						for (int i = 0; i < size; i++) {
							t.push_back(temp.back());
							temp.pop_back();
						}
						ve.push_back(t);
					}
						
					temp.clear();
					tag = 1-tag;
				}
				continue;
			}
			temp.push_back(head->val);

			qu.push(head->left);
			qu.push(head->right);

		}

		return ve;

	}
};

int main ()
