/*************************************************************************
    > File Name: 236_palindrome_linked_list.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sat 17 Oct 2015 03:03:15 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
	bool isPalindrome(ListNode * head) {
		ListNode *temp = head;
		if (!head)
			return true;
		stack<int> s;
		while(temp) {
			s.push(temp->val);
			temp = temp->next;
		}
		while(head) {
			if(head->val == s.top()) {
				head = head->next;
				s.pop();
			}
			else
				break;
		}
		return (s.empty());
	}
};

int main () {
	ListNode *t1 = new ListNode(1);
	ListNode *t2 = new ListNode(3);
	ListNode *t3 = new ListNode(1);
	t1->next = t2; t2->next = t3;
	Solution s;
	cout << s.isPalindrome(t1);
	return 0;
}
