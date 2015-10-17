/*************************************************************************
    > File Name: 160_intersection_of_two_link_list.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sat 17 Oct 2015 10:55:13 AM CST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
	ListNode *geIntersectioNode(ListNode *headA, ListNode*headB) {
		if (!headA||!headB)
			return NULL;
		ListNode *temp = headA;
		stack<int>sa, sb;
		while(temp) {
			sa.push(temp->val);
			temp = temp->next;
		}
		temp = headB;
		while(temp) {
			sb.push(temp->val);
			temp = temp->next;
		}
		int len = min(sa.size(), sb.size());
		int count = 0;
		for (int i = 0; i < len; i++) {
			if(sa.top() == sb.top()) {
				count++;
				sa.pop(); sb.pop();
			}else
				break;
		}
		temp = headA;
		//cout << count << " " << sa.size() << endl;
		int l = sa.size();
		for (int i = 0; i < l; i++) {
			temp = temp->next;
		}
		return temp;
	}
};
int main() {
	ListNode *t1 = new ListNode(1);

	ListNode *t2 = new ListNode(2);
	ListNode *t3 = new ListNode(3);
	ListNode *t4 = new ListNode(4);

	ListNode *t5 = new ListNode(5);
	ListNode *t6 = new ListNode(6);
	ListNode *t7 = new ListNode(7);
	ListNode *t8 = new ListNode(8);
	t1->next = t2; t2->next = t3; t3->next = t4; t4->next = t6;
	t5->next = t6; t6->next = t7;
	Solution s;
	ListNode *t =  s.geIntersectioNode(t1, t5);
	cout << t->val;
	return 0;
}
