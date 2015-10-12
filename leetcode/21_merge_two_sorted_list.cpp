/*************************************************************************
    > File Name: 21_merge_two_sorted_list.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Mon 05 Oct 2015 02:47:53 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
	ListNode * mergeTwoLists(ListNode *l1, ListNode * l2){
		if (l1== NULL )
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode * head = new ListNode(-1);
		ListNode *temp = head;

		while(l1!=NULL && l2!=NULL ) {
			

			if (l1->val < l2->val) {
				temp->val = l1->val;
				l1 = l1->next;
			}
			else {
				temp->val = l2->val;
				l2 = l2->next;
			}
			ListNode *t = new ListNode(-1);
			temp->next = t;
			temp = t;
		}
		
		while (l1!= NULL) {
			temp->val = l1->val;

			l1 = l1->next;
			if (l1 == NULL)
				break;
			ListNode *t = new ListNode(-1);
			temp->next = t;
			temp = t;

		}
		while(l2!= NULL) {
			temp->val = l2->val;
			
			l2 = l2->next;
			if (l2 == NULL)
				break;
			ListNode *t = new ListNode(-1);
			temp->next = t;
			temp = t;

		}
		return head;
		
	}
};

int main () {
	ListNode *l1 = new ListNode(2);
	ListNode *l2 = new ListNode(4);
	ListNode *l3 = new ListNode(1);
	ListNode *l4 = new ListNode(3);
	l1->next = l2;
	l3->next = l4;
	//l2->next = l3;
	Solution s;
	ListNode *l =   s.mergeTwoLists(l1, l3);
	while(l!=NULL) {
		cout << l->val;
		l = l->next;
	}
	
	return 0;
}
