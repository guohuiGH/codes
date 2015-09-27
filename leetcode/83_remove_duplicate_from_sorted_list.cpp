/*************************************************************************
    > File Name: 83_remove_duplicate_from_sorted_list.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sun 27 Sep 2015 06:23:31 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head){
		if(head == NULL || head->next == NULL)
			return head;
		else {
			if (head->val == head->next->val) {
				head->next = head->next->next;
				deleteDuplicates(head);
			}else {
				deleteDuplicates(head->next);
			}

		}
		return head;
	}
};

int main() {
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(1);
	//l1->next = l3;
	ListNode *l3 = new ListNode(3);
	l1->next = l3;
	ListNode *l4 = new ListNode(3);
	l3->next = l4;
	Solution s;
	s.deleteDuplicates(l1);
	while(l1!= NULL) {
		cout << l1->val;
		l1 = l1->next;
	}

	return 0;
}
