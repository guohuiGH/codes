/*************************************************************************
    > File Name: 109_convert_sorted_list_to_binary_tree.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年04月22日 星期五 11时52分59秒
 ************************************************************************/

#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:


	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL)
			return NULL;
		if (head->next == NULL)
			return new TreeNode(head->val);
		ListNode* mid = head;
		ListNode* pre = head;
		ListNode* pp = head;
		while (head!= NULL && head->next!=NULL) {
			pp = mid;
			mid = mid->next;
			head = head->next->next;
		}
		TreeNode* root = new TreeNode(mid->val);
		root->right = sortedListToBST(mid->next);
		pp->next = NULL;
		root->left = sortedListToBST(pre);
		return root;
	}
};

int main () {
	ListNode *t1 = new ListNode(1);
	ListNode *t2 = new ListNode(2);
	ListNode *t3 = new ListNode(3);
	t1->next = t2;
	t2->next = t3;
	Solution s;
	TreeNode *root = s.sortedListToBST(t1);

}
