/*************************************************************************
    > File Name: 147_insertion_sort_list.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年04月21日 星期四 20时38分13秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	ListNode* insertionSortList(ListNode *head) {
		if (head == NULL)
			return head;

		ListNode *header = new ListNode(INT_MIN);

		ListNode *current = head;
		ListNode *next = head;
		ListNode *father = header;
		ListNode *index = head;
		while (current != NULL) {
			next = current->next;
			while(index != NULL && current->val > index->val) {
				father = index;
				index = index->next;
			}

			current->next = index;
			father->next = current;

			father = header;
			index = header->next;
			current = next;

		}
		return header->next;
	
};

int main () {

}
