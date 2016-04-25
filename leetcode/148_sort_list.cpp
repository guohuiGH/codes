/*************************************************************************
    > File Name: 148_sort_list.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年04月21日 星期四 17时08分51秒
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

	ListNode* mergeSort(ListNode*node1, ListNode *node2) {
		ListNode *header = new ListNode(INT_MIN);
		ListNode *h = header;
		while(node1 != NULL && node2 != NULL) {
			if (node1->val < node2->val) {
				h->next = node1;
				node1 = node1->next;
			}else {
				h->next = node2;
				node2 = node2->next;
			}
			h = h->next;
		}
		if(node1 != NULL) {
			h->next = node1;
		}
		if(node2 != NULL) {
			h->next = node2;
		}
		return header->next;
	}

	ListNode* mergeSortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		if (head->next->next == NULL) {
			int minx = min(head->val, head->next->val);
			int maxx = max(head->val, head->next->val);
			head->val = minx;
			head->next->val = maxx;
			return head;
		}
		ListNode *pre = head;
		ListNode *mid = head;
		while(head != NULL && head->next != NULL) {
			mid = mid->next;
			head = head->next->next;
		}

		ListNode* t = mergeSortList(mid->next);
		mid->next = NULL;
		ListNode* h = mergeSortList(pre);
		return mergeSort(h, t);
	}

	ListNode* sortList(ListNode* head) {
		ListNode *tail = head;

		return mergeSortList(head);
	}
};

int main () {
	ListNode *l1 = new ListNode(1);

	ListNode *l2 = new ListNode(3);
	ListNode *l3 = new ListNode(2);
	l1->next = l2;
	l2->next = l3;
	Solution s;
	s.sortList(l1);
}
