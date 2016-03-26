/*************************************************************************
    > File Name: 24_swap_nodes_in_pairs.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月26日 星期六 15时49分55秒
 ************************************************************************/

#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){};
};
class Solution {
public:
	ListNode* swapPairs (ListNode* head) {
		if (head==NULL || head->next == NULL)
			return head;
		ListNode* p1 = head;
		ListNode* p2 = p1->next;
		while(true) {
			int temp = p1->val;
			p1->val = p2->val;
			p2->val = temp;
			p1 = p2->next;
			if (p1 == NULL || p1->next == NULL) {
				break;
			}
			p2 = p1->next;
		}
		return head;
	}
};

int main () {
	
}
