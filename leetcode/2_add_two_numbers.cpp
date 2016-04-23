/*************************************************************************
    > File Name: 2_add_two_numbers.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年04月22日 星期五 16时30分42秒
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
	
	ListNode* getNode(int add, ListNode* t1, ListNode *t2) {
		int value = 0;
		value += add;
		if ((t1 == NULL || t1->next == NULL) && (t2 == NULL || t2->next == NULL)) {

			if (t1 == NULL)
				value += t2->val;
			else if (t2 == NULL)
				value += t1->val;
			else if (t1->next == NULL && t1->next == NULL)
				value += t1->val + t2->val;
			
			ListNode *current = new ListNode(value%10);
			if (value >= 10) {
				current->next = new ListNode(value/10);
			}
			return current;
		}
		else if (t1 == NULL) {

			value += t2->val;
			ListNode* current = new ListNode(value%10);
			current->next = getNode(value/10, t1,t2->next);
			return current;
		}else if (t2 == NULL) {
			value += t1->val;
			ListNode* current = new ListNode(value%10);
			current->next = getNode(value/10,t1->next,t2);
			return current;
		}else {
			value += t1->val + t2->val;
			ListNode* current = new ListNode(value%10);
			current->next = getNode(value/10,t1->next, t2->next);
			return current;
		}
			
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL)
			return NULL;
		ListNode* head = getNode(0, l1, l2);
		return head;

	}
};

int main () {

}
