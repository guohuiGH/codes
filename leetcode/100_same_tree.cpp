/*************************************************************************
    > File Name: 100_same_tree.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Mon 21 Sep 2015 06:13:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	bool isSameTree(TreeNode *p, TreeNode *	q) {
		
		if (p == NULL && q == NULL)
			return true;
		//if (p->left !=NULL && p->right != NULL && q->left != NULL && q->right != NULL) {
				
		if (p!=NULL && q!=NULL &&p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
			return true;
			//}
		}
		//if (p->left == NULL && q->left == NULL && p->right == NULL && q->right == NULL) {
		//	if (p->val == q->val)
		//		return true;
		//}
		
		return false;
	}
};

int main() {
	TreeNode *t1, *t2, *t1l, *t2l;
	//t1 = new TreeNode(1);
	t1 = NULL;
	t1l = new TreeNode(2);
	//t1->val = 1;
	t2 = new TreeNode(1);
	t2l = new TreeNode(2);
	//t2->val = 1;
	Solution so;
	cout << so.isSameTree(t1, t2) << endl;
	return 0;
}
