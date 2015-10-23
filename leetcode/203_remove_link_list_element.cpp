/*************************************************************************
    > File Name: 203_remove_link_list_element.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Fri 23 Oct 2015 10:42:00 AM CST
 ************************************************************************/

#include<iostream>
#include<limits.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * removeElements(ListNode *head, int val) {
		if (head == NULL)
			return NULL;
		ListNode *new_head = new ListNode(INT_MIN);
		new_head->next = head;
		ListNode *p = new_head;
		ListNode *q = head;
		
		while(q) {
			if (q->val == val) {
				p->next = q->next;
				q = q->next;
			}else {
				p = p->next;
				q = q->next;
			}
		}

		return new_head->next;
	}
};

int main () {
	Solution s;
	ListNode *t1 = new ListNode(1);
	ListNode *t2 = new ListNode(2);
	ListNode *t3 = new ListNode(3);
	t1->next = t2; t2->next = t3;
	ListNode *t =  s.removeElements(t1, 3);
	while(t) {
		cout << t->val << endl;
		t = t->next;
	}
	return 0;
}
