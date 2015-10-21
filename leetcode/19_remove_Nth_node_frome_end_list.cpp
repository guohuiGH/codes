/*************************************************************************
    > File Name: 19_remove_Nth_node_frome_end_list.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Wed 21 Oct 2015 08:53:33 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * removeNthFromEnd(ListNode *head, int n) {

		if (!head)
			return NULL;
		ListNode *new_head = new ListNode(0);
		new_head->next = head;	
		ListNode *p1 = new_head, *p2 = new_head;
		for(int i = 0; i < n; i++) {
			p1 = p1->next;
		}
		while(p1->next) {
			p1 = p1->next;
			p2 = p2->next;
		}
		p2->next = p2->next->next;
		
		return new_head->next;
	}
};

int main () {
	
	ListNode *t1 = new ListNode(1);
	ListNode *t2 = new ListNode(2);
	ListNode *t3 = new ListNode(3);
	ListNode *t4 = new ListNode(4);
	t1->next = t2; t2->next = t3; t3->next = t4;
	Solution s; s.removeNthFromEnd(t1, 1);
	while(t1) {
		cout << t1->val;
		t1 = t1->next;
	}
	

	return 1;
}
