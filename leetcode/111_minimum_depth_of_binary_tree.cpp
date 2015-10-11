/*************************************************************************
    > File Name: 111_minimum_depth_of_binary_tree.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sun 11 Oct 2015 02:32:01 PM CST
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL),right(NULL){}
};

class Solution {
public:
	int minDepth(TreeNode * root) {
		TreeNode *flag = NULL;
		queue<TreeNode *> qu;
		int height = 0;
		if (!root)
			return height;
		qu.push(root);
		qu.push(flag);
		while(!qu.empty()) {
			TreeNode *t = qu.front();
			qu.pop();
			if (!t) {
				qu.push(flag);
				height++;
			}else {
				if(t->left)
					qu.push(t->left);
				else
					return height+1;
				if (t->right)
					qu.push(t->right);
				else
					return height +1;
			}

		}
	}
};

int main () {

	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(1);
	TreeNode *t3 = new TreeNode(1);
	TreeNode *t4 = new TreeNode(1);
	TreeNode *t5 = new TreeNode(1);
	t1->left = t2;
	t1->right = t3;
	t2->right = t4;
	Solution s;
	cout << s.minDepth(t1);
	return 0;

}
