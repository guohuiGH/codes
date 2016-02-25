/*************************************************************************
> File Name: 328_odd_even_linked_list.cpp
> Author: guohui
> Mail: guohui1029@foxmail.com
> Created Time: 2016年02月21日 星期日 10时47分13秒
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
	ListNode *oddEvenList(ListNode* head) {
		if (head == NULL)
			return head;
		
		ListNode* p1 = head;
		ListNode* p2 = head;

		int i = 1;
		while (p1 && p1->next) {
			
			if (!(i % 2)) {
				ListNode *temp = p1->next;
				p1->next = temp->next;
				temp->next = p2->next;
				p2->next = temp;
				p2 = p2->next;
			}
			else
				p1 = p1->next;
			i++;
		}
		return head;
	}
};

int main() {

	cout << "hi";
	ListNode *t1 = new ListNode(1);
	ListNode *t2 = new ListNode(2);
	t1->next = t2;
	ListNode *t3 = new ListNode(3);
	t2->next = t3;

	Solution s;
	s.oddEvenList(t1);

	while (t1) {
		cout << t1->val;
		t1 = t1->next;
	}
	return 0;
}
