/*************************************************************************
    > File Name: 141_linked_list_cycle.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Wed 04 Nov 2015 11:17:55 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (!head)
			return false;
		ListNode *p1 = head;
		ListNode *p2 = head;

		while (true) {
			for (int i = 0; i < 2; i++) {
				p1 = p1->next;
				if (p1 == p2)
					return true;
				if (!p1)
					return NULL;
			}
			p2 = p2->next;
		}
		
	}
};

int main () {
	Solution s;
	ListNode *t1 = new ListNode(1);
	ListNode *t2 = new ListNode(2);
	ListNode *t3 = new ListNode(3);
	t1->next = t2; t2->next = t3; t3->next = t2;
	cout << s.hasCycle(t1);
	return 0;
}
