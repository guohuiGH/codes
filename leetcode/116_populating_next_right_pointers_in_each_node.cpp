/*************************************************************************
    > File Name: 116_populating_next_right_pointers_in_each_node.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Thu 05 Nov 2015 03:45:04 PM CST
 ************************************************************************/

#include<iostream>
#include<limits.h>
#include<queue>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		TreeLinkNode *tag = NULL;
		if (!root)
			return;
		queue<TreeLinkNode *> qu;
		qu.push(root); qu.push(tag);
		TreeLinkNode *head = new TreeLinkNode(INT_MIN);
		int flag = 0
		while(!qu.empty()) {
			TreeLinkNode *t = qu.front();
			qu.pop();
			if (flag>1)
				break;
			if (!t) {
				flag++;
				head->next = NULL;
				head = new TreeLinkNode(INT_MIN);
				qu.push(tag);
			}else {
				flag = 0;
				head->next = t;
				head = head->next;
				if (t->left)
					qu.push(t->left);
				if (t->right)
					qu.push(t->right);
			}
		}

	}
};
