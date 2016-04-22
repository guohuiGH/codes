/*************************************************************************
    > File Name: 143_reorder_list.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年04月22日 星期五 14时57分00秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {

		if (head == NULL || head->next == NULL || head->next->next == NULL)
			return ;
		stack<ListNode*> st;
		ListNode *tail = head;
		while(tail->next != NULL) {
			st.push(tail);
			tail = tail->next;
		}
		while(head != NULL && head->next != NULL && head->next->next != NULL) {

			ListNode *tail = st.top();
			st.pop();
			ListNode *pre = st.top();

			tail->next = head->next;
			head->next = tail;
			pre->next = NULL;
			head = head->next->next;
		}
	}
};

int main () {

}
